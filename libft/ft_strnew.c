/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nterrier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 15:02:06 by nterrier          #+#    #+#             */
/*   Updated: 2015/12/11 16:37:00 by nterrier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*ptr;

	ptr = NULL;
	if ((int)size > -1)
	{
		ptr = (char*)malloc(size + 1);
		if (ptr)
			ft_bzero(ptr, size + 1);
	}
	return (ptr);
}
