/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaguez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 09:35:36 by jsaguez           #+#    #+#             */
/*   Updated: 2019/11/22 13:02:03 by jsaguez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#	ifndef GET_NEXT_LINE_H
#	define GET_NEXT_LINE_H

#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int	get_next_line(int const fd, char **line);

#	endif
