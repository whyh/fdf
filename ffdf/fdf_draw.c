/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_draw.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dderevyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/30 16:25:46 by dderevyn          #+#    #+#             */
/*   Updated: 2019/02/04 14:12:52 by dderevyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	fdf_draw_line_x(t_fdf_l2d l2d, t_fdf_main main)
{
	l2d.dx = l2d.x1 - l2d.x0;
	l2d.dy = l2d.y1 - l2d.y0;
	l2d.sign = 1;
	if (l2d.dy < 0 && (l2d.sign = -1))
		l2d.dy *= -1;
	l2d.d = 2 * l2d.dy - l2d.dx;
	l2d.x = l2d.x0;
	l2d.y = l2d.y0;
	while (l2d.dy != 0 && l2d.x <= l2d.x1)
	{
		mlx_pixel_put(main.mlx, main.win,
		l2d.x++ + main.offx, l2d.y + main.offy, fdf_gradient(l2d));
		if (l2d.d > 0)
		{
			l2d.y += l2d.sign;
			l2d.d -= 2 * l2d.dx;
		}
		l2d.d = l2d.d + 2 * l2d.dy;
	}
	while (l2d.dy == 0 && l2d.x <= l2d.x1)
		mlx_pixel_put(main.mlx, main.win,
		l2d.x++ + main.offx, l2d.y + main.offy, fdf_gradient(l2d));
}

static void	fdf_draw_line_y(t_fdf_l2d l2d, t_fdf_main main)
{
	l2d.dx = l2d.x1 - l2d.x0;
	l2d.dy = l2d.y1 - l2d.y0;
	l2d.sign = 1;
	if (l2d.dx < 0 && (l2d.sign = -1))
		l2d.dx *= -1;
	l2d.d = 2 * l2d.dx - l2d.dy;
	l2d.y = l2d.y0;
	l2d.x = l2d.x0;
	while (l2d.dx != 0 && l2d.y <= l2d.y1)
	{
		mlx_pixel_put(main.mlx, main.win,
		l2d.x + main.offx, l2d.y++ + main.offy, fdf_gradient(l2d));
		if (l2d.d > 0)
		{
			l2d.x += l2d.sign;
			l2d.d -= 2 * l2d.dy;
		}
		l2d.d = l2d.d + 2 * l2d.dx;
	}
	while (l2d.dx == 0 && l2d.y <= l2d.y1)
		mlx_pixel_put(main.mlx, main.win,
		l2d.x + main.offx, l2d.y++ + main.offy, fdf_gradient(l2d));
}

static void	fdf_draw_line(t_fdf_p2d *p2d, t_fdf_main main, int i, t_fdf_l2d l2d)
{
	l2d.x1 = p2d->x[p2d->p + i];
	l2d.y1 = p2d->y[p2d->p + i];
	l2d.color1 = p2d->color[p2d->p + i];
	if (l2d.color0 != FDF_FLAGX && l2d.color1 != FDF_FLAGX
	&& ((abs(l2d.y1 - l2d.y0) < abs(l2d.x1 - l2d.x0) && l2d.x0 <= l2d.x1)
	|| (abs(l2d.y1 - l2d.y0) >= abs(l2d.x1 - l2d.x0) && l2d.y0 <= l2d.y1)))
	{
		if (abs(l2d.y1 - l2d.y0) < abs(l2d.x1 - l2d.x0))
			fdf_draw_line_x(l2d, main);
		else
			fdf_draw_line_y(l2d, main);
	}
	else if (l2d.color0 != FDF_FLAGX && l2d.color1 != FDF_FLAGX)
	{
		l2d.x1 = p2d->x[p2d->p];
		l2d.y1 = p2d->y[p2d->p];
		l2d.color1 = p2d->color[p2d->p];
		l2d.x0 = p2d->x[p2d->p + i];
		l2d.y0 = p2d->y[p2d->p + i];
		l2d.color0 = p2d->color[p2d->p + i];
		if (abs(l2d.y1 - l2d.y0) < abs(l2d.x1 - l2d.x0))
			fdf_draw_line_x(l2d, main);
		else
			fdf_draw_line_y(l2d, main);
	}
}

void		fdf_draw(t_fdf_p2d *p2d, t_fdf_main main)
{
	int			length;
	t_fdf_l2d	l2d;

	p2d->p = 0;
	length = main.map_x;
	while (p2d->p < p2d->quant)
	{
		l2d.x0 = p2d->x[p2d->p];
		l2d.y0 = p2d->y[p2d->p];
		l2d.color0 = p2d->color[p2d->p];
		if (length-- > 1)
			fdf_draw_line(p2d, main, 1, l2d);
		if (main.map_y > 1)
			fdf_draw_line(p2d, main, main.map_x, l2d);
		if (length == 0)
		{
			main.map_y--;
			length = main.map_x;
		}
		p2d->p++;
	}
}
