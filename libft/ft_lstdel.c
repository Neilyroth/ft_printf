/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nterrier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 15:15:20 by nterrier          #+#    #+#             */
/*   Updated: 2015/12/05 14:33:42 by nterrier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*ptr;
	t_list	*next_temp;

	if (*alst && del)
	{
		ptr = *alst;
		while (ptr->next)
		{
			next_temp = ptr->next;
			ft_lstdelone(&ptr, del);
			ptr = next_temp;
		}
		ft_lstdelone(&ptr, del);
		*alst = NULL;
	}
}
