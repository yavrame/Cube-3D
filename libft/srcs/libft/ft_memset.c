/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pharmund <pharmund@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 17:22:55 by pharmund          #+#    #+#             */
/*   Updated: 2022/10/13 17:22:56 by pharmund         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*arr;
	int				i;

	arr = (unsigned char *)b;
	i = 0;
	while (len > 0)
	{
		arr[i++] = (unsigned char)c;
		len--;
	}
	return (b);
}
