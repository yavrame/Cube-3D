/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_colors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pharmund <pharmund@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 17:29:29 by pharmund          #+#    #+#             */
/*   Updated: 2022/10/13 17:29:30 by pharmund         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_validate_color(char *color)
{
	char	**split;
	int		i;
	int		j;

	if (color == NULL || ft_strlen(color) == 0)
		return (0);
	split = ft_split(color, ',');
	if (!split)
		return (0);
	if (ft_splitlen(split) != 3)
		return (ft_free_split(split));
	i = -1;
	while (split[++i])
	{
		j = -1;
		while (split[i][++j])
		{
			if (split[i][j] != ' ' && !ft_isdigit(split[i][j]))
				return (ft_free_split(split));
		}
		if (ft_atoll(split[i]) < 0 || ft_atoll(split[i]) > 255)
			return (ft_free_split(split));
	}
	ft_free_split(split);
	return (1);
}

int	ft_set_color(char ***texture, const char *id, char *line)
{
	int		count;
	char	*trim;
	int		i;

	count = 0;
	i = -1;
	while (line[++i] != '\0' && line[i] != '\n')
	{
		if (line[i] == ',')
			++count;
	}
	if (count != 2)
		return (ft_memdel(line));
	trim = ft_strtrim(line, id);
	ft_memdel(line);
	if (**texture != NULL)
		return (ft_memdel(trim));
	(**texture) = ft_strtrim(trim, "\n");
	ft_memdel(trim);
	return (1);
}

static unsigned int	ft_str_to_inthex(char *str)
{
	unsigned int	hex;
	unsigned int	byte;
	int				i;

	hex = 0;
	i = 0;
	while (str[i])
	{
		byte = str[i];
		if (byte >= '0' && byte <= '9')
			byte = byte - '0';
		else if (byte >= 'a' && byte <= 'f')
			byte = byte - 'a' + 10;
		else if (byte >= 'A' && byte <= 'F')
			byte = byte - 'A' + 10;
		hex = hex << 4;
		hex |= byte;
		i++;
	}
	return (hex);
}

unsigned int	ft_convert_color(char *rgb)
{
	char			**split;
	char			*color;
	char			*itoa;
	int				i;
	unsigned int	num;

	split = ft_split(rgb, ',');
	color = malloc(sizeof(char) * 9);
	if (color == NULL)
		return (-1);
	color[0] = '\0';
	i = -1;
	while (split[++i])
	{
		itoa = ft_itoa_base(ft_atoi(split[i]), 16, 'u');
		ft_strcat(color, itoa);
		ft_memdel(itoa);
	}
	ft_free_split(split);
	num = ft_str_to_inthex(color);
	ft_memdel(color);
	return (num);
}
