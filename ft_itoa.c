/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvander- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 15:04:13 by jvander-          #+#    #+#             */
/*   Updated: 2021/07/05 14:58:40 by jvander-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_nbr_char(int n)
{
	int	res;

	res = 0;
	if (n < 0)
		n = -n;
	while (n > 0)
	{
		res++;
		n /= 10;
	}
	return (res);
}

char	*ft_itoa(int n)
{
	char	*to_ret;
	int		nbr_char;
	long	nbr;
	int i;

	i = 0;
	nbr = n;
	nbr_char = ft_nbr_char(n) - 1;
	if (n < 0)
	{
		nbr = -n;
		nbr_char++;
		i = 1;
	}
	to_ret = malloc(sizeof(char) * nbr_char);
	if (to_ret == NULL)
		return (NULL);
	if (n < 0)
		to_ret[0] = '-';
	to_ret[nbr_char - 1] = '\0';
	while (nbr > 9)
	{
		to_ret[nbr_char] = (nbr % 10) + 48;
		nbr = nbr / 10;
		nbr_char--;
	}
	to_ret[nbr_char] = nbr + 48;
	return (to_ret);
}
