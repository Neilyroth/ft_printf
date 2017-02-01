/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nterrier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/24 19:31:22 by nterrier          #+#    #+#             */
/*   Updated: 2017/02/01 22:30:28 by nterrier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static size_t	wcharlen(unsigned c)
{
	if (c < 0x80)
		return (1);
	else if (c < 0x800)
		return (2);
	else if (c < 0x10000)
		return (3);
	return (4);
}

static size_t	ft_wstrlen(unsigned *str, int wide)
{
	size_t len;

	len = 0;
	while (*str != L'\0')
	{
		if (wide)
			len += wcharlen(*str);
		else
			len++;
		str++;
	}
	return (len);
}

int				string(va_list ap, t_flags *flags)
{
	unsigned	*str;
	int			nb_spaces;
	int			str_len;
	int			str_len_wide;

	str = va_arg(ap, unsigned*);
	if (str == NULL)
	{
		ft_putstr("(null)");
		return (6);
	}
	str_len = (int)((LONG) ? ft_wstrlen(str, 0) : ft_strlen((char*)str));
	str_len_wide = (int)((LONG) ? ft_wstrlen(str, 1) : str_len);
	(!flags->apply_precision) ? flags->precision = str_len_wide : 0;
	nb_spaces = flags->min_length - smallest(flags->precision, str_len_wide);
	adjust_length(nb_spaces, !flags->a_minus, ' ');
	while ((char)*str && flags->precision >= ((LONG) ? (int)wcharlen(*str) : 1))
	{
		(LONG) ? ft_putwchar(*str) : ft_putchar((char)(*str));
		flags->precision -= (LONG) ? wcharlen(*str) : 1;
		flags->printed += (LONG) ? wcharlen(*str) : 1;
		str = (LONG) ? str + 1 : (unsigned *)((char*)str + 1);
	}
	adjust_length(nb_spaces, flags->a_minus, ' ');
	return (flags->printed + bigest(nb_spaces, 0));
}

int				m_error(void)
{
	char	*str;

	str = strerror(errno);
	ft_putstr(str);
	return ((int)ft_strlen(str));
}
