/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaguez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 10:06:53 by jsaguez           #+#    #+#             */
/*   Updated: 2019/11/22 09:22:21 by jsaguez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char *str, int type)
{
	size_t	i;

	i = 0;
	if (type == 1)
		while (str[i])
			i++;
	else
		 while (str[i] && str[i] != '\n')
			 i++;
	return (i);
}

char	*ft_realloc(char *s1, char *s2, int type)
{
	char	*tmp;
	size_t	i;
	size_t	j;

	if (!(tmp = malloc(sizeof(*tmp) * (ft_strlen(s1, 1) +
	((type == 1) ? ft_strlen(s2, 1) : ft_strlen(s2, 2)) + 10))))
		return (NULL);
	write(1, "wesh", 4);
	i = 0;
	j = 0;
	while (s1[i])
		tmp[j++] = s1[i++];
	i = 0;
	while (s2[i] && type == 1)
		tmp[j++] = s2[i++];
	while (s2[i] && s2[i] != '\n' && type == 2)
		tmp[j++] = s2[i++];
	free(s1);
	return (tmp);
}

int		ft_clean(char *s, int type)
{
	int		i;

	i = 0;
	while (s[i] && type == 1)
		s[i++] = 0;
	while (s[i] && s[i] != '\n' && type == 2)
		s[i++] = 0;
	return (i);
}

int		get_next_line(int const fd, char **line)
{
	char		tmp[BUFFER_SIZE + 1];
	int			i;
	static char	*save;
	static int	c;

	i = 0;
	if (!save)
		save = NULL;
	if (*save)
	{
		if (ft_strlen(&save[c], 1) == ft_strlen(&save[c], 2))
		{
			*line = ft_realloc(*line, &save[c], 1);
			c = ft_clean(save, 1);
			c = 0;
		}
		else
		{
			*line = ft_realloc(*line, &save[c], 2);
			c = ft_clean(&save[c], 2);
			return (1);
		}
	}
	while (read(fd, tmp, BUFFER_SIZE))
	{
		tmp[BUFFER_SIZE] = 0;
		if (ft_strlen(tmp, 1) == ft_strlen(tmp, 2))
		{
			*line = ft_realloc(*line, tmp, 1);
		}
		else
		{
			*line = ft_realloc(*line, tmp, 2);
			i = ft_clean(tmp, 2);
			save = ft_realloc(save, &tmp[ft_strlen(tmp, 2)], 1);
		}
	}
	if (fd < -1)
		return (-1);
	return (1);
}