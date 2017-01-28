/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   number.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nterrier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/24 19:38:56 by nterrier          #+#    #+#             */
/*   Updated: 2017/01/28 14:44:30 by nterrier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			number(va_list ap, t_flags *flags)
{ //flags supportes : "-"                         + 0-   largeur precision hljz
	int len;
	int max_length;
	char *number;
	int nb_spaces;


	number = itoa_printf(ap, flags);//penser a enlever l'eventuel -
	len = ft_strlen(number);
	flags->printed += len;

	max_length = ((len < flags->precision) ? flags->precision : len);

	nb_spaces = ((max_length < flags->min_length) ? flags->min_length - max_length: 0);

	adjust_length(nb_spaces, !flags->a_minus);
	while (flags->printed < flags->precision){
		ft_putchar('0');
		flags->printed++;
	}
	ft_putstr(number);
	adjust_length(nb_spaces, flags->a_minus);

	return (flags->printed);
}

char	*itoa_printf(va_list ap, t_flags *flags)
{
	int d;
	//precision
	//+
	// 
	//hljz

	(void)flags;

	d = va_arg(ap, int);
	return (ft_itoa(d));
}
