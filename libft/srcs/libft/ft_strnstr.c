/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pharmund <pharmund@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 17:26:13 by pharmund          #+#    #+#             */
/*   Updated: 2022/10/13 17:26:14 by pharmund         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	c;

	i = 0;
	c = 0;
	if (needle[c] == '\0')
		return ((char *)haystack);
	while (haystack[i] != '\0' && len >= i)
	{
		c = 0;
		if (needle[0] == haystack[i])
		{
			while ((needle[c] != '\0')
				&& (needle[c] == haystack[i + c]) && (i + c < len))
			{
				c++;
				if (needle[c] == '\0')
					return ((char *)&haystack[i]);
			}
		}
		i++;
	}
	return (NULL);
}
