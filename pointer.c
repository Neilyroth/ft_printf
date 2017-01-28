/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pointer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nterrier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/26 18:02:13 by nterrier          #+#    #+#             */
/*   Updated: 2017/01/26 19:19:58 by nterrier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	pointer(va_list ap, t_flags *flags)
{
	void	*point;

	point = va_arg(ap, void*);
	(void)flags;
	ft_putstr("0x............");
	return ;
}
