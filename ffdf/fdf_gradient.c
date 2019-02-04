/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_gradient.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dderevyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/01 18:08:11 by dderevyn          #+#    #+#             */
/*   Updated: 2019/02/04 16:26:53 by dderevyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int		fdf_get_color(int color0, int color1, double perc)
{
	return ((int)(perc * color1 + color0 * (1 - perc)));
}

static double	fdf_gradient_percent(int coord, int coord0, int coord1)
{
	double	pos;
	double	perc;
	double	dist;

	dist = coord1 - coord0;
	pos = coord - coord0;
	if (dist == 0)
		perc = 1.0;
	else
		perc = pos / dist;
	return (perc);
}

int				fdf_gradient(t_fdf_l2d l2d)
{
	int		r;
	int		g;
	int		b;
	double	perc;

	if (l2d.dx > l2d.dy)
		perc = fdf_gradient_percent(l2d.x, l2d.x0, l2d.x1);
	else
		perc = fdf_gradient_percent(l2d.y, l2d.y0, l2d.y1);
	r = fdf_get_color((l2d.color0 >> 16), (l2d.color1 >> 16), perc);
	g = fdf_get_color((l2d.color0 >> 8) & 255, (l2d.color1 >> 8) & 255, perc);
	b = fdf_get_color((l2d.color0) & 255, (l2d.color1) & 255, perc);
	return ((r << 16) | (g << 8) | b);
}

int				fdf_get_gradient(t_fdf_main main, int alt)
{
	int		r;
	int		g;
	int		b;
	double	percent;

	if (alt < 0)
		alt = -alt;
	percent = fdf_gradient_percent(alt, main.map_min_alt, main.map_max_alt);
	r = fdf_get_color((main.rgb0 >> 16), (main.rgb1 >> 16), percent);
	g = fdf_get_color((main.rgb0 >> 8) & 255, (main.rgb1 >> 8) & 255, percent);
	b = fdf_get_color(main.rgb0 & 255, main.rgb1 & 255, percent);
	return ((r << 16) | (g << 8) | b);
}

void			fdf_parse_gradient(t_fdf_main *main, char *line, int *i, int p)
{
	int r;
	int g;
	int b;

	if (line[(*i)] == ',' && line[(*i) + 1] == '0' && line[(*i) + 2] == 'x')
	{
		(*i) += 3;
		if (ft_strin(HEX, line[(*i)]))
			main->color[p] = ft_atoibase(HEX_CAP, &(line[(*i)]));
		else if (ft_strin(HEX_CAP, line[(*i)]))
			main->color[p] = ft_atoibase(HEX_CAP, &(line[(*i)]));
		while (ft_strin(HEX_CAP, line[(*i)]) || ft_strin(HEX, line[(*i)]))
			(*i)++;
		b = main->color[p] % 1000;
		main->color[p] = main->color[p] / 1000;
		g = main->color[p] % 1000;
		main->color[p] = main->color[p] / 1000;
		r = main->color[p] % 1000;
		main->color[p] = 0 | (r << 16) | (g << 8) | b;
		if (main->color[p] <= FDF_RGB_WHITE && main->color[p] >= FDF_RGB_BLACK)
			return ;
	}
	main->color[p] = -1;
}
