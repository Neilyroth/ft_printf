/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nterrier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 15:50:17 by nterrier          #+#    #+#             */
/*   Updated: 2016/01/08 14:52:16 by nterrier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t		i;
	const char	*src0;
	char		*dst0;

	i = 0;
	src0 = src;
	dst0 = (char*)dst;
	while (i < n)
	{
		dst0[i] = src0[i];
		if (src0[i] == (char)c)
			return ((void *)dst0 + i + 1);
		i++;
	}
	return (NULL);
}
