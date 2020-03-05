#include "../includes/cub3d.h"

void    ft_set_texture(t_struct *info, text_param *text)
{
	void	*tmp;

	if (!(tmp = mlx_xpm_file_to_image(info->mlx->init, info->no, &text->nox, &text->noy)))
		ft_error(3, info);
	text->no = ft_imgaddr(tmp);
	if (!(tmp = mlx_xpm_file_to_image(info->mlx->init, info->so, &text->sox, &text->soy)))
		ft_error(3, info);
	text->so = ft_imgaddr(tmp);
	if (!(tmp = mlx_xpm_file_to_image(info->mlx->init, info->we, &text->wex, &text->wey)))
		ft_error(3, info);
	text->we = ft_imgaddr(tmp);
	if (!(tmp = mlx_xpm_file_to_image(info->mlx->init, info->ea, &text->eax, &text->eay)))
		ft_error(3, info);
	text->ea = ft_imgaddr(tmp);
	if (!(tmp = mlx_xpm_file_to_image(info->mlx->init, info->s, &text->sx, &text->sy)))
		ft_error(3, info);
	text->s = ft_imgaddr(tmp);
	if (BONUS == 1)
	{
		if (!(tmp = mlx_xpm_file_to_image(info->mlx->init, info->c, &text->cx, &text->cy)))
			ft_error(3, info);
		text->c = ft_imgaddr(tmp);
		if (!(tmp = mlx_xpm_file_to_image(info->mlx->init, info->f, &text->fx, &text->fy)))
			ft_error(3, info);
		text->f = ft_imgaddr(tmp);
	}
}