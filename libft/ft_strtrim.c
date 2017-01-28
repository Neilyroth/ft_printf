/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nterrier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 16:09:39 by nterrier          #+#    #+#             */
/*   Updated: 2015/12/03 16:51:57 by nterrier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	int i;
	int j;

	i = 0;
	j = 0;
	if (s)
	{
		while ((s[i] == ' ' || s[i] == '\n' || s[i] == '\t') && s[i])
			i++;
		if (s[i] == '\0')
			return (ft_strnew(0));
		while (s[i + j])
			j++;
		j--;
		while (s[i + j] == ' ' || s[i + j] == '\n' || s[i + j] == '\t')
			j--;
		return (ft_strsub(s, i, j + 1));
	}
	return (0);
}
