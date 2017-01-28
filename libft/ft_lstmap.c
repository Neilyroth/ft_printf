/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nterrier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 16:23:36 by nterrier          #+#    #+#             */
/*   Updated: 2015/12/05 14:35:02 by nterrier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*first;
	t_list	*last;

	first = NULL;
	if (lst && f)
	{
		first = f(lst);
		last = first;
		while (lst->next)
		{
			lst = lst->next;
			last->next = f(lst);
			last = last->next;
		}
	}
	return (first);
}
