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

#	ifndef CUB3D_H
# 	define CUB3D_H
#	define BUFFER_SIZE 32
#	define OPTIONS "RNSWEFC1"
#	define MAP "NSWE012"
#	define POS "NSWE"

#include <stdlib.h>
#include <stdio.h> //printf
#include <unistd.h> //close
#include <fcntl.h> //open
#include <mlx.h>
#include <math.h>
#include "../libft/libft.h"

typedef struct	mlx_struct
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
}				mlx_param;

typedef struct	text_struct
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
}				text_param;

typedef struct	s_struct
{
	int			x;
	int			y;
	char		*no;
	char		*so;
	char		*we;
	char		*ea;
	char		*s;
	char		**f;
	char		**c;
	char		*type;
	char		**map;
	int			i;
	int			len;
	mlx_param	*mlx;
	text_param	*text;
}				t_struct;

int		get_next_line(int const fd, char **line);
void	ft_parsing(char *line, t_struct *map);
void    ft_parsing_map(char *line, t_struct *map);

#endif
