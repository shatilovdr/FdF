/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_screen_coordinates.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshatilo <dshatilo@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 11:10:14 by dshatilo          #+#    #+#             */
/*   Updated: 2024/01/15 15:40:48 by dshatilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	apply_projection(double *coordinates, t_node *node, int mode);
void	apply_color_inversion(t_node *node);

void	get_screen_coordinates(t_tp *tp, int i, int j, t_node *node)
{
	double	coordinates[3];
	t_map	*map;

	map = tp->map;
	rotate_coordinates(tp, i, j, coordinates);
	apply_projection(coordinates, node, tp->mode);
	node->x += tp->shift_x;
	node->y += tp->shift_y;
	if (tp->color_mode < 2)
		node->color = tp->map->colors[i][j];
	else
	{
		node->color = 0xFFA500;
		if (map->max == map->min)
			return ;
		node->color += ft_abs(map->field[i][j]) / ((long)map->max - map->min)
			* (0x800080 - 0xFFA500);
	}
	if (tp->inverse_mode == 1)
		apply_color_inversion(node);
}

void	apply_projection(double *coordinates, t_node *node, int mode)
{
	if (mode == 0 || mode == 1)
	{
		node->x = (coordinates[0] - coordinates[1]) * cos(0.5);
		node->y = (coordinates[0] + coordinates[1]) * sin(0.5) - coordinates[2];
	}
	if (mode == 2)
	{
		node->x = coordinates[0];
		node->y = coordinates[1];
	}
}

void	apply_color_inversion(t_node *node)
{
	int	color;
	int	r;
	int	g;
	int	b;

	color = node->color;
	b = 255 - color % 256;
	color = color >> 8;
	g = 255 - color % 256;
	color = color >> 8;
	r = 255 - color % 256;
	color = r << 16;
	color += g << 8;
	color += b;
	node->color = color;
}
