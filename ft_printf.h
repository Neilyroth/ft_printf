/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nterrier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/23 16:44:35 by nterrier          #+#    #+#             */
/*   Updated: 2017/01/28 17:29:52 by nterrier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h> //printf

# include <stdarg.h> //fonction variadiques
# include <stdlib.h> //malloc, free, exit
# include <unistd.h> //write
# include <locale.h> //definir la locale pour les wchar
# include <wchar.h> //%lc

# include "libft/libft.h"

typedef struct s_flags
{
	int printed;

	int a_sharp;
	int a_zero;
	int a_minus;
	int a_plus;
	int a_space;

	int min_length;
	int precision;

	int l_long;
	int l_short;
	int l_intmax;
	int l_sizet;

	int uppercase;
	int apply_precision;
}		t_flags;



void	msg_die(char *message);

int		ft_printf(char *format, ...);
char	*percent(char *format, va_list ap, t_flags *flags);
void	new_flags(t_flags *flags);
void	print_flags(t_flags *flags);
char	*color(char *format);

char	*search_flags(char *format, t_flags *flags);
char	*attributes(char *format, t_flags *flags);
char	*field_width(char *format, t_flags *flags);
char	*precision(char *format, t_flags *flags);
char	*length_modifier(char *format, t_flags *flags);

void	adjust_length(int nb_spaces, int on);


void	string(va_list ap, t_flags *flags);

int		number(va_list ap, t_flags *flags);
char	*itoa_printf(va_list ap, t_flags *flags);

void	pointer(va_list ap, t_flags *flags);

void	character(va_list ap, t_flags *flags);
int		ft_putwchar(unsigned wchar);

void	nbr_base(int base, va_list ap, t_flags *flags);
#endif
