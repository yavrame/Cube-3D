/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_identifiers.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pharmund <pharmund@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 17:29:33 by pharmund          #+#    #+#             */
/*   Updated: 2022/10/13 17:29:34 by pharmund         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	ft_set_identifier(char **texture, const char *id, char *line)
{
	char	*trim;
	char	**split;

	trim = ft_strtrim(line, " ");
	if (!trim)
		return (0);
	if (ft_strcmp(id, "F") == 0 || ft_strcmp(id, "C") == 0)
		return (ft_set_color(&texture, id, trim));
	split = ft_split(trim, ' ');
	if (ft_splitlen(split) != 2 || ft_strcmp(split[0], id) != 0)
	{
		ft_memdel(trim);
		ft_free_split(split);
		return (0);
	}
	ft_memdel(trim);
	trim = ft_strtrim(split[1], "\n");
	ft_free_split(split);
	if (*texture != NULL)
		return (ft_memdel(trim));
	*texture = ft_strdup(trim);
	ft_memdel(trim);
	return (1);
}

int	ft_get_identifier(t_element *elem, char *line)
{
	if (ft_strnstr(line, "NO", ft_strlen(line)))
		return (ft_set_identifier((void *)&(elem->north_txtr), "NO", line));
	else if (ft_strnstr(line, "SO", ft_strlen(line)))
		return (ft_set_identifier((void *)&(elem->south_txtr), "SO", line));
	else if (ft_strnstr(line, "WE", ft_strlen(line)))
		return (ft_set_identifier((void *)&(elem->west_txtr), "WE", line));
	else if (ft_strnstr(line, "EA", ft_strlen(line)))
		return (ft_set_identifier((void *)&(elem->east_txtr), "EA", line));
	else if (ft_strnstr(line, "F", ft_strlen(line)))
		return (ft_set_identifier((void *)&(elem->floor_clr), "F", line));
	else if (ft_strnstr(line, "C", ft_strlen(line)))
		return (ft_set_identifier((void *)&(elem->ceiling_clr), "C", line));
	return (-1);
}

static int	ft_open_texture(char *texture)
{
	int	fd;

	if (texture == NULL)
		return (0);
	fd = open(texture, O_RDONLY);
	if (fd < 0)
		return (0);
	close(fd);
	return (1);
}

int	ft_check_identifiers(t_element *elem)
{
	if (!ft_open_texture(elem->north_txtr))
		return (0);
	if (!ft_open_texture(elem->south_txtr))
		return (0);
	if (!ft_open_texture(elem->east_txtr))
		return (0);
	if (!ft_open_texture(elem->west_txtr))
		return (0);
	if (!ft_validate_color(elem->floor_clr))
		return (0);
	if (!ft_validate_color(elem->ceiling_clr))
		return (0);
	return (1);
}
