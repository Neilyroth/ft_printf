/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nextprime.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nterrier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/05 18:01:20 by nterrier          #+#    #+#             */
/*   Updated: 2015/12/05 19:12:32 by nterrier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_nextprime(int nb)
{
	int divisor;

	divisor = 2;
	if (nb < 2)
		return (2);
	while (divisor <= nb - 1)
	{
		if (nb % divisor == 0)
			return (ft_nextprime(nb + 1));
		divisor++;
	}
	return (nb);
}
