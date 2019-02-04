/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_projections.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dderevyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/30 17:16:55 by dderevyn          #+#    #+#             */
/*   Updated: 2019/02/04 20:21:54 by dderevyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	fdf_projection_iso(t_fdf_p2d *p2d)
{
	int i;
	int x;
	int y;

	i = 0;
	while (i < p2d->quant)
	{
		x = (int)(((p2d->x[i] - p2d->y[i]) * p2d->padd) * cos(RAD * 30));
		y = (int)(((p2d->x[i] + p2d->y[i]) * p2d->padd) * sin(RAD * 30))
		- (p2d->z[i] * p2d->alt_mod);
		p2d->x[i] = x;
		p2d->y[i] = y;
		++i;
	}
}

void	fdf_projection_iso_2_1(t_fdf_p2d *p2d)
{
	int i;
	int x;
	int y;

	i = 0;
	while (i < p2d->quant)
	{
		x = (int)(((p2d->x[i] - p2d->y[i]) * p2d->padd) * cos(RAD * 26.57));
		y = (int)(((p2d->x[i] + p2d->y[i]) * p2d->padd) * sin(RAD * 26.57))
		- (p2d->z[i] * p2d->alt_mod);
		p2d->x[i] = x;
		p2d->y[i] = y;
		++i;
	}
}

void	fdf_projection_top(t_fdf_p2d *p2d)
{
	int i;

	i = 0;
	while (i < p2d->quant)
	{
		p2d->x[i] *= p2d->padd * 2;
		p2d->y[i] *= p2d->padd * 2;
		++i;
	}
}

void	fdf_projection_side(t_fdf_p2d *p2d)
{
	int i;

	i = 0;
	while (i < p2d->quant)
	{
		p2d->x[i] = (p2d->x[i] * p2d->padd * 2);
		p2d->y[i] = (int)((p2d->y[i] * p2d->padd * cos(RAD * 90)) * -1)
		- (p2d->z[i] * p2d->alt_mod * 4);
		++i;
	}
}
