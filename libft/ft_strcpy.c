/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nterrier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 14:48:52 by nterrier          #+#    #+#             */
/*   Updated: 2016/01/08 14:56:41 by nterrier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcpy(char *dst, const char *src)
{
	int i;
	int len;

	i = 0;
	len = ft_strlen((char *)src) + 1;
	while (i++ < len)
		dst[i - 1] = src[i - 1];
	return (dst);
	return (NULL);
}
