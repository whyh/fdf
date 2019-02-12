/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_parse.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dderevyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/30 11:19:49 by dderevyn          #+#    #+#             */
/*   Updated: 2019/02/12 11:09:04 by dderevyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	fdf_parse_map(t_fdf_main *main, char *line, int row)
{
	int	x;
	int i;

	x = 0;
	i = 0;
	main->p3d[row] = ft_memalloc(main->map_x * sizeof(int*));
	while (x < main->map_x && line[i])
	{
		if (line[i] == ' '
		|| (ft_strin(SIGNS, line[i]) && ft_strin(DEC, line[i + 1])))
			++i;
		if (ft_strin(DEC, line[i]))
		{
			main->p3d[row][x] = (int)ft_atoibase(DEC, &(line[i]));
			if (main->map_max_alt < main->p3d[row][x])
				main->map_max_alt = main->p3d[row][x];
			else if (main->map_min_alt > main->p3d[row][x])
				main->map_min_alt = main->p3d[row][x];
			while (ft_strin(DEC, line[i]))
				++i;
			fdf_parse_gradient(main, line, &i, ((row * main->map_x) + x));
			++x;
		}
	}
	fdf_complete_map(main, x, row);
}

static int	fdf_map_size(t_fdf_main *main, char const *line)
{
	int i;

	i = 0;
	while (line[i])
	{
		if (ft_strin(SIGNS, line[i]) && ft_strin(DEC, line[i + 1]))
			++i;
		if (ft_strin(DEC, line[i]))
		{
			main->map_x++;
			while (ft_strin(DEC, line[i]))
				++i;
			if (line[i] == ',' && line[i + 1] == '0' && line[i + 2] == 'x')
			{
				i += 3;
				while (ft_strin(HEX_CAP, line[i]) || ft_strin(HEX, line[i]))
					++i;
			}
		}
		if (line[i] && line[i] != ' ')
			return (0);
		if (line[i] == ' ')
			++i;
	}
	return (i);
}

static int	fdf_read_file(t_fdf_main *main, int fd)
{
	char	*line;

	while (ft_gnl(fd, &line))
	{
		if ((!line || !*line) && ft_printf("error: reading file failed\n"))
			return (0);
		if (main->map_y >= FDF_MAX_MAP || main->map_x >= FDF_MAX_MAP)
		{
			ft_printf("error: map is ridiculously big\n");
			ft_strdel(&line);
			return (0);
		}
		if (main->map_y == 0 && line[fdf_map_size(main, line)] != '\0')
		{
			ft_printf("error: map contains forbidden symbols\n");
			ft_strdel(&line);
			return (0);
		}
		fdf_parse_map(main, line, main->map_y++);
		ft_strdel(&line);
	}
	ft_strdel(&line);
	return (1);
}

static int	fdf_parse_rgb(t_fdf_main *main, char *rgb, int i)
{
	int r;
	int g;
	int b;

	if (rgb[9] != '~' || rgb[19] != '\0')
		return (0);
	while (i++ < 7)
		if (!ft_strin(DEC, rgb[i - 1]) || !ft_strin(DEC, rgb[i + 10]))
			return (0);
	main->rgb0 = (int)ft_atoibase(DEC, &(rgb[0]));
	b = main->rgb0 % 1000;
	main->rgb0 = main->rgb0 / 1000;
	g = main->rgb0 % 1000;
	main->rgb0 = main->rgb0 / 1000;
	r = main->rgb0 % 1000;
	main->rgb0 = 0 | (r << 16) | (g << 8) | b;
	main->rgb1 = (int)ft_atoibase(DEC, &(rgb[10]));
	b = main->rgb1 % 1000;
	main->rgb1 = main->rgb1 / 1000;
	g = main->rgb1 % 1000;
	main->rgb1 = main->rgb1 / 1000;
	r = main->rgb1 % 1000;
	main->rgb1 = 0 | (r << 16) | (g << 8) | b;
	return (1);
}

int			fdf_parse(char *filename, char *rgb, t_fdf_main *main)
{
	int	i;
	int	fd;

	if (!(fd = fdf_parse_init(main, filename)))
		return (0);
	if (!fdf_read_file(main, fd))
	{
		i = 0;
		while (main->p3d[i])
			ft_memdel((void**)(&(main->p3d[i++])));
		ft_memdel((void**)(main->p3d));
		close(fd);
		return (0);
	}
	close(fd);
	if (!rgb || !fdf_parse_rgb(main, rgb, 0) || main->rgb0 > FDF_RGB_WHITE
	|| main->rgb0 < 0 || main->rgb1 > FDF_RGB_WHITE || main->rgb1 < 0)
	{
		main->rgb0 = FDF_DEF_RGB0;
		main->rgb1 = FDF_DEF_RGB1;
		ft_printf("warning: wrong RGB format, RGB value set to default\n");
	}
	return (1);
}
