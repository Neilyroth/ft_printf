/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nterrier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 16:38:52 by nterrier          #+#    #+#             */
/*   Updated: 2015/12/11 16:34:59 by nterrier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_str_count_words(char const *s, char c)
{
	int i;
	int j;

	i = 0;
	j = 1;
	while (s[i] == c && s[i++])
		i++;
	while (s[i])
	{
		while (s[i] != c && s[i])
			i++;
		while (s[i] == c && s[i])
			i++;
		j++;
	}
	return (j);
}

static int	ft_count_letters(char const *s, char c, int i)
{
	int	letters;
	int	n;

	n = i;
	letters = 0;
	while (s[n] != c && s[n])
	{
		letters++;
		n++;
	}
	return (letters);
}

char		**ft_strsplit(char const *s, char c)
{
	int		i;
	int		count;
	char	**tab;

	i = 0;
	count = 0;
	tab = 0;
	if (s)
	{
		tab = (char **)malloc(sizeof(char*) * ft_str_count_words(s, c) + 10);
		if (!tab)
			return (NULL);
		while (s[i] == c && s[i])
			i++;
		while (s[i])
		{
			tab[count] = ft_strsub(s, i, ft_count_letters(s, c, i));
			i = i + ft_count_letters(s, c, i);
			while (s[i] == c && s[i])
				i++;
			count++;
		}
		tab[count] = NULL;
	}
	return (tab);
}
