/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvander- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/02 10:26:18 by jvander-          #+#    #+#             */
/*   Updated: 2021/07/06 18:14:50 by jvander-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	i;
	char	*dst_char;
	const char	*src_char;

	dst_char = (char *) dst;
	src_char = (const char *) src;
	if (dst_char == NULL && src_char == NULL)
		return (NULL);
	i = 0;
	if (src_char < dst_char)
	{
		while (len-- > 0)
			dst_char[len] = src_char[len];
	}
	else 
	{	
		while (len-- > 0)
			*dst_char++ = *src_char++;
	}
	return (dst);
}
