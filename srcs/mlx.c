/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pharmund <pharmund@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 17:29:17 by pharmund          #+#    #+#             */
/*   Updated: 2022/10/13 17:29:18 by pharmund         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*pixel;

	pixel = data->addr + (y * data->size_line + x * (data->bpp / 8));
	*(unsigned int *)pixel = color;
}

void	ft_mlx(t_data *data)
{
	data->mlx = mlx_init();
	if (data->mlx == (void *)0)
		ft_exit_error("Error\nmlx_init failed\n");
	data->mlx_win = mlx_new_window(data->mlx, WIN_WIDTH, WIN_HEIGHT, GAME_NAME);
	if (data->mlx_win == (void *)0)
		ft_exit_error("Error\nmlx_window failed\n");
	if (!ft_set_textures(data, data->txtrs))
		ft_free_exit_msg(data, "Error\nFailed to open image\n");
	mlx_loop_hook(data->mlx, &ft_render, data);
	mlx_hook(data->mlx_win, 2, 1L << 0, &ft_key_down, data);
	mlx_hook(data->mlx_win, 3, 1L << 1, &ft_key_up, data);
	mlx_hook(data->mlx_win, 17, 0, &ft_free_exit, data);
	mlx_loop(data->mlx);
}
