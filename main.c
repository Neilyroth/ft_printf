/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nterrier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/06 20:41:06 by nterrier          #+#    #+#             */
/*   Updated: 2017/01/28 18:03:02 by nterrier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		main()
{
	int	chiffre;
	int nombre;

	setlocale(LC_ALL, "");
	nombre = 12345;
	chiffre = 5+4;
	//ft_putstr("\033[36m");
	//ft_printf("%{red}red %{yellow}yellow %{green}green %{cyan}cyan %{blue}blue %{purple}purple %{pink}pink %{eoc}End of color.\n");
	ft_printf("Hello ! my name is%5.4s and I'm %d%% cool %ls %p\n", "Neilyroth", 100, L"|-\u4E2A-|", &chiffre);
	   printf("Hello ! my name is%5.4s and I'm %d%% cool %ls %p\n", "Neilyroth", 100, L"|-\u4E2A-|", &chiffre);

	ft_printf("%c|%c|%lc\n", 'H', 'i', L'\u4E2A');
	   printf("%c|%c|%lc\n", 'H', 'i', L'\u4E2A');
	return (0);
}

void	msg_die(char *message)
{
	ft_putstr("\033[31m");
	ft_putendl(message);
	exit(1);
}
