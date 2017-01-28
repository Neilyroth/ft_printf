/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nterrier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 15:53:48 by nterrier          #+#    #+#             */
/*   Updated: 2016/01/08 14:57:41 by nterrier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	int i;
	int len1;

	i = 0;
	len1 = ft_strlen(s1);
	while (s2[i] && i < (int)n)
	{
		s1[len1 + i] = s2[i];
		i++;
	}
	s1[len1 + i] = '\0';
	return (s1);
	return (NULL);
}
