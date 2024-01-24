/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_screen_coordinates.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshatilo <dshatilo@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 11:10:14 by dshatilo          #+#    #+#             */
/*   Updated: 2024/01/22 15:38:54 by dshatilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	apply_projection(double *coordinates, t_node *node, int mode);
void	apply_color_inversion(t_node *node);
void	apply_height_dependency(t_tp *tp, t_node *node, int i, int j);

void	get_screen_coordinates(t_tp *tp, int i, int j, t_node *node)
{
	double	coordinates[3];

	rotate_coordinates(tp, i, j, coordinates);
	apply_projection(coordinates, node, tp->mode);
	node->x -= (tp->limits.max_x + tp->limits.min_x) / 2;
	node->y -= (tp->limits.max_y + tp->limits.min_y) / 2;
	node->x *= tp->zoom;
	node->y *= tp->zoom;
	node->x += (double)tp->img->width / 2 + tp->shift_x ;
	node->y += (double)tp->img->height / 2 + tp->shift_y;
	if (tp->color_mode < 2)
		node->color = tp->map->colors[i][j];
	else
		apply_height_dependency(tp, node, i, j);
	if (tp->inverse_mode == 1)
		apply_color_inversion(node);
}

void	apply_projection(double *coordinates, t_node *node, int mode)
{
	if (mode == 0 || mode == 1)
	{
		node->x = (coordinates[0] - coordinates[1]) * cos(0.6);
		node->y = (coordinates[0] + coordinates[1]) * sin(0.6) - coordinates[2];
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

void	apply_height_dependency(t_tp *tp, t_node *node, int i, int j)
{
	double	coef;
	t_map	*map;
	int		color_range;
	int		abs_range;

	map = tp->map;
	abs_range = ft_abs(map->max - map->min);
	color_range = 0xFFA500 - 0x800080;
	node->color = 0x800080;
	if (map->max == map->min)
		return ;
	coef = (double)(map->field[i][j] - map->min) / abs_range;
	node->color += (int)(coef * color_range);
}
