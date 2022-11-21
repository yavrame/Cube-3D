/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pharmund <pharmund@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 17:28:48 by pharmund          #+#    #+#             */
/*   Updated: 2022/10/13 17:28:49 by pharmund         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_key_down(int key_code, t_data *data)
{
	t_keys	*key;

	key = &data->keys;
	if (key_code == ESC)
		key->esc = 1;
	if (key_code == W)
		key->w = 1;
	if (key_code == D)
		key->d = 1;
	if (key_code == S)
		key->s = 1;
	if (key_code == A)
		key->a = 1;
	if (key_code == LEFT)
		key->left = 1;
	if (key_code == RIGHT)
		key->right = 1;
	if (key_code == PLUS)
		data->move.move_speed_val += 0.5;
	if (key_code == MIN)
		data->move.move_speed_val -= 0.5;
	return (1);
}

int	ft_key_up(int key_code, t_data *data)
{
	t_keys	*key;

	key = &data->keys;
	if (key_code == ESC)
		key->esc = 0;
	if (key_code == W)
		key->w = 0;
	if (key_code == D)
		key->d = 0;
	if (key_code == S)
		key->s = 0;
	if (key_code == A)
		key->a = 0;
	if (key_code == LEFT)
		key->left = 0;
	if (key_code == RIGHT)
		key->right = 0;
	return (1);
}

int	ft_key_hooks(t_data *data)
{
	t_keys	*key;

	key = &data->keys;
	if (key->esc == 1)
	{
		ft_game_msg("Quit\n");
		ft_free_exit(data);
	}
	if (key->w == 1)
		ft_move_up(data, &data->move);
	if (key->d == 1)
		ft_move_right(data, &data->move);
	if (key->s == 1)
		ft_move_down(data, &data->move);
	if (key->a == 1)
		ft_move_left(data, &data->move);
	if (key->left == 1)
		ft_rotate_left(data, &data->move);
	if (key->right == 1)
		ft_rotate_right(data, &data->move);
	return (1);
}
