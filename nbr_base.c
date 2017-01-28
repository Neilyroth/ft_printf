/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nbr_base.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nterrier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/26 19:08:26 by nterrier          #+#    #+#             */
/*   Updated: 2017/01/26 19:31:22 by nterrier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void nbr_base(int base, va_list ap, t_flags *flags)
{
	int deci;

	deci = va_arg(ap, int);
	(void)flags;
	ft_putstr("{nbr_base ");
	ft_putnbr(base);
	ft_putstr("}");
	return ;
}
