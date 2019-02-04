/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_key_control.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dderevyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/03 21:29:02 by dderevyn          #+#    #+#             */
/*   Updated: 2019/02/03 22:02:29 by dderevyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	fdf_key_press(int keycode, void *param)
{
	t_fdf_ptr	*ptr;

	ptr = param;
	if (keycode == 53)
		exit(0);
	else if (keycode == 256)
		ptr->loop->lctrl = 1;
	else if (keycode == 259)
		ptr->loop->lcmd = 1;
	else if (keycode >= 18 && keycode <= 21)
		fdf_project(keycode, ptr);
	else if (keycode == 4)
	{
		ptr->loop->keyh = 1;
		fdf_help_menu(ptr);
	}
	return (1);
}

int	fdf_key_release(int keycode, void *param)
{
	t_fdf_ptr	*ptr;

	ptr = param;
	if (keycode == 256)
		ptr->loop->lctrl = 0;
	else if (keycode == 259)
		ptr->loop->lcmd = 0;
	else if (keycode == 4)
	{
		fdf_project(0, ptr);
		ptr->loop->keyh = 0;
	}
	return (1);
}
