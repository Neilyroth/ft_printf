/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nterrier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 15:13:21 by nterrier          #+#    #+#             */
/*   Updated: 2016/01/08 14:51:45 by nterrier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	i;
	char	*dst0;
	char	*src0;

	dst0 = (char*)dst;
	src0 = (char*)src;
	i = 0;
	while (i < n)
	{
		dst0[i] = src0[i];
		i++;
	}
	return (dst);
}
