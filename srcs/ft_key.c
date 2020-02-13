#include "../includes/cub3d.h"

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
    if (key == 257)
        mlx->v = 0.2;
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
    if (key == 257)
        mlx->v = 0.05;
    return (1);
}