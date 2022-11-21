/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pharmund <pharmund@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 17:27:31 by pharmund          #+#    #+#             */
/*   Updated: 2022/10/13 17:27:32 by pharmund         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_free_elems(t_data *data)
{
	ft_memdel(data->elems->north_txtr);
	ft_memdel(data->elems->south_txtr);
	ft_memdel(data->elems->west_txtr);
	ft_memdel(data->elems->east_txtr);
	ft_memdel(data->elems->floor_clr);
	ft_memdel(data->elems->ceiling_clr);
}

void	ft_destroy_textures(t_data *data, t_texture *t)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (t[i].img != (void *)0)
			mlx_destroy_image(data->mlx, t[i].img);
		i++;
	}
}

void	ft_free_all(t_data *data)
{
	if (data->mlx != (void *)0)
		mlx_destroy_window(data->mlx, data->mlx_win);
	ft_free_elems(data);
	ft_memdel(data->elems);
	ft_free_split(data->map->game_map);
	ft_memdel(data->map);
	ft_destroy_textures(data, data->txtrs);
	ft_memdel(data->txtrs);
}

int	ft_free_exit_msg(t_data *data, char *error)
{
	ft_free_all(data);
	if (error != NULL)
		ft_exit_error(error);
	exit(EXIT_SUCCESS);
}

int	ft_free_exit(t_data *data)
{
	ft_free_all(data);
	exit(EXIT_SUCCESS);
}
