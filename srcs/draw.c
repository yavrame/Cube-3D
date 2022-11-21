/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pharmund <pharmund@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 17:27:41 by pharmund          #+#    #+#             */
/*   Updated: 2022/10/13 17:27:42 by pharmund         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	ft_set_dir_plane(t_data *data, t_values *vals)
{
	data->move.dir_x = vals->x1;
	data->move.dir_y = vals->y1;
	data->move.plane_x = vals->x2;
	data->move.plane_y = vals->y2;
}

static void	ft_set_initial_pos(t_data *data)
{
	data->move.pos_x = (double)(data->map->player_x + 0.5);
	data->move.pos_y = (double)(data->map->player_y + 0.5);
	if (data->map->player_dir == 'N')
		ft_set_dir_plane(data, &((t_values){0.0, -1, 0.6, 0.0}));
	if (data->map->player_dir == 'E')
		ft_set_dir_plane(data, &((t_values){1, 0.0, 0.0, 0.6}));
	if (data->map->player_dir == 'S')
		ft_set_dir_plane(data, &((t_values){0.0, 1, -0.6, 0.0}));
	if (data->map->player_dir == 'W')
		ft_set_dir_plane(data, &((t_values){-1, 0.0, 0.0, -0.6}));
	data->move.move_speed_val = 1.5;
}

void	ft_start_draw(t_data *data)
{
	data->map->floor = ft_convert_color(data->elems->floor_clr);
	data->map->ceiling = ft_convert_color(data->elems->ceiling_clr);
	ft_set_initial_pos(data);
	ft_minimap_init(data);
	ft_mlx(data);
}
