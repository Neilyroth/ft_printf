/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprime.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nterrier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/05 17:59:23 by nterrier          #+#    #+#             */
/*   Updated: 2015/12/05 19:11:26 by nterrier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isprime(int nb)
{
	int divisor;

	divisor = 2;
	if (nb < 2)
		return (0);
	while (divisor <= nb - 1)
	{
		if (nb % divisor == 0)
			return (0);
		divisor++;
	}
	return (1);
}
