/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nterrier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 17:56:39 by nterrier          #+#    #+#             */
/*   Updated: 2015/12/05 15:53:16 by nterrier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *s1, const char *s2, size_t size)
{
	int		i;
	size_t	len1;
	size_t	len2;

	i = 0;
	len1 = ft_strlen(s1);
	len2 = ft_strlen((char *)s2);
	if (s1 && s2)
	{
		while (s2[i] && (len1 + i + 1) < size)
		{
			s1[len1 + i] = s2[i];
			i++;
		}
		s1[len1 + i] = '\0';
	}
	return (((len1 > size) ? size : len1) + len2);
}
