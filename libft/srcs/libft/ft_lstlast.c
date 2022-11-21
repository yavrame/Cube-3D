/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pharmund <pharmund@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 17:21:42 by pharmund          #+#    #+#             */
/*   Updated: 2022/10/13 17:21:43 by pharmund         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*temp_begin;

	temp_begin = lst;
	if (temp_begin == NULL)
		return (NULL);
	while (temp_begin->next != NULL)
		temp_begin = temp_begin->next;
	return (temp_begin);
}
