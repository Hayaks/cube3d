#include "../includes/cub3d.h"

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