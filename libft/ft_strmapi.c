/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nterrier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 15:09:32 by nterrier          #+#    #+#             */
/*   Updated: 2016/01/08 15:22:31 by nterrier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		len;
	int		i;
	char	*ptr;

	i = 0;
	ptr = 0;
	if (s)
	{
		len = ft_strlen((char*)s);
		ptr = ft_strnew(len);
		while (len - i && ptr)
		{
			ptr[i] = f(i, s[i]);
			i++;
		}
	}
	return (ptr);
}
