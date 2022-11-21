/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pharmund <pharmund@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 17:22:06 by pharmund          #+#    #+#             */
/*   Updated: 2022/10/13 17:22:07 by pharmund         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	t_list	*temp_begin;
	int		count;

	count = 0;
	temp_begin = lst;
	while (temp_begin != NULL)
	{
		count++;
		temp_begin = temp_begin->next;
	}
	return (count);
}
