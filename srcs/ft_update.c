#include "../includes/cub3d.h"

void    ft_move(t_struct *info, mlx_param *mlx)
{
    float   v;

    v = mlx->v;
    if (info->map[(int)(mlx->posx + mlx->dirx * 0.5)][(int)mlx->posy]
    != '1' && info->map[(int)(mlx->posx + mlx->dirx * 0.5)][(int)mlx->posy]
    != '2' && mlx->up == 1)
        mlx->posx += mlx->dirx * v;
    if (info->map[(int)mlx->posx][(int)(mlx->posy + mlx->diry * 0.5)]
    != '1' && info->map[(int)mlx->posx][(int)(mlx->posy + mlx->diry * 0.5)]
    != '2' && mlx->up == 1)
        mlx->posy += mlx->diry * v;

    if (info->map[(int)(mlx->posx - mlx->dirx * 0.5)][(int)mlx->posy]
    != '1' && info->map[(int)(mlx->posx - mlx->dirx * 0.5)][(int)mlx->posy]
    != '2' &&  mlx->down == 1)
        mlx->posx -= mlx->dirx * v;
    if (info->map[(int)mlx->posx][(int)(mlx->posy - mlx->diry * 0.5)]
    != '1' && info->map[(int)mlx->posx][(int)(mlx->posy - mlx->diry * 0.5)]
    != '2' && mlx->down == 1)
        mlx->posy -= mlx->diry * v;

    if (info->map[(int)(mlx->posx + mlx->planex * 0.5)][(int)mlx->posy]
    != '1' && info->map[(int)(mlx->posx + mlx->planex * 0.5)][(int)mlx->posy]
    != '2' && mlx->right == 1)
        mlx->posx += mlx->planex * v;
    if (info->map[(int)mlx->posx][(int)(mlx->posy + mlx->planey * 0.5)]
    != '1' && info->map[(int)mlx->posx][(int)(mlx->posy + mlx->planey * 0.5)]
    != '2' && mlx->right == 1)
        mlx->posy += mlx->planey * v;

    if (info->map[(int)(mlx->posx - mlx->planex * 0.5)][(int)mlx->posy]
    != '1' && info->map[(int)(mlx->posx - mlx->planex * 0.5)][(int)mlx->posy]
    != '2' && mlx->left == 1)
        mlx->posx -= mlx->planex * v;
    if (info->map[(int)mlx->posx][(int)(mlx->posy - mlx->planey * 0.5)]
    != '1' && info->map[(int)mlx->posx][(int)(mlx->posy - mlx->planey * 0.5)]
    != '2' && mlx->left == 1)
        mlx->posy -= mlx->planey * v;
}

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

int    ft_update(t_struct *info)
{
    ft_move(info, info->mlx);
    ft_rotate(info->mlx);
    mlx_destroy_image(info->mlx->init, info->mlx->img);
    ft_draw(info);
    ft_sprite(info);
    return (0);
}