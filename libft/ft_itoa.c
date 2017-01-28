/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nterrier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 18:01:43 by nterrier          #+#    #+#             */
/*   Updated: 2016/01/12 18:45:15 by nterrier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char static	*ft_itoa_safe(unsigned int n, char *res, int i)
{
	size_t	p;

	p = 10000000000;
	if (n == 0)
	{
		res[i] = '0';
		res[i + 1] = '\0';
		return (res);
	}
	while (n && (n / p) == 0)
		p = p / 10;
	while (p != 1)
	{
		res[i] = '0' + (n / p);
		n = n % p;
		i++;
		p = p / 10;
	}
	res[i] = '0' + n;
	res[i + 1] = '\0';
	return (res);
}

char		*ft_itoa(int n)
{
	int				i;
	unsigned int	m;
	char			*res;

	i = 0;
	res = ft_strnew(12);
	if (res == NULL)
		return (NULL);
	if (n < 0)
	{
		res[i] = '-';
		i++;
		m = (unsigned int)((-1) * n);
	}
	else
		m = (unsigned int)n;
	return (ft_itoa_safe(m, res, i));
}
