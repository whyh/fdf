/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_mouse_control.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dderevyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/03 21:27:49 by dderevyn          #+#    #+#             */
/*   Updated: 2019/02/04 10:47:02 by dderevyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	fdf_mouse_press(int button, int x, int y, void *param)
{
	t_fdf_ptr	*ptr;

	ptr = param;
	if (button == 4 && ptr->loop->lctrl == 1)
		fdf_zoom(-FDF_ZOOM_STEP, ptr);
	else if (button == 5 && ptr->loop->lctrl == 1)
		fdf_zoom(FDF_ZOOM_STEP, ptr);
	else if (button == 5 && ptr->loop->lcmd == 1)
		fdf_altitude(-FDF_ALT_MOD_STEP, ptr);
	else if (button == 4 && ptr->loop->lcmd == 1)
		fdf_altitude(FDF_ALT_MOD_STEP, ptr);
	else if (button == 1)
	{
		ptr->loop->lmouse = 1;
		ptr->loop->lmouse_x = x;
		ptr->loop->lmouse_y = y;
	}
	return (1);
}

int	fdf_mouse_move(int x, int y, void *param)
{
	t_fdf_ptr	*ptr;

	ptr = param;
	if (ptr->loop->lmouse == 1 && ptr->loop->lctrl == 1
		&& abs(x - ptr->main->offx) < 100 && abs(y - ptr->main->offy) < 100)
		fdf_move(x, y, ptr);
	return (1);
}

int	fdf_mouse_release(int button, int x, int y, void *param)
{
	t_fdf_ptr	*ptr;

	(void)x;
	(void)y;
	(void)button;
	ptr = param;
	ptr->loop->lmouse = 0;
	return (1);
}
