/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pharmund <pharmund@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 17:29:53 by pharmund          #+#    #+#             */
/*   Updated: 2022/10/13 17:29:54 by pharmund         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

double	ft_deg_to_rad(int ang)
{
	return (ang * PI / 180);
}

static void	ft_draw_loop(t_data *data)
{
	int	x;

	x = 0;
	while (x < WIN_WIDTH)
	{
		ft_calc_ray_pos_dir(&data->move, x);
		ft_calc_intersection_dist(&data->move);
		data->move.is_wall = 0;
		ft_calc_step_first_intersect(&data->move);
		ft_dda(&data->move, data->map->game_map);
		ft_calc_wall_dist_and_ray_height(&data->move);
		ft_draw_ray(data, &data->move, x);
		x++;
	}
}

int	ft_render(t_data *data)
{
	data->mlx_img = mlx_new_image(data->mlx, WIN_WIDTH, WIN_HEIGHT);
	data->addr = mlx_get_data_addr(data->mlx_img, &data->bpp, \
									&data->size_line, &data->endian);
	ft_draw_bg_ceiling(data);
	ft_draw_loop(data);
	ft_key_hooks(data);
	ft_draw_minimap(data);
	if (data->move.move_speed_val < 1.5 || data->move.move_speed_val > 6.0)
		data->move.move_speed_val = 1.5;
	data->move.move_speed = (double)(60 / 1000.0 * data->move.move_speed_val);
	data->move.rot_speed_val = ft_deg_to_rad(30);
	data->move.rot_speed = (double)(60 / 1000.0 * data->move.rot_speed_val);
	mlx_put_image_to_window(data->mlx, data->mlx_win, data->mlx_img, 0, 0);
	mlx_destroy_image(data->mlx, data->mlx_img);
	return (1);
}
