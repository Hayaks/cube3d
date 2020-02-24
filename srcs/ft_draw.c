#include "../includes/cub3d.h"

void    ft_transparent(int *img, int pixel)
{
    int i;

    i = 0;
    while (i < pixel)
    {
        if (img[i] == 0 && i <= (pixel / 2))
            img[i] = 12058111;
        if (img[i] == 0 && i > (pixel / 2))
            img[i] = 12895428;
        i++;
    }
    
}

void    ft_draw(t_struct *info, mlx_param *mlx)
{
    int     x;
    int     y;
    float   camerax;// position de la colonne par rapport au centre de l’écran
    float   rayposx;// position de départ du rayon sur X
    float   rayposy;// position de départ du rayon sur Y
    float   raydirx;// direction du rayon sur X
    float   raydiry;// direction du rayon sur Y
    // sur quelle case est la caméra
    int     mapx;
    int     mapy;
    // longueur du rayon
    float   sidedistx;
    float   sidedisty;
    // longueur du rayon entre chaque intersection
    float   deltadistx;
    float   deltadisty;
    // direction du vecteur sur X et Y (+1 ou -1)
    int     stepx;
    int     stepy;
    int     hit;//le rayon touche un mur ou pas
    int     side;//quelle orientation à le mur (nord/sud ou est/ouest) dans la map
    float   perpwalldist;//Distance corrigée du rayon
    float   hauteurligne;//La hauteur de la ligne a tracer
    int     drawstart;//Max haut de la colonne a tracer
    int     drawend;//Max bas de la colonne a tracer
    int     *img;
    float   wallx;// la colonne exacte touchée transposée sur X
    int     texx;// coordonnée x de la colonne dans la texture
    int     texy;
    //sol et plafond
    // positions X et Y du texel du sol au bas du mur
    float   floorxwall;
    float   floorywall;
    float   weight;
    float   currentfloorx;
    float   currentfloory;
    int     floortextx;
    int     floortexty;
    float   currentdist;

    x = 0;
    mlx->img = mlx_new_image(mlx->init, info->x, info->y);
    img = ft_imgaddr(mlx->img);
    while (x <= info->x)
    {
        y = 0;
        camerax = (2.0 * (float)x / (float)info->x) - 1.0;
        rayposx = mlx->posx;
        rayposy = mlx->posy;
        raydirx = mlx->dirx + mlx->planex * camerax;
        raydiry = mlx->diry + mlx->planey * camerax;
        mapx = (int)rayposx;
        mapy = (int)rayposy;
        deltadistx = fabs(1 / raydirx);
        deltadisty = fabs(1/ raydiry);
        hit = 0;
        side = 0;
        if (raydirx < 0)
        {
            stepx = -1;
            sidedistx = (rayposx - mapx) * deltadistx;
        }
        else
        {
            stepx = 1;
            sidedistx = (mapx + 1.0 - rayposx) * deltadistx;
        }
        if (raydiry < 0)
        {
            stepy = -1;
            sidedisty = (rayposy - mapy) * deltadisty;
        }
        else
        {
            stepy = 1;
            sidedisty = (mapy + 1.0 - rayposy) * deltadisty;
        }
        while (hit == 0)
        {
            if (sidedistx < sidedisty)
            {
                sidedistx += deltadistx;
                mapx += stepx;
                side = 0;
            }
            else
            {
                sidedisty += deltadisty;
                mapy += stepy;
                side = 1;
            }
            if (info->map[mapx][mapy] == '1')
                hit = 1;
        }
        if (side == 0)
        {
            perpwalldist = (float)fabs(((float)mapx - rayposx + (1.0 - (float)stepx) / 2.0) / raydirx);
            wallx = rayposy + ((mapx - rayposx + (1 - stepx) / 2) / raydirx) * raydiry;
        }
        else
        {
            perpwalldist = (float)fabs(((float)mapy - rayposy + (1.0 - (float)stepy) / 2.0) / raydiry);
            wallx = rayposx + ((mapy - rayposy + (1 - stepy) / 2) / raydiry) * raydirx;
        }
        wallx -= floor(wallx);
        texx = (int)(wallx * 64);
        if (side == 0 && raydirx > 0)
        {
            texx = 64 - texx - 1;
            floorxwall = mapx;
            floorywall = mapy + wallx;
        }
        else if (side == 0 && raydirx < 0)
        {
            floorxwall = mapx + 1.0;
            floorywall = mapy + wallx;
        }
        else if (side == 1 && raydiry < 0)
        {
            texx = 64 - texx - 1;
            floorxwall = mapx + wallx;
            floorywall = mapy + 1.0;
        }
        else if (side == 1 && raydiry > 0)
        {
            floorxwall = mapx + wallx;
            floorywall = mapy;
        }
        hauteurligne = (float)fabs((float)(info->y / perpwalldist));
        drawstart = (int)(-hauteurligne / 2 + info->y / 2);
        drawend = (int)(hauteurligne / 2 + info->y / 2);
        if (drawstart < 0)
            drawstart = 0;
        if (drawend >= info->y)
            drawend = info->y - 1;
        y = drawstart;
        while (y < drawend)
        {
            texy = (y * 2 - info->y + hauteurligne) * (64 / 2) / hauteurligne;
            if (side == 0 && raydirx < 0)
                img[x + info->x * y] = info->text->no[texx + texy * 64];
            else if (side == 0 && raydirx > 0)
                img[x + info->x * y] = info->text->so[texx + texy * 64];
            else if (side == 1 && raydiry < 0)
                img[x + info->x * y] = info->text->we[texx + texy * 64];
            else if (side == 1 && raydiry > 0)
                img[x + info->x * y] = info->text->ea[texx + texy * 64];
            y++;
        }
        while (y < info->y - 1)
        {
            currentdist = info->y / (2.0 * y - info->y);
            weight = currentdist / perpwalldist;
            currentfloorx = weight * floorxwall + (1.0 - weight) * rayposx;
            currentfloory = weight * floorywall + (1.0 - weight) * rayposy;
            floortextx = (int)(currentfloorx * 64) % 64;
            floortexty = (int)(currentfloory * 64) % 64;
            img[x + info->x * y] = info->text->f[floortextx + floortexty * 64];
            img[x + info->x * (info->y - y) - 1] = info->text->c[floortextx + floortexty * 64];
            y++;
        }
        mlx->perp[x] = perpwalldist;
        x++;
    }
    ft_transparent(img, (info->x * info->y));
    ft_sprite(info, info->mlx, info->sprites);
    mlx_put_image_to_window(mlx->init, mlx->window, mlx->img, 0, 0);
}