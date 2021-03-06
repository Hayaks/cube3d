/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaguez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/25 12:56:22 by jsaguez           #+#    #+#             */
/*   Updated: 2020/08/17 12:15:12 by jsaguez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/cub3d.h"

void	ft_verif(char *line, t_struct *info, int i)
{
	if (!(ft_strchr(OPTIONS, line[i])))
		ft_error(3, info);
	if ((line[i] == 'R' && info->x != 0) ||
	(line[i] == 'N' && line[i + 1] == 'O' && info->no != NULL) ||
	(line[i] == 'S' && line[i + 1] == 'O' && info->so != NULL) ||
	(line[i] == 'W' && line[i + 1] == 'E' && info->we != NULL) ||
	(line[i] == 'E' && line[i + 1] == 'A' && info->ea != NULL) ||
	(line[i] == 'S' && line[i + 1] == ' ' && info->s != NULL) ||
	(line[i] == 'F' && info->f != NULL) ||
	(line[i] == 'C' && info->c != NULL))
		ft_error(3, info);
	if (line[i] == '1' && (info->x == 0 || info->no == NULL ||
	info->so == NULL || info->we == NULL || info->ea == NULL ||
	info->s == NULL || info->f == NULL || info->c == NULL))
		ft_error(3, info);
}

void	ft_resolution(char *line, t_struct *info, int i)
{
	char	**temp;
	int		j;

	j = 0;
	temp = ft_split(&line[i + 1], ' ');
	while (temp[j])
		j++;
	if (j != 2)
		ft_error(3, info);
	info->x = ft_atoi(temp[0]);
	info->y = ft_atoi(temp[1]);
	if ((info->x % 2) == 1)
		info->x++;
	if ((info->y % 2) == 1)
		info->y++;
	free(temp[0]);
	free(temp[1]);
	free(temp);
}

void	ft_color(char *line, t_struct *info, int i, int type)
{
	char	*temp;
	char	**tab;
	int		j;
	int		result;

	j = 0;
	result = 0;
	while (line[i] == ' ')
		i++;
	temp = ft_strdup(&line[i]);
	tab = ft_split(temp, ',');
	while (tab[j])
		j++;
	if (j != 3)
		ft_error(3, info);
	ft_verif_color(tab, info, result, type);
	free(temp);
	free(tab[2]);
	free(tab[1]);
	free(tab[0]);
	free(tab);
}

void	ft_options(char *line, t_struct *info, int i)
{
	if (line[i] == 'R')
		ft_resolution(line, info, i);
	else if (line[i] == 'N' && line[i + 1] == 'O')
		info->no = ft_strtrim(&line[i + 2], " ");
	else if (line[i] == 'S' && line[i + 1] == 'O')
		info->so = ft_strtrim(&line[i + 2], " ");
	else if (line[i] == 'W' && line[i + 1] == 'E')
		info->we = ft_strtrim(&line[i + 2], " ");
	else if (line[i] == 'E' && line[i + 1] == 'A')
		info->ea = ft_strtrim(&line[i + 2], " ");
	else if (line[i] == 'S' && line[i + 1] == ' ')
		info->s = ft_strtrim(&line[i + 2], " ");
	else if (line[i] == 'F' && BONUS == 0)
		ft_color(line, info, (i + 1), 1);
	else if (line[i] == 'F' && BONUS == 1)
		info->f = ft_strtrim(&line[i + 2], " ");
	else if (line[i] == 'C' && BONUS == 0)
		ft_color(line, info, (i + 1), 2);
	else if (line[i] == 'C' && BONUS == 1)
		info->c = ft_strtrim(&line[i + 2], " ");
	else if (line[i] == '1')
		ft_parsing_map(line, info);
	else
		ft_error(3, info);
}

void	ft_parsing(char *line, t_struct *info)
{
	int i;

	i = 0;
	while (line[i] == ' ')
		i++;
	if (!(line[i]))
		return ;
	ft_verif(line, info, i);
	ft_options(line, info, i);
}
