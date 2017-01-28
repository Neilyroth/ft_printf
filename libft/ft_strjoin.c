/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nterrier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 16:04:09 by nterrier          #+#    #+#             */
/*   Updated: 2016/01/08 15:06:54 by nterrier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*ptr;
	int		len1;
	int		len2;

	ptr = NULL;
	len1 = 0;
	len2 = 0;
	if (s1 || s2)
	{
		if (s1)
			len1 = ft_strlen((char*)s1);
		if (s2)
			len2 = ft_strlen((char*)s2);
		ptr = ft_strnew(len1 + len2 + 1);
		if (ptr)
		{
			ft_strncpy(ptr, s1, len1);
			ft_strncpy(ptr + len1, s2, len2);
		}
	}
	return (ptr);
}
