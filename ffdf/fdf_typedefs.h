/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_typedefs.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dderevyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/30 11:36:39 by dderevyn          #+#    #+#             */
/*   Updated: 2019/01/30 16:11:28 by dderevyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_TYPEDEFS_H
# define FDF_TYPEDEFS_H

# define FDF_MAX_MAP_ROWS 1000
# define FDF_MAX_ALTITUDE 100

typedef struct	s_fdf_map {
	int			**matrix;
	int			**pointx;
	int			**pointy;
	int 		**pointz;
	size_t		matrix_length;
	size_t		matrix_heigth;
	int			matrix_max_altitude;
}				t_fdf_map;

typedef struct	s_fdf_mlx {
	void		*mlx_ptr;
	void		*win_ptr;
}				t_fdf_mlx;



#endif
