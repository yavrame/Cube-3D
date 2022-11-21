/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pharmund <pharmund@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 17:21:51 by pharmund          #+#    #+#             */
/*   Updated: 2022/10/13 17:21:52 by pharmund         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_list;
	t_list	*current;

	current = NULL;
	if (lst == NULL)
		return (NULL);
	while (lst != NULL)
	{
		new_list = ft_lstnew(f(lst->content));
		if (new_list == NULL)
		{
			del(current->content);
			free(current);
			return (NULL);
		}
		ft_lstadd_back(&current, new_list);
		lst = lst->next;
	}
	return (current);
}
