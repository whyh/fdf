/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_key_control.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dderevyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/03 21:29:02 by dderevyn          #+#    #+#             */
/*   Updated: 2019/02/04 19:48:05 by dderevyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	fdf_key_press2(int keycode, t_fdf_ptr *ptr)
{
	if (keycode == 15)
	{
		if (ptr->loop->keyr == 0)
			ptr->loop->keyr = 1;
		else if (ptr->loop->keyr == 1)
			ptr->loop->keyr = 0;
		if (ptr->p2d->alt_mod != 0)
			fdf_altitude(1, ptr);
	}
}

int			fdf_key_press(int keycode, void *param)
{
	t_fdf_ptr	*ptr;

	ptr = param;
	if (keycode == 53)
		exit(0);
	else if (keycode == 256)
		ptr->loop->lctrl = 1;
	else if (keycode == 259)
		ptr->loop->lcmd = 1;
	else if (keycode == 18 || keycode == 19 || keycode == 20 || keycode == 21)
		fdf_project(keycode, ptr, 1);
	else if (keycode == 4 && ptr->loop->keyh == 0)
	{
		ptr->loop->keyh = 1;
		fdf_project(0, ptr, 0);
	}
	fdf_key_press2(keycode, ptr);
	return (1);
}

int			fdf_key_release(int keycode, void *param)
{
	t_fdf_ptr	*ptr;

	ptr = param;
	if (keycode == 256)
		ptr->loop->lctrl = 0;
	else if (keycode == 259)
		ptr->loop->lcmd = 0;
	else if (keycode == 4 && ptr->loop->keyh == 1)
	{
		ptr->loop->keyh = 0;
		fdf_project(0, ptr, 0);
	}
	return (1);
}
