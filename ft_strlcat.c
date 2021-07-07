/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvander- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/02 10:32:04 by jvander-          #+#    #+#             */
/*   Updated: 2021/07/07 08:47:28 by jvander-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	dst_len;
	size_t	src_len;

	dst_len = ft_strlen(dst);
	src_len = ft_strlen(src);
	if (dst == NULL && src == NULL)
		return (-1);
	if (dstsize == 0)
		return (dst_len);
	i = 0;
	while (src[i] != '\0' && i < dstsize - dst_len - 1)
	{
		dst[i + dst_len] = src[i];
		i++;
	}
	if (i <= dstsize - dst_len - 1)
		dst[i + dst_len] = '\0';
	if (dst_len < dstsize)
		return (dst_len + src_len);
	else
		return (dstsize + src_len);
}
