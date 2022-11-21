/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pharmund <pharmund@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 17:27:25 by pharmund          #+#    #+#             */
/*   Updated: 2022/10/13 17:27:26 by pharmund         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	ft_set_player_pos(t_map *map, int x, int y, int *p)
{
	map->player_x = x;
	map->player_y = y;
	map->player_dir = map->game_map[y][x];
	map->game_map[y][x] = '0';
	*p += 1;
}

static int	ft_check_eachchar(t_map *map, char **map_game)
{
	int	x;
	int	y;
	int	ground;
	int	player;

	y = -1;
	ground = 0;
	player = 0;
	while (map_game[++y])
	{
		x = 0;
		while (map_game[y][x] != '\0' && map_game[y][x] != '\n')
		{
			if (map_game[y][x] == '0' || map_game[y][x] == '1')
				ground++;
			if (map_game[y][x] == 'N' || map_game[y][x] == 'S' || \
				map_game[y][x] == 'W' || map_game[y][x] == 'E')
				ft_set_player_pos(map, x, y, &player);
			x++;
		}
	}
	if (ground == 0 || player != 1)
		return (0);
	return (1);
}

static int	ft_check_chars(char **map, const char *set)
{
	int		x;
	int		y;
	char	*trim;

	y = 0;
	while (map[y])
	{
		x = 0;
		trim = ft_strtrim(map[y], " ");
		if (ft_strcmp(trim, "\n") == 0)
			return (ft_memdel(trim));
		while (map[y][x] != '\0' && map[y][x] != '\n')
		{
			if (ft_strchr(set, map[y][x]) == NULL)
				return (ft_memdel(trim));
			x++;
		}
		ft_memdel(trim);
		y++;
	}
	return (1);
}

/*flood fill algorithm*/
void	ft_check_walls(int px, int py, char **map_tmp, int *check)
{
	if (px < 0 || py < 0)
		return ;
	if (!map_tmp[py][px] || map_tmp[py][px] == ' ' || map_tmp[py][px] == '\n')
	{
		*check = 0;
		return ;
	}
	if (map_tmp[py][px] == '1' || map_tmp[py][px] == 'F')
		return ;
	map_tmp[py][px] = 'F';
	ft_check_walls(px, py - 1, map_tmp, check);
	ft_check_walls(px, py + 1, map_tmp, check);
	ft_check_walls(px - 1, py, map_tmp, check);
	ft_check_walls(px + 1, py, map_tmp, check);
	return ;
}

int	ft_check_map(t_map *map)
{
	char	**map_tmp;
	int		check;

	if (!ft_check_chars(map->game_map, "01NSWE "))
		return (0);
	if (!ft_check_eachchar(map, map->game_map))
		return (0);
	map_tmp = ft_map_cpy(map->height, map->game_map);
	check = 1;
	ft_check_walls(map->player_x, map->player_y, map_tmp, &check);
	if (check == 0)
	{
		ft_free_split(map_tmp);
		return (0);
	}
	ft_free_split(map_tmp);
	return (1);
}
