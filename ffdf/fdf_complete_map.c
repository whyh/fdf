/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_complete_map.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dderevyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/04 16:24:42 by dderevyn          #+#    #+#             */
/*   Updated: 2019/02/04 16:24:42 by dderevyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	fdf_complete_map(t_fdf_main *main, int x, int row)
{
	while (x < main->map_x)
	{
		main->p3d[row][x] = 0;
		main->color[(row * main->map_x) + x] = FDF_FLAGX;
		++x;
	}
}
