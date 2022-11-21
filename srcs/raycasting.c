/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pharmund <pharmund@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 17:29:47 by pharmund          #+#    #+#             */
/*   Updated: 2022/10/13 17:29:48 by pharmund         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*	calculate ray position and direction */
/*
	@[map_x ; map_y]:
	coords of square with ray ->
	points where in this square is the ray
*/
void	ft_calc_ray_pos_dir(t_move *mv, int x)
{
	mv->camera_x = 2 * x / (double)WIN_WIDTH - 1;
	mv->ray_dir_x = mv->dir_x + mv->plane_x * mv->camera_x;
	mv->ray_dir_y = mv->dir_y + mv->plane_y * mv->camera_x;
	mv->map_x = (int)mv->pos_x;
	mv->map_y = (int)mv->pos_y;
}

/* 	calculate distance to next x or y side (next intersection) */
void	ft_calc_intersection_dist(t_move *mv)
{
	if (mv->ray_dir_x == 0)
		mv->delta_x = 1e30;
	else
		mv->delta_x = fabs(1 / mv->ray_dir_x);
	if (mv->ray_dir_y == 0)
		mv->delta_y = 1e30;
	else
		mv->delta_y = fabs(1 / mv->ray_dir_y);
}

void	ft_calc_step_first_intersect(t_move *mv)
{
	if (mv->ray_dir_x < 0)
	{
		mv->step_x = -1;
		mv->intersect_dist_x = (mv->pos_x - mv->map_x) * mv->delta_x;
	}
	else
	{
		mv->step_x = 1;
		mv->intersect_dist_x = (mv->map_x + 1.0 - mv->pos_x) * mv->delta_x;
	}
	if (mv->ray_dir_y < 0)
	{
		mv->step_y = -1;
		mv->intersect_dist_y = (mv->pos_y - mv->map_y) * mv->delta_y;
	}
	else
	{
		mv->step_y = 1;
		mv->intersect_dist_y = (mv->map_y + 1.0 - mv->pos_y) * mv->delta_y;
	}
}

/* digital differential algorithm */
/* move to the next x or y square */
void	ft_dda(t_move *mv, char **map)
{
	while (mv->is_wall == 0)
	{
		if (mv->intersect_dist_x < mv->intersect_dist_y)
		{
			mv->intersect_dist_x += mv->delta_x;
			mv->map_x += mv->step_x;
			mv->side = 0;
		}
		else
		{
			mv->intersect_dist_y += mv->delta_y;
			mv->map_y += mv->step_y;
			mv->side = 1;
		}
		if (map[mv->map_y][mv->map_x] == '1')
			mv->is_wall = 1;
	}
}

/* calculate perpendicular distance from camera plane to wall */
/* if side == 0 -> y_line was hit; if side == 1 -> x_line was hit*/
/* calculate height of line to draw on screen */
/* calculate lowest and highest pixel to fill in current stripe */
void	ft_calc_wall_dist_and_ray_height(t_move *mv)
{
	if (mv->side == 0)
	{
		mv->perp_wall_dist = mv->intersect_dist_x - mv->delta_x;
		if (mv->ray_dir_x > 0)
			mv->texture_num = EA;
		else
			mv->texture_num = WE;
	}
	else
	{
		mv->perp_wall_dist = mv->intersect_dist_y - mv->delta_y;
		if (mv->ray_dir_y > 0)
			mv->texture_num = SO;
		else
			mv->texture_num = NO;
	}
	mv->line_h = (int)(WIN_HEIGHT / mv->perp_wall_dist);
	mv->draw_start = (-1) * mv->line_h / 2 + WIN_HEIGHT / 2;
	if (mv->draw_start < 0)
		mv->draw_start = 0;
	mv->draw_end = mv->line_h / 2 + WIN_HEIGHT / 2;
	if (mv->draw_end >= WIN_HEIGHT)
		mv->draw_end = WIN_HEIGHT - 1;
}
