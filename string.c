/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nterrier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/24 19:31:22 by nterrier          #+#    #+#             */
/*   Updated: 2017/01/28 17:58:42 by nterrier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	string(va_list ap, t_flags *flags)
{// - 30 .10 l
	char	*str;
	int		nb_spaces;

	str = va_arg(ap, char*);



	if (!flags->apply_precision)
		flags->precision = ft_strlen(str); //ne marche pas avec les long !!
	nb_spaces = flags->min_length - ((flags->precision < (int)ft_strlen(str)) ? flags->precision : ft_strlen(str));

	adjust_length(nb_spaces, !flags->a_minus);
	while (*str && flags->precision)
	{
		//if (flags->l_long)
		//	ft_putwchar((unsigned)*str);
		//else
			ft_putchar(*str);
		flags->precision--;
		str++;
	}
	adjust_length(nb_spaces, flags->a_minus);
	return ;
}
