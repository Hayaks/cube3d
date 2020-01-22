/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaguez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 11:54:41 by jsaguez           #+#    #+#             */
/*   Updated: 2019/11/13 15:08:28 by jsaguez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list *list;
	t_list *tmp;

	list = *lst;
	tmp = NULL;
	if (!lst || !*lst)
		return ;
	while (list)
	{
		if (list->next)
			tmp = list->next;
		else
			tmp = NULL;
		del(list->content);
		free(list);
		list = tmp;
	}
	*lst = NULL;
}
