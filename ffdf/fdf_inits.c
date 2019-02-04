/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_inits.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dderevyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/04 15:21:31 by dderevyn          #+#    #+#             */
/*   Updated: 2019/02/04 20:16:16 by dderevyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	fdf_malloc(t_fdf_main *main, t_fdf_p2d *p2d)
{
	p2d->quant = main->map_x * main->map_y;
	p2d->x = ft_memalloc(sizeof(int) * p2d->quant);
	p2d->y = ft_memalloc(sizeof(int) * p2d->quant);
	p2d->z = ft_memalloc(sizeof(int) * p2d->quant);
	p2d->color = ft_memalloc(sizeof(int) * p2d->quant);
}

int		fdf_parse_init(t_fdf_main *main, char *filename)
{
	int	fd;

	main->map_max_alt = 0;
	main->map_min_alt = FDF_ALT_RANGE;
	main->map_y = 0;
	main->map_x = 0;
	main->p3d = ft_memalloc(sizeof(int*) * FDF_MAX_MAP);
	main->color = ft_memalloc(sizeof(int) * FDF_MAX_MAP * FDF_MAX_MAP);
	fd = open(filename, O_RDONLY);
	if (fd < 1)
	{
		ft_printf("error: can't open file %s\n", filename);
		return (0);
	}
	return (fd);
}

void	fdf_set_init_values(t_fdf_ptr *ptr, t_fdf_main *main, t_fdf_p2d *p2d,
		t_fdf_imgs *imgs)
{
	main->curr_proj = 18;
	imgs->imgb = NULL;
	imgs->imgh = NULL;
	ptr->p2d = p2d;
	ptr->loop = NULL;
	ptr->imgs = imgs;
	ptr->main = main;
}

void	fdf_init_loop(t_fdf_ptr *ptr, t_fdf_loop *loop)
{
	loop->lmouse = 0;
	loop->keyr = 0;
	loop->lctrl = 0;
	loop->keyh = 0;
	loop->lcmd = 0;
	ptr->loop = loop;
}
