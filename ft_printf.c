/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nterrier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/23 17:25:09 by nterrier          #+#    #+#             */
/*   Updated: 2017/02/01 22:25:47 by nterrier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf(char *format, ...)
{
	va_list	ap;
	t_flags flags;

	flags.total = 0;
	va_start(ap, format);
	while (*format)
	{
		if (*format == 37)
			format = percent(++format, ap, &flags);
		else
		{
			ft_putchar(*format);
			flags.total++;
		}
		format++;
	}
	return (flags.total);
}

char	*percent(char *format, va_list ap, t_flags *flags)
{
	new_flags(flags);
	format = search_flags(format, flags);
	(*format == 'X') ? flags->uppercase = 1 : 0;
	(*format == 'C' || *format == 'D' || *format == 'S' || *format == 'U') ?
		LONG = 1 : 0;
	if (*format == '{')
		return (color(format, flags));
	(*format == '%') ? TOTAL += percent_char(flags) : 0;
	(*format == 'S' || *format == 's') ? TOTAL += string(ap, flags) : 0;
	(*format == 'p') ? TOTAL += adress(ap, flags) : 0;
	(*format == 'D' || *format == 'd' || *format == 'i') ?
		TOTAL += number(ap, flags) : 0;
	(*format == 'b' || *format == 'B') ? TOTAL += nbr_base(2, ap, flags) : 0;
	(*format == 'o' || *format == 'O') ? TOTAL += nbr_base(8, ap, flags) : 0;
	(*format == 'u' || *format == 'U') ? TOTAL += nbr_base(10, ap, flags) : 0;
	(*format == 'x' || *format == 'X') ? TOTAL += nbr_base(16, ap, flags) : 0;
	(*format == 'c' || *format == 'C') ? TOTAL += character(ap, flags) : 0;
	(*format == 'n') ? stock_total(ap, TOTAL) : 0;
	(*format == 'm') ? TOTAL += m_error() : 0;
	if (!ft_strchr("sSpdDibBoOuUxXcC%nm", *format))
		MSG_DIE("\033[31mWrong \033[33m'", *format, "' \033[31mSpecifier !");
	return (format);
}

void	new_flags(t_flags *flags)
{
	flags->printed = 0;
	flags->prefix = 0;
	flags->a_zero = 0;
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
