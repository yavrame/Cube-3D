/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pharmund <pharmund@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 17:29:11 by pharmund          #+#    #+#             */
/*   Updated: 2022/10/13 17:29:12 by pharmund         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_minimap_init(t_data *data)
{
	data->map->min = WIN_WIDTH / 100;
	if (data->map->height * data->map->min > WIN_HEIGHT / 2)
		data->map->min -= 2;
	if (data->map->width * data->map->min > WIN_WIDTH / 2 - 100)
		data->map->min -= 2;
}

void	ft_draw_cell(t_data *data, int x, int y, int color)
{
	int	x_start;
	int	y_start;

	y_start = y;
	while (y_start < y + data->map->min)
	{
		x_start = x;
		while (x_start < x + data->map->min)
		{
			ft_mlx_pixel_put(data, x_start, y_start, color);
			x_start++;
		}
		y_start++;
	}
}

void	ft_draw_2d_map(t_data *data, t_move *mv, t_map *map)
{
	int		x;
	int		y;
	int		len;

	y = 0;
	while (y < map->height)
	{
		x = -1;
		len = (int)ft_strlen_nl(map->game_map[y]);
		while (++x < len)
		{
			if (map->game_map[y][x] == '1')
				ft_draw_cell(data, x * map->min, y * map->min, PURPLE_INT);
			else if (map->game_map[y][x] != ' ')
				ft_draw_cell(data, x * map->min, y * map->min, BLUE_INT);
			if (y == (int)mv->pos_y && x == (int)mv->pos_x)
				ft_draw_cell(data, x * map->min, y * map->min, YELLOW_INT);
		}
		y++;
	}
}

void	ft_draw_minimap(t_data *data)
{
	t_move	*mv;
	t_map	*map;

	mv = &data->move;
	map = data->map;
	ft_draw_2d_map(data, mv, map);
}
