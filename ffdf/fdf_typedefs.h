/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_typedefs.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dderevyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/30 11:36:39 by dderevyn          #+#    #+#             */
/*   Updated: 2019/02/04 15:28:05 by dderevyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_TYPEDEFS_H
# define FDF_TYPEDEFS_H

# define FDF_MAX_MAP 1000
# define FDF_ALT_RANGE 1000
# define FDF_WIN_Y 1000
# define FDF_WIN_X 1500
# define FDF_OFF_X FDF_WIN_X / 2
# define FDF_OFF_Y FDF_WIN_Y / 2
# define FDF_P_PADD 10
# define FDF_H_MENU_X 165
# define FDF_H_MENU_Y 500
# define FDF_H_MENU_POS_X 5
# define FDF_H_MENU_POS_Y FDF_WIN_Y / 5
# define FDF_RGB_BG 2105376
# define FDF_DEF_RGB0 10066176
# define FDF_DEF_RGB1 9972992
# define FDF_RGB_FONT FDF_DEF_RGB1
# define FDF_H_MENU_BG FDF_DEF_RGB0
# define FDF_H_MENU_FONT FDF_RGB_BG
# define FDF_ZOOM_STEP 1
# define FDF_LINE_PADD_Y 18
# define FDF_SEP_PADD 80
# define FDF_LINE_PADD_X 12
# define FDF_ALT_MOD 1
# define FDF_ALT_MOD_STEP 2
# define FDF_RGB_WHITE 16777215
# define FDF_FLAGX -10
# define FDF_RGB_BLACK 0

typedef struct	s_fdf_main{
	void		*mlx;
	void		*win;
	int			**p3d;
	int			rgb0;
	int			rgb1;
	int			map_x;
	int			map_y;
	int			map_max_alt;
	int			offx;
	int			offy;
	int			*color;
	int			curr_proj;
}				t_fdf_main;

typedef struct	s_fdf_p2d{
	int			*x;
	int			*y;
	int			*z;
	int			*color;
	int			p;
	int			padd;
	int			quant;
	int			alt_mod;
}				t_fdf_p2d;

typedef struct	s_fdf_loop{
	int			lctrl;
	int			lmouse_x;
	int			lmouse_y;
	int			lmouse;
	int			lcmd;
	int			keyh;
}				t_fdf_loop;

typedef struct	s_fdf_l2d{
	int			x0;
	int			y0;
	int			color0;
	int			x;
	int			y;
	int			x1;
	int			y1;
	int			color1;
	int			dx;
	int			dy;
	int			d;
	int			sign;
}				t_fdf_l2d;

typedef struct	s_fdf_imgs
{
	void		*imgb;
	void		*imgh;
}				t_fdf_imgs;

typedef void	(*t_fdf_projs)(t_fdf_p2d *p2d);

typedef struct	s_fdf_ptr{
	t_fdf_main	*main;
	t_fdf_p2d	*p2d;
	t_fdf_projs	*projs;
	t_fdf_imgs	*imgs;
	t_fdf_loop	*loop;
}				t_fdf_ptr;

#endif
