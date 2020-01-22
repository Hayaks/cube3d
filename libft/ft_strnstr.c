/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaguez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 13:34:09 by jsaguez           #+#    #+#             */
/*   Updated: 2019/11/13 15:01:27 by jsaguez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *to_find, size_t len)
{
	size_t	i;
	size_t	i_word;
	size_t	size_word;

	i = 0;
	size_word = ft_strlen(to_find);
	if (size_word == 0)
		return ((char*)str);
	while (str[i] && i < len)
	{
		i_word = 0;
		while (str[i + i_word] == to_find[i_word])
		{
			if ((i + i_word) > len)
				return (0);
			i_word++;
			if (i_word == size_word)
				return ((char*)&str[i]);
		}
		i++;
	}
	return (0);
}
