/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_trimset.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaguez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 09:13:17 by jsaguez           #+#    #+#             */
/*   Updated: 2020/01/27 09:13:23 by jsaguez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char    *ft_trimset(char *str, char *set)
{
    char    *new;
    int     i;
    int     j;
    int     c;

    i = 0;
    j = 0;
    c = 0;
    while (str[i])
    {
        while (set[j] && str[i] != set[j])
            j++;
        if (str[j] && str[i] != set[j])
            c++;
        i++;
        j = 0;
    }
    i = 0;
    if (!(new = malloc(sizeof(*new) * (c + 1))))
        return (NULL);
    c = 0;
    while (str[i])
    {
        while (set[j] && str[i] != set[j])
            j++;
        if (str[j] && str[i] != set[j])
        {
            new[c] = str[i];
            c++;
        }
        i++;
        j = 0;
    }
    new[c + 1] = '\0';
    return (new);
}