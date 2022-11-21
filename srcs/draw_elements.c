/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_elements.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pharmund <pharmund@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 17:27:36 by pharmund          #+#    #+#             */
/*   Updated: 2022/10/13 17:27:37 by pharmund         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_draw_bg_ceiling(t_data *data)
{
	int	x;
	int	y;

	y = -1;
	while (++y < WIN_HEIGHT / 2)
	{
		x = -1;
		while (++x < WIN_WIDTH)
			ft_mlx_pixel_put(data, x, y, data->map->ceiling);
	}
	while (y < WIN_HEIGHT)
	{
		x = -1;
		while (++x < WIN_WIDTH)
			ft_mlx_pixel_put(data, x, y, data->map->floor);
		y++;
	}
}

/*calculate value where the wall was hit*/
static int	ft_get_texture_pos_x(t_move *mv)
{
	double	wall_x;
	int		txtr_x;

	wall_x = 0.0;
	if (mv->side == 0)
		wall_x = mv->pos_y + mv->perp_wall_dist * mv->ray_dir_y;
	else
		wall_x = mv->pos_x + mv->perp_wall_dist * mv->ray_dir_x;
	wall_x -= floor(wall_x);
	txtr_x = (int)(wall_x * (double)WALL_SIZE);
	if (mv->side == 0 && mv->ray_dir_x > 0)
		txtr_x = WALL_SIZE - txtr_x - 1;
	if (mv->side == 1 && mv->ray_dir_y < 0)
		txtr_x = WALL_SIZE - txtr_x - 1;
	return (txtr_x);
}

void	ft_draw_ray(t_data *data, t_move *mv, int x)
{
	double	step;
	int		y;
	int		txtr_y;
	int		txtr_x;
	double	tex_pos;

	txtr_x = ft_get_texture_pos_x(mv);
	step = 1.0 * WALL_SIZE / mv->line_h;
	tex_pos = (mv->draw_start - WIN_HEIGHT / 2 + mv->line_h / 2) * step;
	y = mv->draw_start - 1;
	while (++y < mv->draw_end)
	{
		txtr_y = (int)tex_pos & (WALL_SIZE - 1);
		tex_pos += step;
		ft_mlx_pixel_put(data, x, y, \
		data->map->txtr_arr[mv->texture_num][WALL_SIZE * txtr_y + txtr_x]);
	}
}
