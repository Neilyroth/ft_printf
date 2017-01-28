/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nterrier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/23 17:25:09 by nterrier          #+#    #+#             */
/*   Updated: 2017/01/28 14:16:49 by nterrier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf(char *format, ...)
{
	va_list	ap;
	t_flags flags;

	va_start(ap, format);
	while (*format)
	{
		if (*format == 37)
			format = percent(++format, ap, &flags);
		else
			ft_putchar(*format);
		format++;
	}
	return (0);
}

char	*percent(char *format, va_list ap, t_flags *flags)
{
	new_flags(flags);
	format = search_flags(format, flags);
	//fait les conversions, et retourne un pointeur sur la suite du texte.
	if (*format == 'C' || *format == 'D' || *format == 'S')
		flags->l_long = 1; //flag long (raccourcis)
	if (*format == '%')
	{
		ft_putstr("%");
		return (format);
	}
	if (*format == '{')
		return (color(format));
	(*format == 'S' || *format == 's') ? string(ap, flags) : 0;
	(*format == 'D' || *format == 'd' || *format == 'i') ? number(ap, flags) : 0;
	(*format == 'p') ? pointer(ap, flags) : 0;
	(*format == 'C' || *format == 'c') ? character(ap, flags) : 0;
	(*format == 'o' || *format == 'O') ? nbr_base(8, ap, flags) : 0;
	(*format == 'u' || *format == 'U') ? nbr_base(10, ap, flags) : 0;
	(*format == 'X') ? flags->uppercase = 1 : 0;
	(*format == 'x' || *format == 'X') ? nbr_base(16, ap, flags) : 0;
	//msg_die("Format is not recognized");
	return(format);
}

void	new_flags(t_flags *flags)
{
	flags->printed = 0;

	flags->a_sharp = 0;
	flags->a_zero= 0;
	flags->a_minus = 0;
	flags->a_plus = 0;
	flags->a_space = 0;

	flags->min_length = 0;
	flags->precision = 1;

	flags->l_long = 0;
	flags->l_short = 0;
	flags->l_intmax = 0;
	flags->l_sizet = 0;

	flags->uppercase = 0;
	flags->apply_precision = 0;
}

void	print_flags(t_flags *flags)
{
	printf("#: %d\n0: %d\n+: %d\n-: %d\n : %d\n\nmin_length: %d\nprecision: %d\n\nlong:   %d\nshort:  %d\nintmax: %d\nsize_t: %d\n",
		  flags->a_sharp,flags->a_zero,flags->a_plus,flags->a_minus,flags->a_space,
		  flags->min_length,flags->precision,
		  flags->l_long,flags->l_short,flags->l_intmax,flags->l_sizet);
	return ;
}
