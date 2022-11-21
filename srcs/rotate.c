/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pharmund <pharmund@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 17:30:08 by pharmund          #+#    #+#             */
/*   Updated: 2022/10/13 17:30:09 by pharmund         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/* rotation is calculated using rotation matrice */
void	ft_rotate_right(t_data *data, t_move *mv)
{
	double	dir_x_tmp;
	double	dir_y_tmp;
	double	plane_x_tmp;
	double	plane_y_tmp;
	double	rot_ang;

	(void)data;
	rot_ang = mv->rot_speed;
	dir_x_tmp = mv->dir_x;
	dir_y_tmp = mv->dir_y;
	mv->dir_x = dir_x_tmp * cos(rot_ang) - dir_y_tmp * sin(rot_ang);
	mv->dir_y = dir_y_tmp * cos(rot_ang) + dir_x_tmp * sin(rot_ang);
	plane_x_tmp = mv->plane_x;
	plane_y_tmp = mv->plane_y;
	mv->plane_x = plane_x_tmp * cos(rot_ang) - plane_y_tmp * sin(rot_ang);
	mv->plane_y = plane_y_tmp * cos(rot_ang) + plane_x_tmp * sin(rot_ang);
}

void	ft_rotate_left(t_data *data, t_move *mv)
{
	double	dir_x_tmp;
	double	dir_y_tmp;
	double	plane_x_tmp;
	double	plane_y_tmp;
	double	rot_ang;

	(void)data;
	rot_ang = mv->rot_speed;
	dir_x_tmp = mv->dir_x;
	dir_y_tmp = mv->dir_y;
	mv->dir_x = dir_x_tmp * cos(-rot_ang) - dir_y_tmp * sin(-rot_ang);
	mv->dir_y = dir_y_tmp * cos(-rot_ang) + dir_x_tmp * sin(-rot_ang);
	plane_x_tmp = mv->plane_x;
	plane_y_tmp = mv->plane_y;
	mv->plane_x = plane_x_tmp * cos(-rot_ang) - plane_y_tmp * sin(-rot_ang);
	mv->plane_y = plane_y_tmp * cos(-rot_ang) + plane_x_tmp * sin(-rot_ang);
}
