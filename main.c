#include "./includes/cub3d.h"
#include "./includes/key.h"

void    ft_newmap(t_struct *info)
{
    info->x = 0;
    info->y = 0;
    info->no = NULL;
    info->so = NULL;
    info->we = NULL;
    info->ea = NULL;
    info->s = NULL;
    info->f = NULL;
    info->c = NULL;
    info->map = NULL;
    info->i = 0;
    info->len = 0;
    info->mlx->posx = 0;
    info->mlx->posy = 0;
    info->mlx->dirx = 0;
    info->mlx->diry = 0;
    info->mlx->planex = 0;
    info->mlx->planey = 0;
    info->mlx->up = 0;
    info->mlx->down = 0;
    info->mlx->left = 0;
    info->mlx->right = 0;
    info->mlx->leftr = 0;
    info->mlx->rightr = 0;
    info->text->no = NULL;
    info->text->nox = 0;
    info->text->noy = 0;
    info->text->so = NULL;
    info->text->sox = 0;
    info->text->soy = 0;
    info->text->we = NULL;
    info->text->wex = 0;
    info->text->wey = 0;
    info->text->ea = NULL;
    info->text->eax = 0;
    info->text->eay = 0;
}

void    ft_map(int ret, int fd, char *line, t_struct *info)
{
    int i;

    i = 0;
    while ((ret = get_next_line(fd, &line)) > 0)
    {
        ft_parsing(line, info);
        free(line);
    }
    if (ret == 0)
    {
        ft_parsing(line, info);
        free(line);
    }
    while (info->map[0][i])
    {
        if (info->map[0][i] != '1' ||
        info->map[info->i - 1][i] != '1')
            exit(0);
        i++;
    }
}

int     *ft_imgaddr(void *img) 
{
    int lgthbytes;
    int sizeline;
    int endian;
    int *stockimg;

    lgthbytes = sizeof(int);
    stockimg = (int*)mlx_get_data_addr(img, &lgthbytes, &sizeline, &endian);
    return (stockimg);
}

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

void    ft_draw(t_struct *info)
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

    x = 0;
    y = 0;
    info->mlx->img = mlx_new_image(info->mlx->init, info->x, info->y);
    img = ft_imgaddr(info->mlx->img);
    while (x <= info->x)
    {
        camerax = (2.0 * (float)x / (float)info->x) - 1.0;
        rayposx = info->mlx->posx;
        rayposy = info->mlx->posy;
        raydirx = info->mlx->dirx + info->mlx->planex * camerax;
        raydiry = info->mlx->diry + info->mlx->planey * camerax;
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
            texx = 64 - texx - 1;
        if (side == 1 && raydiry < 0)
            texx = 64 - texx - 1;
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
            if (texy < 0)
            texy -= texy;
            if (side == 0 && raydirx < 0)
                img[x + info->x * y] = info->text->no[texx + texy * 64];
            else if (side == 0 && raydirx > 0)
                img[x + info->x * y] = info->text->so[texx + texy * 64];
            else if (side == 1 && raydiry < 0)
                img[x + info->x * y] = info->text->we[texx + texy * 64];
            else if (side == 1 && raydiry > 0)
                img[x + info->x * y] = info->text->ea[texx + texy * 64];
            //img[x + info->x * y] = 12481831;
            y++;
        }
        x++;
    }
    ft_transparent(img, (info->x * info->y));
    mlx_put_image_to_window(info->mlx->init, info->mlx->window, info->mlx->img, 0, 0);
}
//////////////////////////////////////////////////
void    ft_move(t_struct *info, mlx_param *mlx)
{
    float   v;

    v = 0.05;
    if (info->map[(int)(mlx->posx + mlx->dirx * 0.5)][(int)mlx->posy]
    != '1' && mlx->up == 1)
        mlx->posx += mlx->dirx * v;
    if (info->map[(int)mlx->posx][(int)(mlx->posy + mlx->diry * 0.5)]
    != '1' && mlx->up == 1)
        mlx->posy += mlx->diry * v;

    if (info->map[(int)(mlx->posx - mlx->dirx * 0.5)][(int)mlx->posy]
    != '1' && mlx->down == 1)
        mlx->posx -= mlx->dirx * v;
    if (info->map[(int)mlx->posx][(int)(mlx->posy - mlx->diry * 0.5)]
    != '1' && mlx->down == 1)
        mlx->posy -= mlx->diry * v;

    if (info->map[(int)(mlx->posx + mlx->planex * 0.5)][(int)mlx->posy]
    != '1' && mlx->right == 1)
        mlx->posx += mlx->planex * v;
    if (info->map[(int)mlx->posx][(int)(mlx->posy + mlx->planey * 0.5)]
    != '1' && mlx->right == 1)
        mlx->posy += mlx->planey * v;

    if (info->map[(int)(mlx->posx - mlx->planex * 0.5)][(int)mlx->posy]
    != '1' && mlx->left == 1)
        mlx->posx -= mlx->planex * v;
    if (info->map[(int)mlx->posx][(int)(mlx->posy - mlx->planey * 0.5)]
    != '1' && mlx->left == 1)
        mlx->posy -= mlx->planey * v;
}
//////////////////////////////////////////////////
void    ft_rotate(mlx_param *mlx)
{
    float   v;
    float   tempdirx;
    float   tempplanex;

    v = 0.05;
    if (mlx->rightr == 1)
    {
        tempdirx = mlx->dirx;
        mlx->dirx = mlx->dirx * cos(-v) - mlx->diry * sin(-v);
        mlx->diry = tempdirx * sin(-v) + mlx->diry * cos(-v);
        tempplanex = mlx->planex;
        mlx->planex = mlx->planex * cos(-v) - mlx->planey * sin(-v);
        mlx->planey = tempplanex * sin(-v) + mlx->planey * cos(-v);
    }
    if (mlx->leftr == 1)
    {
        tempdirx = mlx->dirx;
        mlx->dirx = mlx->dirx * cos(v) - mlx->diry * sin(v);
        mlx->diry = tempdirx * sin(v) + mlx->diry * cos(v);
        tempplanex = mlx->planex;
        mlx->planex = mlx->planex * cos(v) - mlx->planey * sin(v);
        mlx->planey = tempplanex * sin(v) + mlx->planey * cos(v);
    }
}
//////////////////////////////////////////////////
int    ft_update(t_struct *info)
{
    ft_move(info, info->mlx);
    ft_rotate(info->mlx);
    mlx_destroy_image(info->mlx->init, info->mlx->img);
    ft_draw(info);
    return (0);
}
int     ft_presskey(int key, mlx_param *mlx)
{
    if (key == 13)
        mlx->up = 1;
    if (key == 1)
        mlx->down = 1;
    if (key == 0)
        mlx->left = 1;
    if (key == 2)
        mlx->right = 1;
    if (key == 123)
        mlx->leftr = 1;
    if (key == 124)
        mlx->rightr = 1;
    return (1);
}

int     ft_releasekey(int key, mlx_param *mlx)
{
    if (key == 13)
        mlx->up = 0;
    if (key == 1)
        mlx->down = 0;
    if (key == 0)
        mlx->left = 0;
    if (key == 2)
        mlx->right = 0;
    if (key == 123)
        mlx->leftr = 0;
    if (key == 124)
        mlx->rightr = 0;
    return (1);
}

void    ft_set_texture(t_struct *info, text_param *text)
{
    info->text->no = ft_imgaddr(mlx_xpm_file_to_image(info->mlx->init, info->no, &text->nox, &text->noy));
    info->text->so = ft_imgaddr(mlx_xpm_file_to_image(info->mlx->init, info->so, &text->sox, &text->soy));
    info->text->we = ft_imgaddr(mlx_xpm_file_to_image(info->mlx->init, info->we, &text->wex, &text->wey));
    info->text->ea = ft_imgaddr(mlx_xpm_file_to_image(info->mlx->init, info->ea, &text->eax, &text->eay));
}
void    ft_mlx(t_struct *info)
{
    info->mlx->init = mlx_init();
    info->mlx->window = mlx_new_window(info->mlx->init, info->x, info->y, "wesh");
    ft_set_texture(info, info->text);
    ft_draw(info);
    mlx_hook(info->mlx->window, KEYPRESS, KEYPRESSMASK, &ft_presskey, info->mlx);
	mlx_hook(info->mlx->window, KEYRELEASE, KEYRELEASEMASK, &ft_releasekey, info->mlx);
    mlx_loop_hook(info->mlx->init, &ft_update, info);
    mlx_loop(info->mlx->init);
}

int	main(int ac, char **av)
{
	int         fd;
    int         ret;
    char        *line;
    t_struct    *info;

    if (!(info = malloc(sizeof(t_struct))) && ac != 2)
        return (-1);
    else
    {
        if (!(info->mlx = malloc(sizeof(mlx_param))))
            return (-1);
        if (!(info->text = malloc(sizeof(text_param))))
            return (-1);
        ft_newmap(info);
        fd = open(av[1], O_RDONLY);
        ft_map(ret, fd, line, info);
        close(fd);
    }
    ft_mlx(info);
}