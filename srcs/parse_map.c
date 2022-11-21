/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pharmund <pharmund@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 17:29:38 by pharmund          #+#    #+#             */
/*   Updated: 2022/10/13 17:29:39 by pharmund         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	**ft_map_cpy(int height, char **map)
{
	int		y;
	char	**map_tmp;

	map_tmp = (char **)malloc(sizeof(char *) * (height + 1));
	if (map_tmp == NULL)
		return (NULL);
	y = 0;
	while (map[y])
	{
		map_tmp[y] = ft_strdup(map[y]);
		y++;
	}
	map_tmp[y] = NULL;
	return (map_tmp);
}

static int	ft_get_height(int fd)
{
	int		i;
	char	*line;

	i = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		i++;
		free(line);
	}
	return (i);
}

static void	ft_search_map(int fd, char *map_line)
{
	char	*line;

	line = NULL;
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		if (ft_strcmp(line, map_line) == 0)
		{
			free(line);
			return ;
		}
		free(line);
	}
}

static void	ft_fill_map(t_map *map, int map_fd, char *line)
{
	int		i;
	size_t	len;

	i = 0;
	map->game_map[i++] = ft_strdup(line);
	map->width = (int)ft_strlen_nl(line);
	ft_memdel(line);
	while (1)
	{
		line = get_next_line(map_fd);
		if (line == NULL)
			break ;
		map->game_map[i] = ft_strdup(line);
		i++;
		len = (int)ft_strlen_nl(line);
		if (map->width < (int)len)
			map->width = len;
		free(line);
	}
	map->game_map[i] = NULL;
}

int	ft_parse_map(t_data *data, char *line, int fd, char *file)
{
	t_map	*map;
	int		map_fd;

	map = data->map;
	map->height = ft_get_height(fd) + 1;
	map->game_map = (char **)malloc(sizeof(char *) * (map->height + 1));
	if (map->game_map == NULL)
		return (0);
	map_fd = open(file, O_RDONLY);
	if (map_fd < 0)
		return (0);
	ft_search_map(map_fd, line);
	ft_fill_map(data->map, map_fd, line);
	if (!ft_check_map(map))
	{
		close(map_fd);
		return (0);
	}
	close(map_fd);
	return (1);
}
