/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dderevyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/30 11:20:03 by dderevyn          #+#    #+#             */
/*   Updated: 2019/01/30 16:15:41 by dderevyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	fdf_init(t_fdf_mlx *mlx, t_fdf_map	map)
{
	mlx->mlx_ptr = mlx_init();
	mlx->win_ptr = mlx_new_window(mlx->mlx_ptr, 500 + (int)map.matrix_length *
	3+ (int)map.matrix_heigth * 2, 500 + map.matrix_max_altitude * 3, "mlx");
//	mlx_pixel_put(mlx->mlx_ptr, mlx->win_ptr, 250, 250, 1000);
//	mlx_pixel_put(mlx->mlx_ptr, mlx->win_ptr, 251, 250, 1000);
//	mlx_pixel_put(mlx->mlx_ptr, mlx->win_ptr, 252, 250, 1000);
//	mlx_pixel_put(mlx->mlx_ptr, mlx->win_ptr, 253, 250, 1000);
	mlx_loop(mlx->mlx_ptr);
}

int			main(int argc, char **argv)
{
	t_fdf_map	map;
	t_fdf_mlx	mlx;

	if (argc != 2)
	{
		ft_printf("error: wrong usage, try\n./fdf map_name\n");
		return (0);
	}
	if (!fdf_get_matrix(argv[1], &map))
		return (0);
	ft_printf("decent map");
	fdf_init(&mlx, map);
//	system("leaks fdf");
	return (1);
}
