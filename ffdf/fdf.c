/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dderevyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/30 11:20:03 by dderevyn          #+#    #+#             */
/*   Updated: 2019/02/04 19:48:05 by dderevyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	fdf_new_window(t_fdf_main *main, char *map)
{
	char	*title;

	title = ft_strjoin("fdf: ", map);
	main->mlx = mlx_init();
	main->win = mlx_new_window(main->mlx, FDF_WIN_X, FDF_WIN_Y, title);
	ft_strdel(&title);
}

static void	fdf_memdel(t_fdf_ptr *ptr)
{
	int i;

	ft_memdel((void**)&(ptr->p2d->x));
	ft_memdel((void**)&(ptr->p2d->y));
	i = 0;
	while (i < ptr->main->map_y)
		ft_memdel((void**)(&(ptr->main->p3d[i++])));
	ft_memdel((void**)(ptr->main->p3d));
	if (ptr->imgs->imgb != NULL)
		mlx_destroy_image(ptr->main->mlx, ptr->imgs->imgb);
	if (ptr->imgs->imgh != NULL)
		mlx_destroy_image(ptr->main->mlx, ptr->imgs->imgh);
}

static int	fdf_close(void *param)
{
	t_fdf_ptr	*ptr;

	ptr = param;
	fdf_memdel(ptr);
	exit(0);
	return (1);
}

static void	fdf_loop(t_fdf_ptr *ptr)
{
	t_fdf_loop	loop;

	fdf_init_loop(ptr, &loop);
	mlx_hook(ptr->main->win, 17, 0, &fdf_close, (void*)ptr);
	mlx_hook(ptr->main->win, 3, 0, &fdf_key_release, (void*)ptr);
	mlx_hook(ptr->main->win, 5, 0, &fdf_mouse_release, (void*)ptr);
	mlx_hook(ptr->main->win, 2, 0, &fdf_key_press, (void*)ptr);
	mlx_hook(ptr->main->win, 4, 0, &fdf_mouse_press, (void*)ptr);
	mlx_hook(ptr->main->win, 6, 0, &fdf_mouse_move, (void*)ptr);
	mlx_loop(ptr->main->mlx);
}

int			main(int argc, char **argv)
{
	t_fdf_main	main;
	t_fdf_p2d	p2d;
	t_fdf_imgs	imgs;
	t_fdf_projs	projs[50];
	t_fdf_ptr	ptr;

	if ((argc != 2 && argc != 3) || !fdf_parse(argv[1], argv[2], &main))
	{
		ft_printf("usage: ./fdf map RRRGGGBBB~RRRGGGBBB\n");
		return (0);
	}
	fdf_new_window(&main, argv[1]);
	fdf_malloc(&main, &p2d);
	ptr.projs = projs;
	projs[18] = &fdf_projection_iso;
	projs[19] = &fdf_projection_iso_2_1;
	projs[20] = &fdf_projection_top;
	projs[21] = &fdf_projection_side;
	fdf_set_init_values(&ptr, &main, &p2d, &imgs);
	fdf_project(0, &ptr, 1);
	fdf_loop(&ptr);
	fdf_memdel(&ptr);
	return (1);
}
