/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_split.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pharmund <pharmund@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 17:19:52 by pharmund          #+#    #+#             */
/*   Updated: 2022/10/13 17:19:53 by pharmund         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_free_split(char **split_string)
{
	int	i;

	i = 0;
	if (split_string)
	{
		while (split_string[i] != NULL)
		{
			ft_memdel(split_string[i]);
			i++;
		}
		ft_memdel(split_string);
		return (0);
	}
	else
		return (1);
}
