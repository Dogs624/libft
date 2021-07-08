/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvander- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/02 10:33:48 by jvander-          #+#    #+#             */
/*   Updated: 2021/07/08 07:35:56 by jvander-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_check_longmax(int negative)
{
	if (negative == -1)
		return (0);
	return (-1);
}

int	ft_atoi(const char *s)
{
	unsigned long long	res;
	int					i;
	int					negative;

	i = 0;
	negative = 1;
	res = 0;
	while (s[i] == '\t' || s[i] == '\v' || s[i] == '\r' || s[i] == '\f'
		|| s[i] == '\n' || s[i] == ' ')
		i++;
	if (s[i] == '-' || s[i] == '+')
	{
		if (s[i] == '-')
			negative *= -1;
		i++;
	}
	while (s[i] >= '0' && s[i] <= '9')
	{
		res *= 10;
		res += s[i] - 48;
		i++;
	}
	if (res > LLONG_MAX)
		return (ft_check_longmax(negative));
	return (res * negative);
}
