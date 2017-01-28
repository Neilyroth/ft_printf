/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nterrier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 12:25:25 by nterrier          #+#    #+#             */
/*   Updated: 2016/01/12 20:28:58 by nterrier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	unsigned int	u;

	u = n;
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		u = -u;
	}
	if (u >= 10)
	{
		ft_putnbr_fd(u / 10, fd);
		ft_putnbr_fd(u % 10, fd);
	}
	else
		ft_putchar_fd('0' + u, fd);
}
