/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clloc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvander- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/02 10:34:10 by jvander-          #+#    #+#             */
/*   Updated: 2021/07/05 12:01:12 by jvander-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*to_ret;

	to_ret = malloc(count * size);
	if (!to_ret)
		return (NULL);
	ft_bzero(to_ret, size * count);
	return (to_ret);
}
