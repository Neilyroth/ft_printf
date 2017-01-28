/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nterrier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/05 17:52:26 by nterrier          #+#    #+#             */
/*   Updated: 2015/12/05 17:55:23 by nterrier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_sqrt(int nb)
{
	int odd;
	int sum;

	odd = 1;
	sum = 0;
	while (sum < nb)
	{
		sum += odd;
		odd += 2;
	}
	if (sum == nb)
		return (odd / 2);
	else
		return (0);
}
