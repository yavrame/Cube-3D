/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pharmund <pharmund@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 17:29:42 by pharmund          #+#    #+#             */
/*   Updated: 2022/10/13 17:29:43 by pharmund         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_check_ext(char *file)
{
	char	*dot;

	dot = ft_strrchr(file, '.');
	if (dot == NULL)
		return (0);
	if (ft_strcmp(dot, ".cub") == 0)
		return (1);
	return (0);
}

static char	*ft_get_info(t_data *data, int fd, int *count_ids)
{
	char	*line;
	int		res;

	line = NULL;
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		if (ft_strcmp(line, "\n") != 0)
		{
			res = ft_get_identifier(data->elems, line);
			if (res == -1)
				return (line);
			else if (res == 0)
			{
				free(line);
				return (NULL);
			}
			else
				*count_ids += 1;
		}
		free(line);
	}
	return (NULL);
}

void	ft_parse_file(t_data *data, char *file)
{
	int			fd;
	char		*line;
	int			count_ids;

	if (!ft_check_ext(file))
		ft_exit_error("Error\nInvalid map extension\n");
	fd = open(file, O_RDONLY);
	if (fd < 0)
		ft_exit_error("Error\nOpening file\n");
	count_ids = 0;
	line = ft_get_info(data, fd, &count_ids);
	if (line == NULL || !ft_check_identifiers(data->elems) || count_ids != 6)
	{
		close(fd);
		ft_free_exit_msg(data, "Error\nInvalid identifiers\n");
	}
	if (!ft_parse_map(data, line, fd, file))
	{
		close(fd);
		ft_free_exit_msg(data, "Error\nInvalid map\n");
	}
	close(fd);
}
