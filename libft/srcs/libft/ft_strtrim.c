/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pharmund <pharmund@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 17:26:26 by pharmund          #+#    #+#             */
/*   Updated: 2022/10/13 17:26:27 by pharmund         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	int		s1_len;
	char	*new;

	i = 0;
	if (s1 == NULL || set == NULL)
		return (NULL);
	s1_len = ft_strlen(s1);
	while (s1[i] != '\0' && ft_strchr(set, s1[i]))
		i++;
	while (s1_len > 0 && ft_strchr(set, s1[s1_len]))
		s1_len--;
	new = ft_substr(s1, i, s1_len - i + 1);
	if (!new)
		return (NULL);
	return (new);
}
