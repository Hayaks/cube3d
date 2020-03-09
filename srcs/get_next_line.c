/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaguez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/25 12:56:45 by jsaguez           #+#    #+#             */
/*   Updated: 2020/03/09 14:16:56 by jsaguez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../includes/cub3d.h"

char	*ft_save(char *save, int i)
{
	char	*tmp;

	if (save[i])
	{
		tmp = ft_strdup(save + i + 1);
		free(save);
		save = tmp;
	}
	else
	{
		free(save);
		save = NULL;
	}
	return (save);
}

int		ft_exit(int c, char **buffer, char **save)
{
	if (c >= 0)
	{
		if (*buffer)
			free(*buffer);
		if (c == 0 && *save)
			free(*save);
	}
	if (c == -1)
		if (!*buffer)
			free(*buffer);
	return (c);
}

int		ft_return(int c, char *buffer, char *save)
{
	if (c || save)
		return (ft_exit(1, &buffer, &save));
	return (ft_exit(0, &buffer, &save));
}

int		get_next_line(int fd, char **line)
{
	static char	*save;
	char		*buffer;
	char		*tmp;
	int			i;
	int			c;

	i = 0;
	buffer = NULL;
	if (fd < 0 || !line || BUFFER_SIZE <= 0 ||
	!(buffer = ft_calloc(sizeof(*buffer), (BUFFER_SIZE + 1))))
		return (ft_exit(-1, &buffer, &save));
	if (!save)
		save = ft_calloc(sizeof(*save), 1);
	while (!ft_strchr(buffer, '\n') && (c = read(fd, buffer, BUFFER_SIZE)))
	{
		if (c < 0)
			return (ft_exit(-1, &buffer, &save));
		buffer[c] = '\0';
		tmp = ft_strjoin(save, buffer);
		free(save);
		save = tmp;
	}
	while (save[i] && save[i] != '\n')
		i++;
	*line = ft_substr(save, 0, i);
	save = ft_save(save, i);
	return (ft_return(c, buffer, save));
}
