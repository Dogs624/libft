/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvander- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/02 10:26:18 by jvander-          #+#    #+#             */
/*   Updated: 2021/07/05 09:11:19 by jvander-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char			*char_dst;
	const char		*char_src;
	size_t			i;

	char_dst = (char *) dst;
	char_src = (const char *) src;
	i = 0;
	if (char_dst == NULL && char_src == NULL)
		return (NULL);	
	if (char_dst < char_src)
	{
		while (i++ < len)
			char_dst[i] = char_src[i];
	}
	else
	{
		while (len-- > 0)
			char_dst[len] = char_src[len];
	}
	return (dst);
}
