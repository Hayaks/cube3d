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

void    ft_init_draw(t_struct *info, mlx_param *mlx, draw_param *d)
{
    d->y = 0;
    d->camerax = (2.0 * (float)d->x / (float)info->x) - 1.0;
    d->raydirx = mlx->dirx + mlx->planex * d->camerax;
    d->raydiry = mlx->diry + mlx->planey * d->camerax;
    d->mapx = (int)mlx->posx;
    d->mapy = (int)mlx->posy;
    d->deltadistx = fabs(1 / d->raydirx);
    d->deltadisty = fabs(1 / d->raydiry);
    d->hit = 0;
    d->side = 0;
}

void    ft_vector(mlx_param *mlx, draw_param *d)
{
    if (d->raydirx < 0)
    {
        d->stepx = -1;
        d->sidedistx = (mlx->posx - d->mapx) * d->deltadistx;
    }
    else
    {
        d->stepx = 1;
        d->sidedistx = (d->mapx + 1.0 - mlx->posx) * d->deltadistx;
    }
    if (d->raydiry < 0)
    {
        d->stepy = -1;
        d->sidedisty = (mlx->posy - d->mapy) * d->deltadisty;
    }
    else
    {
        d->stepy = 1;
        d->sidedisty = (d->mapy + 1.0 - mlx->posy) * d->deltadisty;
    }
}

void    ft_hit(t_struct *info, draw_param *d)
{
    while (d->hit == 0)
    {
        if (d->sidedistx < d->sidedisty)
        {
            d->sidedistx += d->deltadistx;
            d->mapx += d->stepx;
            d->side = 0;
        }
        else
        {
            d->sidedisty += d->deltadisty;
            d->mapy += d->stepy;
            d->side = 1;
        }
        if (info->map[d->mapx][d->mapy] == '1')
            d->hit = 1;
        }
}

void    ft_perp(mlx_param *mlx, draw_param *d)
{
    if (d->side == 0)
    {
        d->perpwalldist = (float)fabs(((float)d->mapx - mlx->posx + (1.0 - (float)d->stepx) / 2.0) / d->raydirx);
        d->wallx = mlx->posy + ((d->mapx - mlx->posx + (1 - d->stepx) / 2) / d->raydirx) * d->raydiry;
    }
    else
    {
        d->perpwalldist = (float)fabs(((float)d->mapy - mlx->posy + (1.0 - (float)d->stepy) / 2.0) / d->raydiry);
        d->wallx = mlx->posx + ((d->mapy - mlx->posy + (1 - d->stepy) / 2) / d->raydiry) * d->raydirx;
    }
    d->wallx -= floor(d->wallx);
}

void    ft_texx(draw_param *d)
{
    d->texx = (int)(d->wallx * 64);
    if (d->side == 0 && d->raydirx > 0)
    {
        d->texx = 64 - d->texx - 1;
        d->floorxwall = d->mapx;
        d->floorywall = d->mapy + d->wallx;
    }
    else if (d->side == 0 && d->raydirx < 0)
    {
        d->floorxwall = d->mapx + 1.0;
        d->floorywall = d->mapy + d->wallx;
    }
    else if (d->side == 1 && d->raydiry < 0)
    {
        d->texx = 64 - d->texx - 1;
        d->floorxwall = d->mapx + d->wallx;
        d->floorywall = d->mapy + 1.0;
    }
    else if (d->side == 1 && d->raydiry > 0)
    {
        d->floorxwall = d->mapx + d->wallx;
        d->floorywall = d->mapy;
    }
}

void    ft_hauteur(t_struct *info, draw_param *d)
{
    d->hauteurligne = (float)fabs((float)(info->y / d->perpwalldist));
    d->start = (int)(-d->hauteurligne / 2 + info->y / 2);
    d->end = (int)(d->hauteurligne / 2 + info->y / 2);
    if (d->start < 0)
        d->start = 0;
    if (d->end >= info->y)
        d->end = info->y - 1;
    d->y = d->start;
}

void    ft_wall(t_struct *info, draw_param *d)
{
    while (d->y <= d->end)
    {
        d->texy = (d->y * 2 - info->y + d->hauteurligne) * (64 / 2) / d->hauteurligne;
        if (d->side == 0 && d->raydirx < 0)
            d->img[d->x + info->x * d->y] = info->text->no[d->texx + d->texy * 64];
        else if (d->side == 0 && d->raydirx > 0)
            d->img[d->x + info->x * d->y] = info->text->so[d->texx + d->texy * 64];
        else if (d->side == 1 && d->raydiry < 0)
            d->img[d->x + info->x * d->y] = info->text->we[d->texx + d->texy * 64];
        else if (d->side == 1 && d->raydiry > 0)
            d->img[d->x + info->x * d->y] = info->text->ea[d->texx + d->texy * 64];
        d->y++;
    }
}

void    ft_floor(t_struct *info, mlx_param *mlx, draw_param *d)
{
    while (d->y < info->y - 1)
    {
        d->currentdist = info->y / (2.0 * d->y - info->y);
        d->weight = d->currentdist / d->perpwalldist;
        d->currentfloorx = d->weight * d->floorxwall + (1.0 - d->weight) * mlx->posx;
        d->currentfloory = d->weight * d->floorywall + (1.0 - d->weight) * mlx->posy;
        d->floortextx = (int)(d->currentfloorx * 64) % 64;
        d->floortexty = (int)(d->currentfloory * 64) % 64;
        d->img[d->x + info->x * d->y] = info->text->f[d->floortextx + d->floortexty * 64];
        d->img[d->x + info->x * (info->y - d->y)] = info->text->c[d->floortextx + d->floortexty * 64];
        d->y++;
    }
}

void    ft_draw(t_struct *info, mlx_param *mlx, draw_param *d)
{
    d->x = 0;
    mlx->img = mlx_new_image(mlx->init, info->x, info->y);
    d->img = ft_imgaddr(mlx->img);
    while (d->x <= info->x)
    {
        ft_init_draw(info, mlx, d);
        ft_vector(mlx, d);
        ft_hit(info, d);
        ft_perp(mlx, d);
        ft_texx(d);
        ft_hauteur(info, d);
        ft_wall(info, d);
        ft_floor(info, mlx, d);
        mlx->perp[d->x] = d->perpwalldist;
        d->x++;
    }
    ft_transparent(d->img, (info->x * info->y));
    ft_sprite(info, info->mlx, info->sprites);
    mlx_put_image_to_window(mlx->init, mlx->window, mlx->img, 0, 0);
}