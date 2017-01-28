/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nterrier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 09:41:25 by nterrier          #+#    #+#             */
/*   Updated: 2016/01/08 14:58:17 by nterrier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;
	int		len;
	char	*ptr;

	ptr = NULL;
	i = 0;
	len = ft_strlen((char *)s);
	while (i <= len && ptr == NULL)
	{
		if (s[i] == c + '\0')
			ptr = (char *)s + i;
		i++;
	}
	return (ptr);
}
