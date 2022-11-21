/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pharmund <pharmund@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 17:25:36 by pharmund          #+#    #+#             */
/*   Updated: 2022/10/13 17:25:37 by pharmund         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	dest_len;
	size_t	src_len;
	size_t	i;
	size_t	c;

	i = 0;
	c = 0;
	dest_len = ft_strlen(dst);
	i = dest_len;
	src_len = ft_strlen(src);
	if (dstsize < dest_len + 1)
		return (src_len + dstsize);
	else
	{
		dstsize = dstsize - dest_len - 1;
		while (src[c] != '\0' && dstsize > 0)
		{
			dst[i++] = src[c++];
			dstsize--;
		}
		dst[i] = '\0';
	}
	return (dest_len + src_len);
}
