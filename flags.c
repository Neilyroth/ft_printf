/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nterrier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/27 14:21:23 by nterrier          #+#    #+#             */
/*   Updated: 2017/01/27 19:00:41 by nterrier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

//l'attribut - calcule pour toute conversion, grace a min_length


char	*search_flags(char *format, t_flags *flags)
{
	format = attributes(format, flags);
	format = field_width(format, flags);
	format = precision(format, flags);
	format = length_modifier(format, flags);
	//print_flags(flags);
	return (format);
}

char *attributes(char *format, t_flags *flags)
{
	while (ft_strchr("#0+- ", *format))
	{
		(*format == '#') ? flags->a_sharp = 1 : 0;
		(*format == '0') ? flags->a_zero  = 1 : 0;
		(*format == '+') ? flags->a_plus  = 1 : 0;
		(*format == '-') ? flags->a_minus = 1 : 0;
		(*format == ' ') ? flags->a_space = 1 : 0;
		format++;
	}
	(flags->a_minus) ? flags->a_zero = 0 : 0;// '-' surcharge '0'
	(flags->a_plus) ? flags->a_space = 0 : 0;// '+' surcharge ' '
	return(format);
}

char *field_width(char *format, t_flags *flags)
{
	int value;

	if (ft_strchr("123456789", *format))
	{
		value = ft_atoi(format);//recoder noter atoi en brut ici pour eviter un probleme ?
		if (value < 0) // c'est cense ne jamais arriver, sauf si atoi retourne un nombre indefini :(
		{
			value = (-value); // attention -2148....48 !
			flags->a_minus = 1; //penser a surcharger '0' ???
		}
		flags->min_length = value;
		while(ft_strchr("0123456789", *format))
			format++;
	}
	return(format);
}

char *precision(char *format, t_flags *flags)
{
	int value;

	if (ft_strchr(".", *format))
	{
		value = ft_atoi(++format);//devrait passer
		flags->precision = (value > 0) ? value : 0;
		while(ft_strchr("0123456789", *format))
			format++;
		flags->apply_precision = 1;
	}
	return(format);
}

char *length_modifier(char *format, t_flags *flags)
{
	while (ft_strchr("hljz", *format))
	{
		(*format == 'h') ? flags->l_short  = 1 : 0;
		(*format == 'l') ? flags->l_long   = 1 : 0;
		(*format == 'j') ? flags->l_intmax = 1 : 0;
		(*format == 'z') ? flags->l_sizet  = 1 : 0;
		format++;
	}
	return(format);
}

