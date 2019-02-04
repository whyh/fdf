/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_help_menu.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dderevyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/03 14:13:04 by dderevyn          #+#    #+#             */
/*   Updated: 2019/02/04 13:45:06 by dderevyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	fdf_help_bg(t_fdf_ptr *ptr)
{
	int		size_line;
	int		i;
	int		row;
	int		*img;

	if (ptr->imgs->imgh == NULL)
	{
		ptr->imgs->imgh = mlx_new_image(ptr->main->mlx, FDF_H_MENU_X,
		FDF_H_MENU_Y);
		img = (int*)mlx_get_data_addr(ptr->imgs->imgh, &i, &size_line, &i);
		i = FDF_H_MENU_X * FDF_H_MENU_Y;
		row = 0;
		while (i-- > 0)
		{
			if ((row > 15 && row < 30) || (row > 45 && row < 60)
			|| (row > 80 && row < 95))
				*img++ = FDF_RGB_BG;
			else
				*img++ = FDF_H_MENU_BG;
			if (i % size_line == 0)
				++row;
		}
	}
	mlx_put_image_to_window(ptr->main->mlx, ptr->main->win, ptr->imgs->imgh,
	FDF_H_MENU_POS_X, FDF_H_MENU_POS_Y);
}

static void	fdf_help_text2(t_fdf_main main, int i)
{
	mlx_string_put(main.mlx, main.win, FDF_LINE_PADD_X, FDF_WIN_Y / 5 +
	(i += FDF_LINE_PADD_Y + 5), FDF_H_MENU_FONT, "drag top left");
	mlx_string_put(main.mlx, main.win, FDF_LINE_PADD_X, FDF_WIN_Y / 5 +
	(i += FDF_LINE_PADD_Y + 5), FDF_H_MENU_FONT, "corner of image with mouse");
	mlx_string_put(main.mlx, main.win, FDF_LINE_PADD_X,
	FDF_WIN_Y / 5 + (i += FDF_LINE_PADD_Y + 5), FDF_H_MENU_FONT, "with mouse");
}

static void	fdf_help_text(t_fdf_main main, int i)
{
	mlx_string_put(main.mlx, main.win, FDF_LINE_PADD_X,
	FDF_WIN_Y / 5 + (i += 0), FDF_H_MENU_FONT, "use keys 1 - 9");
	mlx_string_put(main.mlx, main.win, FDF_LINE_PADD_X,
	FDF_WIN_Y / 5 + (i += FDF_LINE_PADD_Y), FDF_H_MENU_FONT, "to swap between");
	mlx_string_put(main.mlx, main.win, FDF_LINE_PADD_X,
	FDF_WIN_Y / 5 + (i += FDF_LINE_PADD_Y), FDF_H_MENU_FONT, "projections");
	mlx_string_put(main.mlx, main.win, FDF_LINE_PADD_X,
	FDF_WIN_Y / 5 + (i += FDF_SEP_PADD + 5), FDF_H_MENU_FONT, "to change");
	mlx_string_put(main.mlx, main.win, FDF_LINE_PADD_X,
	FDF_WIN_Y / 5 + (i += FDF_LINE_PADD_Y), FDF_H_MENU_FONT, "altitude hold");
	mlx_string_put(main.mlx, main.win, FDF_LINE_PADD_X,
	FDF_WIN_Y / 5 + (i += FDF_LINE_PADD_Y), FDF_H_MENU_FONT, "CMD and scroll");
	mlx_string_put(main.mlx, main.win, FDF_LINE_PADD_X,
	FDF_WIN_Y / 5 + (i += FDF_SEP_PADD + 3), FDF_H_MENU_FONT, "you also can");
	mlx_string_put(main.mlx, main.win, FDF_LINE_PADD_X,
	FDF_WIN_Y / 5 + (i += FDF_LINE_PADD_Y), FDF_H_MENU_FONT, "zoom in and out");
	mlx_string_put(main.mlx, main.win, FDF_LINE_PADD_X,
	FDF_WIN_Y / 5 + (i += FDF_LINE_PADD_Y), FDF_H_MENU_FONT, "by holding CTRL");
	mlx_string_put(main.mlx, main.win, FDF_LINE_PADD_X, FDF_WIN_Y / 5 +
	(i += FDF_LINE_PADD_Y + 1), FDF_H_MENU_FONT, "and scrolling");
	mlx_string_put(main.mlx, main.win, FDF_LINE_PADD_X,
	FDF_WIN_Y / 5 + (i += FDF_SEP_PADD + 5), FDF_H_MENU_FONT, "to move image");
	mlx_string_put(main.mlx, main.win, FDF_LINE_PADD_X, FDF_WIN_Y / 5 +
	(i += FDF_LINE_PADD_Y + 5), FDF_H_MENU_FONT, "hold CTRL and");
	fdf_help_text2(main, i);
}

void		fdf_help_menu(t_fdf_ptr *ptr)
{
	fdf_help_bg(ptr);
	fdf_help_text(*(ptr->main), 0);
}
