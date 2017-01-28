/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nterrier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 16:03:58 by nterrier          #+#    #+#             */
/*   Updated: 2016/01/08 14:53:19 by nterrier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*dst0;
	char	*src0;

	dst0 = (char *)dst;
	src0 = (char *)src;
	if (dst <= src)
		return (ft_memcpy(dst0, src0, len));
	else
	{
		while (len)
		{
			dst0[len - 1] = src0[len - 1];
			len--;
		}
	}
	return (dst);
}
