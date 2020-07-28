#include "./includes/cub3d.h"

void    ft_verif_window(t_struct *info, t_mlx *mlx)
{
        int sizex;
        int sizey;

        mlx_get_screen_size(mlx->init, &sizex, &sizey);
        info->x = (info->x < (sizex/2)) ? (sizex/2) : info->x;
        info->y = (info->y < (sizey/2)) ? (sizey/2) : info->y;
        info->x = (info->x > sizex) ? sizex : info->x;
        info->y = (info->y > sizey) ? sizey : info->y;
}