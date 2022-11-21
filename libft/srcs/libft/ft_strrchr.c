/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pharmund <pharmund@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 17:26:20 by pharmund          #+#    #+#             */
/*   Updated: 2022/10/13 17:26:21 by pharmund         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	int		i;
	char	*found;

	found = (char *)str;
	i = 0;
	while (str[i] != '\0')
		i++;
	i += 1;
	while (i > 0)
	{
		i--;
		if (str[i] == (char)c)
			return (found + i);
	}
	return (NULL);
}
