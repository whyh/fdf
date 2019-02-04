/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_exit.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dderevyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/03 22:06:01 by dderevyn          #+#    #+#             */
/*   Updated: 2019/02/04 15:25:37 by dderevyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		fdf_close(void *param)
{
	t_fdf_ptr	*ptr;

	ptr = param;
	fdf_memdel(ptr);
	exit(0);
	return (1);
}

void	fdf_memdel(t_fdf_ptr *ptr)
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
