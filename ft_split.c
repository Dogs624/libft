/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvander- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 14:07:10 by jvander-          #+#    #+#             */
/*   Updated: 2021/07/07 08:42:27 by jvander-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_nbr_words(char const *s, char c)
{
	int	i;
	int	nbr_words;

	i = 0;
	nbr_words = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c)
		{
			i++;
			nbr_words++;
		}
		while (s[i] != c)
		{
			if (s[i] == '\0')
				return (nbr_words);
			i++;
		}
		i++;
	}
	return (nbr_words);
}

int	ft_word_size(char *s, int c)
{
	int	i;

	i = 0;
	while (s[i] != '\0' && s[i] != c)
		i++;
	return (i);
}

void	*ft_free(char **tab, int len)
{
	while (len >= 0)
	{
		free(tab[len]);
		len--;
	}
	return (NULL);
}

char	*ft_strncpy(char *s, int size)
{
	char	*to_ret;

	to_ret = malloc(sizeof(char) * (size + 1));
	if (to_ret == NULL)
		return (NULL);
	to_ret[size] = '\0';
	size--;
	while (size >= 0)
	{
		to_ret[size] = s[size];
		size--;
	}
	return (to_ret);
}

char	**ft_split(char const *s, char c)
{
	char	**tab;
	int		nbr_words;
	int		i;
	int		size_word;
	int		j;

	if (s == NULL)
		return (NULL);
	nbr_words = ft_nbr_words(s, c);
	tab = malloc(sizeof(char *) * nbr_words + 1);
	if (tab == NULL)
		return (NULL);
	i = 0;
	j = 0;
	while (s[i] != '\0')
	{
		while (s[i] != '\0' && s[i] == c)
			i++;
		tab[j++] = ft_strncpy((char *) s + i, ft_word_size((char *) s + i, c));
		if (tab[j - 1] == NULL)
			return (ft_free(tab, j - 1));
		i += ft_word_size((char *) s + i, c);
	}
	tab[nbr_words] = 0;
	return (tab);
}
