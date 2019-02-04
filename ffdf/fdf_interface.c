/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_interface.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dderevyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/03 19:27:02 by dderevyn          #+#    #+#             */
/*   Updated: 2019/02/03 21:36:23 by dderevyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	fdf_inf(t_fdf_ptr *ptr)
{
	mlx_string_put(ptr->main->mlx, ptr->main->win, FDF_WIN_X - 150,
	FDF_WIN_Y - 30, FDF_RGB_FONT, "use H for help");
	if (ptr->main->curr_proj == 18)
		mlx_string_put(ptr->main->mlx, ptr->main->win, 10, 5, FDF_RGB_FONT,
		"iso");
	else if (ptr->main->curr_proj == 19)
		mlx_string_put(ptr->main->mlx, ptr->main->win, 10, 5, FDF_RGB_FONT,
		"iso 2:1");
	else if (ptr->main->curr_proj == 20)
		mlx_string_put(ptr->main->mlx, ptr->main->win, 10, 5, FDF_RGB_FONT,
		"top view");
	else if (ptr->main->curr_proj == 21)
		mlx_string_put(ptr->main->mlx, ptr->main->win, 10, 5, FDF_RGB_FONT,
		"side view");
	else if (ptr->main->curr_proj == 22)
		mlx_string_put(ptr->main->mlx, ptr->main->win, 10, 5, FDF_RGB_FONT,
		"side view");
}

static void	fdf_background(t_fdf_ptr *ptr)
{
	int		size_line;
	int		i;
	int		*img;

	if (ptr->imgs->imgb == NULL)
	{
		ptr->imgs->imgb = mlx_new_image(ptr->main->mlx, FDF_WIN_X, FDF_WIN_Y);
		img = (int*)mlx_get_data_addr(ptr->imgs->imgb, &i, &size_line, &i);
		i = FDF_WIN_X * FDF_WIN_Y;
		while (i-- > 0)
			*img++ = FDF_RGB_BG;
	}
	mlx_put_image_to_window(ptr->main->mlx, ptr->main->win, ptr->imgs->imgb, 0,
							0);
}

void		fdf_compose_slide(t_fdf_ptr *ptr)
{
	mlx_clear_window(ptr->main->mlx, ptr->main->win);
	fdf_background(ptr);
	fdf_draw(ptr->p2d, *(ptr->main));
	fdf_inf(ptr);
}
