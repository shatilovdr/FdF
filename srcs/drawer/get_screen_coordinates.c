/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_screen_coordinates.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshatilo <dshatilo@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 11:10:14 by dshatilo          #+#    #+#             */
/*   Updated: 2024/01/14 13:38:03 by dshatilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	get_screen_coordinates(t_tp *tp, int i, int j, t_node *node)
{
	double	coordinates[3];

	rotate_coordinates(tp, i, j, coordinates);
	node->color = tp->map->colors[i][j];
	node->x = (coordinates[0] - coordinates[1]) * cos(0.8);
	node->y = (coordinates[0] + coordinates[1]) * sin(0.8) - coordinates[2];
	node->x *= tp->zoom;
	node->y *= tp->zoom;
	node->x += tp->shift_x;
	node->y += tp->shift_y;
	// int	cosine = 1;
	// int sine = 0;
	// node->x = tp->shift_x + (j * tp->zoom) * cosine - (i * tp->zoom) * sine;
	// node->y = tp->shift_y + (j * tp->zoom) * sine + (i * tp->zoom) * cosine;
}
