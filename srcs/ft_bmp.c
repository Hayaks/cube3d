#include "../includes/cub3d.h"

void	ft_size(char *str, int size)
{
	str[0] = (char)(size);
	str[1] = (char)(size >> 8);
	str[2] = (char)(size >> 16);
	str[3] = (char)(size >> 24);
}

void	ft_bmp(t_struct *info, bmp_param *bmp)
{
	if ((bmp->fd = open(BMP, O_CREAT | O_WRONLY, 0777)) < 0)
		ft_error(5, info);
	printf("wesh\n");
	ft_error(0, info);
}