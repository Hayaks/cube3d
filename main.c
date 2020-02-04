#include "./includes/cub3d.h"

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
        //deltadistx = (float)sqrt(1 + (raydiry * raydiry) / (rayposx * rayposx));
        //deltadisty = (float)sqrt(1 + (raydirx * raydirx) / (rayposy * rayposy));
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
            perpwalldist = (float)fabs(((float)mapx - rayposx + (1.0 - (float)stepx) / 2.0) / raydirx);
        else
            perpwalldist = (float)fabs(((float)mapy - rayposy + (1.0 - (float)stepy) / 2.0) / raydiry);
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
            img[x + info->x * y] = 12481831;
            y++;
        }
        x++;
    }
    ft_transparent(img, (info->x * info->y));
    mlx_put_image_to_window(info->mlx->init, info->mlx->window, info->mlx->img, 0, 0);
}
//////////////////////////////////////////////////
void    ft_move(t_struct *info)
{
    float v;

    v = 0.05;
    if (info->map[(int)(info->mlx->posx + info->mlx->dirx * v)][(int)info->mlx->posy]
    != '1' && info->mlx->up == 1)
        info->mlx->posx += info->mlx->dirx * v;
    if (info->map[(int)info->mlx->posx][(int)(info->mlx->posy + info->mlx->diry * v)]
    != '1' && info->mlx->up == 1)
        info->mlx->posy += info->mlx->diry * v;

    if (info->map[(int)(info->mlx->posx - info->mlx->dirx * v)][(int)info->mlx->posy]
    != '1' && info->mlx->down == 1)
        info->mlx->posx -= info->mlx->dirx * v;
    if (info->map[(int)info->mlx->posx][(int)(info->mlx->posy - info->mlx->diry * v)]
    != '1' && info->mlx->down == 1)
        info->mlx->posy -= info->mlx->diry * v;

    if (info->map[(int)(info->mlx->posx + info->mlx->planex * v)][(int)info->mlx->posy]
    != '1' && info->mlx->up == 1)
        info->mlx->posx += info->mlx->planex * v;
    if (info->map[(int)info->mlx->posx][(int)(info->mlx->posy + info->mlx->planey * v)]
    != '1' && info->mlx->up == 1)
        info->mlx->posy += info->mlx->planey * v;

    if (info->map[(int)(info->mlx->posx - info->mlx->planex * v)][(int)info->mlx->posy]
    != '1' && info->mlx->down == 1)
        info->mlx->posx -= info->mlx->planex * v;
    if (info->map[(int)info->mlx->posx][(int)(info->mlx->posy - info->mlx->planey * v)]
    != '1' && info->mlx->down == 1)
        info->mlx->posy -= info->mlx->planey * v;
}
//////////////////////////////////////////////////

int    ft_update(t_struct *info)
{
    ft_move(info);
    mlx_destroy_image(info->mlx->init, info->mlx->img);
    ft_draw(info);
    printf("up: %d\n", info->mlx->up);
    return (0);
}
int     ft_presskey(t_struct *info, int key)
{
    if (key == 13)
        info->mlx->up = 1;
    if (key == 1)
        info->mlx->down = 1;
    if (key == 0)
        info->mlx->left = 1;
    if (key == 2)
        info->mlx->right = 1;
    if (key == 123)
        info->mlx->leftr = 1;
    if (key == 124)
        info->mlx->rightr = 1;
    return (1);
}

int     ft_releasekey(t_struct *info, int key)
{
    if (key == 13)
        info->mlx->up = 0;
    if (key == 1)
        info->mlx->down = 0;
    if (key == 0)
        info->mlx->left = 0;
    if (key == 2)
        info->mlx->right = 0;
    if (key == 123)
        info->mlx->leftr = 0;
    if (key == 124)
        info->mlx->rightr = 0;
    return (1);
}

void    ft_mlx(t_struct *info)
{
    info->mlx->init = mlx_init();
    info->mlx->window = mlx_new_window(info->mlx->init, info->x, info->y, "wesh");
    ft_draw(info);
    //mlx_hook(info->mlx->window, KEYPRESS, KEYPRESSMASK, &ft_presskey, info);
	//mlx_hook(info->mlx->window, KEYRELEASE, KEYRELEASEMASK, &ft_releasekey, info);
    mlx_loop_hook(info->mlx->init, &ft_update, info);
    mlx_loop(info->mlx->init);
}

int	main(int ac, char **av)
{
	int         fd;
    int         ret;
    char        *line;
    t_struct    *info;

    if (!(info = malloc(sizeof(*info))) && ac != 2)
        return (-1);
    else
    {
        if (!(info->mlx = malloc(sizeof(mlx_param))))
            return (-1);
        ft_newmap(info);
        fd = open(av[1], O_RDONLY);
        ft_map(ret, fd, line, info);
        close(fd);
    }
    ft_mlx(info);
    printf("r1: %d\n", info->x);
    printf("r2: %d\n", info->y);
    printf("no: %s\n", info->no);
    printf("so: %s\n", info->so);
    printf("we: %s\n", info->we);
    printf("ea: %s\n", info->ea);
    printf("s: %s\n", info->s);
    printf("f1: %s\n", info->f[0]);
    printf("f2: %s\n", info->f[1]);
    printf("f3: %s\n", info->f[2]);
    printf("c1: %s\n", info->c[0]);
    printf("c2: %s\n", info->c[1]);
    printf("c3: %s\n", info->c[2]);
    printf("%s\n", info->map[0]);
    printf("%s\n", info->map[1]);
    printf("%s\n", info->map[2]);
    printf("%s\n", info->map[3]);
    printf("%s\n", info->map[4]);
    printf("%s\n", info->map[5]);
    printf("%s\n", info->map[6]);
    printf("i: %d\n", info->i);
    printf("len: %d\n", info->len);
    printf("posx: %f\n", info->mlx->posx);
    printf("posy: %f\n", info->mlx->posy);
    printf("dirx: %f\n", info->mlx->dirx);
    printf("diry: %f\n", info->mlx->diry);
    printf("planex: %f\n", info->mlx->planex);
    printf("planey: %f\n", info->mlx->planey);
}