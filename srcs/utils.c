/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pharmund <pharmund@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 17:30:18 by pharmund          #+#    #+#             */
/*   Updated: 2022/10/13 17:30:19 by pharmund         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

size_t	ft_strlen_nl(char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0' && str[i] != '\n')
		i++;
	return (i);
}

void	ft_init_data(t_data *data)
{
	data->elems = ft_calloc(1, sizeof(t_element));
	data->map = ft_calloc(1, sizeof(t_map));
	data->txtrs = ft_calloc(4, sizeof(t_texture));
	if (!data->elems || !data->map || !data->txtrs)
		ft_exit_error("Error\nMalloc Errror\n");
	ft_bzero(&data->move, sizeof(t_move));
	ft_bzero(&data->vals, sizeof(t_values));
	ft_bzero(&data->keys, sizeof(t_keys));
}

void	ft_exit_error(char *error)
{
	ft_putstr_fd(RED, STDERR_FILENO);
	ft_putstr_fd(error, STDERR_FILENO);
	ft_putstr_fd(BREAK, STDERR_FILENO);
	exit(EXIT_FAILURE);
}

void	ft_game_msg(char *msg)
{
	ft_putstr_fd(YELLOW, STDOUT_FILENO);
	ft_putstr_fd(msg, STDOUT_FILENO);
	ft_putstr_fd(BREAK, STDOUT_FILENO);
}

void	ft_printf_split(char **split)
{
	int	i;

	i = -1;
	if (split == NULL || *split == NULL)
		return ;
	while (split[++i])
		printf("%s\n", split[i]);
}
