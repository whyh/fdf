/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_parse_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dderevyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/30 11:19:49 by dderevyn          #+#    #+#             */
/*   Updated: 2019/01/30 16:11:28 by dderevyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	fdf_parse_map(t_fdf_map *map, char *line, size_t row)
{
	size_t	i;
	size_t	m;

	map->matrix[row] = ft_memalloc(map->matrix_length * sizeof(int*));
	i = 0;
	m = 0;
	while (m < map->matrix_length && line[i])
	{
		if (line[i] != ' ')
		{
			if ((map->matrix[row][m] = ft_atoi(&(line[i]))) > FDF_MAX_ALTITUDE ||
			map->matrix[row][m] < FDF_MAX_ALTITUDE * -1)
			{
				ft_printf("error: unsupported value of altitude(%d)", map->matrix[row][m]);
				return (0);
			}
			if (map->matrix_max_altitude < map->matrix[row][m])
				map->matrix_max_altitude = map->matrix[row][m];
			while (line[i] && line[i] != ' ')
				++i;
			++m;
		}
		++i;
	}
	if (m != map->matrix_length)
	{
		ft_printf("error: map has wrong length of line %d\n", row);
		return (0);
	}
	return (1);
}


static int	fdf_map_size(t_fdf_map *map, char const *line)
{
	int		i;
	size_t	length;

	i = 0;
	length = 0;
	while (line[i])
	{
		if ((line[i] >= '0' && line[i] <= '9')
		|| ((line[i] == '+' || line[i] == '-')
		&& line[i + 1] >= '0' && line[i + 1] <= '9'))
		{
			++length;
			if (line[i] == '+' || line[i] == '-')
				++i;
			while (line[i] >= '0' && line[i] <= '9')
				++i;
		}
		else if (line[i] && line[i] != ' ' && line[i] != '\n')
		{
			ft_printf("error: map contains forbidden symbols\n");
			return (0);
		}
		if (line[i] != '\0')
			++i;
	}
	map->matrix_length = length;
	return (1);
}


static int	fdf_read_file(t_fdf_map *map, int fd)
{
	char	*line;

	map->matrix_heigth = 0;
	while (ft_gnl(fd, &line))
	{
		if (map->matrix_heigth > FDF_MAX_MAP_ROWS)
		{
			ft_printf("error: map is ridiculously big\n");
			ft_strdel(&line);
			return (0);
		}
		if (map->matrix_heigth == 0 && !fdf_map_size(map, line))
		{
			ft_strdel(&line);
			return (0);
		}
		if (!fdf_parse_map(map, line, map->matrix_heigth))
		{
			ft_strdel(&line);
			return (0);
		}
		ft_strdel(&line);
		++(map->matrix_heigth);
	}
	ft_strdel(&line);
	return (1);
}

int			fdf_get_matrix(char *filename, t_fdf_map *map)
{
	int		fd;
	size_t	i;

	map->matrix_max_altitude = 0;
	if ((fd = open(filename, O_RDONLY)) < 1)
	{
		ft_printf("error: can't open file\n");
		return (0);
	}
	map->matrix = ft_memalloc(FDF_MAX_MAP_ROWS * sizeof(int**));
	if (!fdf_read_file(map, fd))
	{
		i = 0;
		while (map->matrix[i])
		{
			ft_memdel((void**)(&(map->matrix[i])));
			++i;
		}
		ft_memdel((void**)(map->matrix));
		return (0);
	}
	return (1);
}
