/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaguez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 13:14:24 by jsaguez           #+#    #+#             */
/*   Updated: 2020/01/21 13:55:25 by jsaguez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# define BUFFER_SIZE 32
# define OPTIONS "RNSWEFC1"
# define MAP "NSWE012 "
# define POS "NSWE"
# define ARG ".cub"
# define SAVE "--save"
# define BMP "save.bmp"
# ifndef BONUS
#  define BONUS 0
# endif

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include "../mlx/mlx.h"
# include <math.h>
# include "../libft/libft.h"

typedef struct	s_s
{
	int			x;
	int			y;
	float		dist;
	int			*img;
}				t_s;

typedef struct	s_draw
{
	int		x;
	int		y;
	float	camerax;
	float	raydirx;
	float	raydiry;
	int		mapx;
	int		mapy;
	float	sidedistx;
	float	sidedisty;
	float	deltadistx;
	float	deltadisty;
	int		stepx;
	int		stepy;
	int		hit;
	int		side;
	float	perpwalldist;
	float	hauteurligne;
	int		start;
	int		end;
	int		*img;
	float	wallx;
	int		texx;
	int		texy;
	float	floorxwall;
	float	floorywall;
	float	weight;
	float	currentfloorx;
	float	currentfloory;
	int		floortextx;
	int		floortexty;
	float	currentdist;
}				t_draw;

typedef	struct	s_sp
{
	int		i;
	int		y;
	int		d;
	float	spritex;
	float	spritey;
	float	invdet;
	float	transformx;
	float	transformy;
	int		spritescreenx;
	int		spriteheight;
	int		spritewidth;
	int		drawstarty;
	int		drawendy;
	int		drawstartx;
	int		drawendx;
	int		texy;
	int		texx;
	int		*final;
}				t_sp;

typedef struct	s_mlx
{
	void		*init;
	void		*window;
	void		*img;
	float		posx;
	float		posy;
	float		dirx;
	float		diry;
	float		planex;
	float		planey;
	int			up;
	int			down;
	int			left;
	int			right;
	int			leftr;
	int			rightr;
	float		v;
	float		*perp;
}				t_mlx;

typedef struct	s_text
{
	int			*no;
	int			nox;
	int			noy;
	int			*so;
	int			sox;
	int			soy;
	int			*we;
	int			wex;
	int			wey;
	int			*ea;
	int			eax;
	int			eay;
	int			*s;
	int			sx;
	int			sy;
	int			*c;
	int			cx;
	int			cy;
	int			*f;
	int			fx;
	int			fy;
}				t_text;

typedef struct	s_struct
{
	int			x;
	int			y;
	char		*no;
	char		*so;
	char		*we;
	char		*ea;
	char		*s;
	char		*f;
	char		*c;
	char		**map;
	int			i;
	int			nb;
	int			ac;
	int			fd;
	t_mlx		*mlx;
	t_text		*text;
	t_s			**sprites;
	t_draw		*d;
	t_sp		*sp;
}				t_struct;

int				get_next_line(int const fd, char **line);
void			ft_parsing(char *line, t_struct *map);
void			ft_parsing_map(char *line, t_struct *map);
int				ft_update(t_struct *info);
void			ft_move(t_struct *info);
void			ft_draw(t_struct *info, t_mlx *mlx, t_draw *draw);
int				*ft_imgaddr(void *img);
int				ft_presskey(int key, t_struct *info);
int				ft_releasekey(int key, t_struct *info);
void			ft_sp(t_struct *info, t_mlx *m, t_s **s, t_sp *sp);
int				ft_error(int i, t_struct *info);
void			ft_vector(t_struct *info, t_mlx *mlx, t_draw *d);
int				*ft_tri(t_struct *info, int *final);
void			ft_newmap(t_struct *info);
void			ft_verif_map(t_struct *info);
void			ft_bmp(t_struct *info);
void			ft_set_texture(t_struct *info, t_text *text);
void			ft_verif_color(char **tab, t_struct *info);
void			ft_verif_window(t_struct *info, t_mlx *mlx);

#endif
