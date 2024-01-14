/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_screen_coordinates.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshatilo <dshatilo@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 11:10:14 by dshatilo          #+#    #+#             */
/*   Updated: 2024/01/14 23:18:27 by dshatilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	get_screen_coordinates(t_tp *tp, int i, int j, t_node *node)
{
	double	coordinates[3];
	t_map	*map;

	map = tp->map;
	rotate_coordinates(tp, i, j, coordinates);
	node->x = (coordinates[0] - coordinates[1]) * cos(0.8);
	node->y = (coordinates[0] + coordinates[1]) * sin(0.8) - coordinates[2];
	node->x *= tp->zoom;
	node->y *= tp->zoom;
	node->x += tp->shift_x;
	node->y += tp->shift_y;
	if (tp->color_mode == 0)
		node->color = tp->map->colors[i][j];
	else
	{
		node->color = 0xFFA500;
		if (map->max == map->min)
			return ;
		node->color += ft_abs(map->field[i][j]) / ((long)map->max - map->min)
			* (0x800080 - 0xFFA500);
	}
}
