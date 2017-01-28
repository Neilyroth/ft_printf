/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nterrier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 16:02:11 by nterrier          #+#    #+#             */
/*   Updated: 2015/12/05 14:34:31 by nterrier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(t_list *elem))
{
	t_list *ptr;

	if (lst && f)
	{
		ptr = lst;
		f(ptr);
		while (ptr->next)
		{
			ptr = ptr->next;
			f(ptr);
		}
	}
}
