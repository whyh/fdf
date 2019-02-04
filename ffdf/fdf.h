/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dderevyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/30 11:20:22 by dderevyn          #+#    #+#             */
/*   Updated: 2019/02/04 15:24:54 by dderevyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <math.h>
# include <mlx.h>
# include "../libft/libft.h"
# include "fdf_typedefs.h"

int		fdf_parse(char *filename, char	*rgb, t_fdf_main *main);
void	fdf_draw(t_fdf_p2d *p2d, t_fdf_main main);
int		fdf_close(void *param);
int		fdf_mouse_move(int x, int y, void *param);
int		fdf_key_release(int keycode, void *param);
int		fdf_mouse_release(int button, int x, int y, void *param);
int		fdf_mouse_press(int button, int x, int y, void *param);
int		fdf_key_press(int keycode, void *param);
void	fdf_projection_iso(t_fdf_p2d *p2d);
void	fdf_projection_iso_2_1(t_fdf_p2d *p2d);
void	fdf_projection_top(t_fdf_p2d *p2d);
void	fdf_projection_side(t_fdf_p2d *p2d);
void	fdf_move(int x, int y, t_fdf_ptr *ptr);
void	fdf_altitude(int step, t_fdf_ptr *ptr);
int		fdf_gradient(t_fdf_l2d l2d);
void	fdf_project(int keycode, t_fdf_ptr *ptr);
void	fdf_zoom(int step, t_fdf_ptr *ptr);
void	fdf_compose_slide(t_fdf_ptr *ptr);
void	fdf_memdel(t_fdf_ptr *ptr);
void	fdf_help_menu(t_fdf_ptr *ptr);
int		fdf_get_gradient(t_fdf_main main, int alt);
void	fdf_parse_gradient(t_fdf_main *main, char *line, int *i, int p);
int		fdf_parse_init(t_fdf_main *main, char *filename);
void	fdf_set_init_values(t_fdf_ptr *ptr, t_fdf_main *main, t_fdf_p2d *p2d,
		t_fdf_imgs *imgs);
void	fdf_malloc(t_fdf_main *main, t_fdf_p2d *p2d);
void	fdf_new_window(t_fdf_main *main, char *map);
void	fdf_init_loop(t_fdf_ptr *ptr, t_fdf_loop *loop);

#endif
