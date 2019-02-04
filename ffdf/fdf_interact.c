/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_interact.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dderevyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/03 21:24:39 by dderevyn          #+#    #+#             */
/*   Updated: 2019/02/04 15:10:57 by dderevyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	fdf_p3d_to_p2d(t_fdf_main *main, t_fdf_p2d *p2d)
{
	int i;
	int row;
	int col;

	row = 0;
	i = 0;
	while (row < main->map_y)
	{
		col = 0;
		while (col < main->map_x)
		{
			p2d->x[i] = col;
			p2d->y[i] = row;
			p2d->z[i] = main->p3d[row][col];
			if (main->color[i] == FDF_FLAGX || (main->color[i] >= FDF_RGB_BLACK
			&& main->color[i] <= FDF_RGB_WHITE))
				p2d->color[i] = main->color[i];
			else
				p2d->color[i] = fdf_get_gradient(*main, main->p3d[row][col]);
			++col;
			++i;
		}
		++row;
	}
	p2d->quant = i;
}

void		fdf_zoom(int step, t_fdf_ptr *ptr)
{
	ptr->p2d->padd += step;
	if (ptr->p2d->padd < 1)
		ptr->p2d->padd = 1;
	else if (ptr->p2d->padd > 50)
		ptr->p2d->padd = 50;
	fdf_p3d_to_p2d(ptr->main, ptr->p2d);
	ptr->projs[ptr->main->curr_proj](ptr->p2d);
	fdf_compose_slide(ptr);
}

void		fdf_move(int x, int y, t_fdf_ptr *ptr)
{
	ptr->main->offy = y;
	ptr->main->offx = x;
	if (ptr->main->offx > FDF_WIN_X - 50)
		ptr->main->offx = FDF_WIN_X - 50;
	else if (ptr->main->offx < 50)
		ptr->main->offx = 50;
	if (ptr->main->offy > FDF_WIN_Y - 50)
		ptr->main->offy = FDF_WIN_Y - 50;
	else if (ptr->main->offy < 0)
		ptr->main->offy = 0;
	fdf_compose_slide(ptr);
}

void		fdf_altitude(int step, t_fdf_ptr *ptr)
{
	if (step < 0)
	{
		step = -step;
		if (ptr->p2d->alt_mod / step >= 0)
			ptr->p2d->alt_mod /= step;
	}
	else if (step > 0)
	{
		if (ptr->p2d->alt_mod == 0)
			ptr->p2d->alt_mod = FDF_ALT_MOD;
		if (ptr->p2d->alt_mod * step < FDF_ALT_RANGE)
			ptr->p2d->alt_mod *= step;
	}
	fdf_p3d_to_p2d(ptr->main, ptr->p2d);
	ptr->projs[ptr->main->curr_proj](ptr->p2d);
	fdf_compose_slide(ptr);
}

void		fdf_project(int keycode, t_fdf_ptr *ptr)
{
	if (keycode != 0)
		ptr->main->curr_proj = keycode;
	if (!(ptr->loop) || ptr->loop->keyh == 0)
	{
		ptr->main->offx = FDF_OFF_X;
		ptr->main->offy = FDF_OFF_Y;
		ptr->p2d->padd = FDF_P_PADD;
		ptr->p2d->alt_mod = FDF_ALT_MOD;
		fdf_p3d_to_p2d(ptr->main, ptr->p2d);
		ptr->projs[ptr->main->curr_proj](ptr->p2d);
	}
	fdf_compose_slide(ptr);
}
