/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pharmund <pharmund@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 17:30:13 by pharmund          #+#    #+#             */
/*   Updated: 2022/10/13 17:30:14 by pharmund         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	ft_fill_textures_arr(t_data *data, t_texture *t, int i)
{
	t_map	*map;
	int		w;
	int		h;

	map = data->map;
	h = -1;
	while (++h < t[i].h)
	{
		w = -1;
		while (++w < t[i].w)
		{
			map->txtr_arr[i][t[i].h * h + w] = t[i].addr[t[i].h * h + w];
		}
	}
}

int	ft_set_textures(t_data *data, t_texture *t)
{
	int	i;

	i = -1;
	while (++i < 4)
	{
		if (i == NO)
			t[i].img = mlx_xpm_file_to_image(data->mlx, \
				(char *)data->elems->north_txtr, &(t[i].w), &(t[i].h));
		else if (i == EA)
			t[i].img = mlx_xpm_file_to_image(data->mlx, \
				(char *)data->elems->east_txtr, &(t[i].w), &(t[i].h));
		else if (i == SO)
			t[i].img = mlx_xpm_file_to_image(data->mlx, \
				(char *)data->elems->south_txtr, &(t[i].w), &(t[i].h));
		else if (i == WE)
			t[i].img = mlx_xpm_file_to_image(data->mlx, \
				(char *)data->elems->west_txtr, &(t[i].w), &(t[i].h));
		if (t[i].img == (void *)0)
			return (0);
		t[i].addr = (int *)mlx_get_data_addr(t[i].img, \
				&(t[i].bpp), &(t[i].size_line), &(t[i].endian));
		ft_fill_textures_arr(data, t, i);
	}
	return (1);
}
