/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   character.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nterrier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/26 18:18:08 by nterrier          #+#    #+#             */
/*   Updated: 2017/01/28 17:46:28 by nterrier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static size_t	wcharlen(unsigned c)
{ //retourne le nombre de bytes occupes par le wchar
	//ft_putnbr(c);
	if (c < 0x80)
		return (1);
	else if (c < 0x800)
		return (2);
	else if (c < 0x10000)
		return (3);
	return (4);
}

//00000000 -- 0000007F: 	0xxxxxxx
//00000080 -- 000007FF: 	110xxxxx 10xxxxxx
//00000800 -- 0000FFFF: 	1110xxxx 10xxxxxx 10xxxxxx
//00010000 -- 001FFFFF: 	11110xxx 10xxxxxx 10xxxxxx 10xxxxxx

void	character(va_list ap, t_flags *flags)
{
	unsigned c;
	int len;

	c = va_arg(ap, unsigned);
	//ft_putnbr(c);
	adjust_length(flags->min_length - 1, !flags->a_minus);
	//write(1, &c, wcharlen(c));//test
	len = ft_putwchar(c);
	adjust_length(flags->min_length - 1, flags->a_minus);
	return ;
}

int ft_putwchar(unsigned wchar)
{
	int nb_bytes;

	nb_bytes = wcharlen(wchar);
	if (nb_bytes == 1)
		ft_putchar(wchar);
	else if (nb_bytes == 2)
	{
		ft_putchar(((wchar & (0x1f << 6)) >> 6) + 0xC0);
		ft_putchar(((wchar & 0x3f       )     ) + 0x80);
	}
	else if (nb_bytes == 3)
	{
		ft_putchar(((wchar & (0xf << 12)) >> 12) + 0xE0);
		ft_putchar(((wchar & (0x3f << 6)) >> 6 ) + 0x80);
		ft_putchar(((wchar & 0x3f       )      ) + 0x80);
	}
	else
	{
		ft_putchar(((wchar & ( 0x7 << 18)) >> 18) + 0xF0);
		ft_putchar(((wchar & (0x3f << 12)) >> 12) + 0x80);
		ft_putchar(((wchar & (0x3f << 6 )) >> 6)  + 0x80);
		ft_putchar(((wchar & 0x3f        )     )  + 0x80);
	}
	return(nb_bytes);
}
