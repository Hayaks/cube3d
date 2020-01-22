/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaguez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 09:52:34 by jsaguez           #+#    #+#             */
/*   Updated: 2019/11/13 15:06:38 by jsaguez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*list;

	if (!(list = malloc(sizeof(*list))))
		return (0);
	if (!(list->content = malloc(sizeof(*content))))
		return (0);
	list->content = content;
	list->next = NULL;
	return (list);
}
