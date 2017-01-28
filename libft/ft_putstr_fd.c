/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nterrier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 11:04:13 by nterrier          #+#    #+#             */
/*   Updated: 2015/12/05 15:41:18 by nterrier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_fd(char const *s, int fd)
{
	int nb;
	int i;

	if (s)
	{
		nb = ft_strlen((char*)s);
		i = 0;
		while (i++ < nb)
			ft_putchar_fd(s[i - 1], fd);
	}
}
