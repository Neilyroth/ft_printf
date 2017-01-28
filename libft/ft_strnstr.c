/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nterrier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 10:15:03 by nterrier          #+#    #+#             */
/*   Updated: 2016/01/08 14:59:25 by nterrier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	int		i;
	int		j;
	int		len1;
	int		len2;

	i = 0;
	len1 = ft_strlen((char *)s1);
	len2 = ft_strlen((char *)s2);
	while (i <= len1 - len2 && i < (int)n)
	{
		j = 0;
		while (s1[i + j] == s2[j] && s2[j] && i + j < (int)n)
			j++;
		if (s2[j] == '\0')
		{
			return ((char *)s1 + i);
		}
		i++;
	}
	return (NULL);
}
