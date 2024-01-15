/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_coordinates.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshatilo <dshatilo@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 10:20:32 by dshatilo          #+#    #+#             */
/*   Updated: 2024/01/15 13:00:37 by dshatilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	rotate_coordinates(t_tp *tp, int i, int j, double *coordinates)
{
	double	x;
	double	y;
	double	z;
	double	**mtx;

	mtx = tp->r_mtx;
	x = mtx[0][0] * (j - tp->map->size_x / 2) + mtx[0][1]
		* (i - tp->map->size_y / 2) + mtx[0][2] * tp->map->field[i][j];
	y = mtx[1][0] * (j - tp->map->size_x / 2) + mtx[1][1]
		* (i - tp->map->size_y / 2) + mtx[1][2] * tp->map->field[i][j];
	z = mtx[2][0] * (j - tp->map->size_x / 2) + mtx[2][1]
		* (i - tp->map->size_y / 2) + mtx[2][2] * tp->map->field[i][j];
	x *= tp->zoom;
	y *= tp->zoom;
	z *= tp->zoom;
	coordinates[0] = x + tp->map->size_x / 2;
	coordinates[1] = y + tp->map->size_y / 2;
	coordinates[2] = z;
}
