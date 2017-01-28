/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nterrier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 15:35:54 by nterrier          #+#    #+#             */
/*   Updated: 2015/12/03 16:01:46 by nterrier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char *ptr;

	ptr = 0;
	if (s)
	{
		ptr = ft_strnew(len);
		if (ptr == NULL)
			return (NULL);
		ft_strncpy(ptr, s + start, len);
	}
	return (ptr);
}
