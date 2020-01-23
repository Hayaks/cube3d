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

#include <stdlib.h>
#include <stdio.h> //printf
#include <unistd.h> //close
#include <fcntl.h> //open

typedef struct	s_struct
{
	char		**r;
	char		*no;
	char		*so;
	char		*we;
	char		*ea;
	char		*s;
	char		**f;
	char		**c;
}				t_struct;

int		get_next_line(int const fd, char **line);

#endif
