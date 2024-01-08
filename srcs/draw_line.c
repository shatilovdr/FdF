/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshatilo <dshatilo@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 14:18:52 by dshatilo          #+#    #+#             */
/*   Updated: 2024/01/08 17:10:54 by dshatilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	get_clr_coefs(float *color_coefs, int color1, int color2, t_grid grid);

// void	draw_line(mlx_image_t *img, t_map *map, t_grid grid)
// {
// 	int	scale;

// 	scale = 30;
// }

void	draw_line_x(mlx_image_t *img, t_map *map, t_grid grid)
{
	int		k;
	int		color1;
	int		color2;
	int		curr_color;
	float	color_coefs[3];

	if (grid.j == map->size_x || grid.stp == 1)
		return ;
	color1 = map->colors[grid.i][grid.j - 1];
	color2 = map->colors[grid.i][grid.j];
	get_clr_coefs(color_coefs, color1, color2, grid);
	k = 1;
	while (k < grid.stp)
	{
		curr_color = color1;
		curr_color += (int)round(color_coefs[0] * k) << 16;
		curr_color += (int)round(color_coefs[1] * k) << 8;
		curr_color += (int)round(color_coefs[2] * k);
		// mlx_put_pixel(img, grid.x + k, grid.y, 0xFF);
		mlx_put_pixel(img, grid.x + k, grid.y, curr_color << 8 | 0xFF);
		k++;
	}
}

void	draw_line_y(mlx_image_t *img, t_map *map, t_grid grid)
{
	int		k;
	int		color1;
	int		color2;
	int		curr_color;
	float	color_coefs[3];

	if (grid.i == map->size_y - 1 || grid.stp == 1)
		return ;
	color1 = map->colors[grid.i][grid.j - 1];
	color2 = map->colors[grid.i + 1][grid.j - 1];
	get_clr_coefs(color_coefs, color1, color2, grid);
	k = 1;
	while (k < grid.stp)
	{
		curr_color = color1;
		curr_color += (int)round(color_coefs[0] * k) << 16;
		curr_color += (int)round(color_coefs[1] * k) << 8;
		curr_color += (int)round(color_coefs[2] * k);
		// mlx_put_pixel(img, grid.x, grid.y + k++, 0xFF);
		mlx_put_pixel(img, grid.x, grid.y + k++, curr_color << 8 | 0xFF);
	}
}

void	get_clr_coefs(float *color_coefs, int color1, int color2, t_grid grid)
{
	float	r_diff;
	float	g_diff;
	float	b_diff;

	b_diff = color2 % 256 - color1 % 256;
	color1 = color1 >> 8;
	color2 = color2 >> 8;
	g_diff = color2 % 256 - color1 % 256;
	color1 = color1 >> 8;
	color2 = color2 >> 8;
	r_diff = color2 % 256 - color1 % 256;
	color_coefs[0] = r_diff / (grid.stp - 1);
	color_coefs[1] = g_diff / (grid.stp - 1);
	color_coefs[2] = b_diff / (grid.stp - 1);
}