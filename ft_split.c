/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvander- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 14:07:10 by jvander-          #+#    #+#             */
/*   Updated: 2021/07/08 09:11:49 by jvander-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_count_words(const char *s, char c)
{
	int		i;
	int		nbr_words;

	i = 0;
	nbr_words = 0;
	if (s == 0 || s[0] == 0)
		return (0);
	if (c == 0)
		return (1);
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

int	ft_wordlen(const char *s, char c)
{
	int		i;

	i = 0;
	while (s[i] != '\0' && s[i] != c)
		i++;
	return (i);
}

char	*ft_strncpy(const char *s, int size)
{
	char	*to_ret;

	to_ret = malloc(sizeof(char) * (size));
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
	char	**to_ret;
	int		nbr_words;
	int		i;
	int		size_word;
	int		j;

	if (s == 0 && c == 0)
		return (NULL);
	nbr_words = ft_count_words(s, c);
	to_ret = malloc(sizeof(char *) * (nbr_words + 1));
	if (to_ret == NULL)
		return (NULL);
	i = 0;
	j = 0;
	while (j < nbr_words)
	{
		while (s[i] && s[i] == c)
			i++;
		size_word = ft_wordlen(s + i, c);
		to_ret[j++] = ft_strncpy(s + i, size_word);
		i += size_word;
	}
	to_ret[nbr_words] = 0;
	return (to_ret);
}
