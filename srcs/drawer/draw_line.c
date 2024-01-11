/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshatilo <dshatilo@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 14:18:52 by dshatilo          #+#    #+#             */
/*   Updated: 2024/01/11 10:57:31 by dshatilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	draw_line(t_grid grid, t_pix_pair pair);
void	get_clr_incs(float *color_incs, t_pix_pair pair, int steps);
int		color_pixel(float *color_incs, int curr_color, int i);

void	draw_lines(t_map *map, t_grid grid, int i, int j)
{
	t_pix_pair	pair;


	pair.x = (j * grid.zoom) * grid.cos - (i * grid.zoom) * grid.sin;
	pair.y = (j * grid.zoom) * grid.sin + (i * grid.zoom) * grid.cos;
	pair.color = map->colors[i][j];
	if (j != map->size_x - 1)
	{
		pair.x1 = ((j + 1) * grid.zoom) * grid.cos - (i * grid.zoom) * grid.sin;
		pair.y1 = ((j + 1) * grid.zoom) * grid.sin + (i * grid.zoom) * grid.cos;
		pair.color1 = map->colors[i][j + 1];
		draw_line(grid, pair);
	}
	if (i != map->size_y - 1)
	{
		pair.x1 = (j * grid.zoom) * grid.cos - ((i + 1) * grid.zoom) * grid.sin;
		pair.y1 = (j * grid.zoom) * grid.sin + ((i + 1) * grid.zoom) * grid.cos;
		pair.color1 = map->colors[i + 1][j];
		draw_line(grid, pair);
	}
}

void	draw_line(t_grid grid, t_pix_pair pair)
{
	float	coord_incs[2];
	float	color_incs[3];
	int		color;
	size_t	steps;
	size_t	i;

	steps = (int)ft_max(ft_abs((long)(pair.x1 - pair.x)),
			ft_abs((long)(pair.y1 - pair.y)));
	coord_incs[0] = (pair.x1 - pair.x) / steps;
	coord_incs[1] = (pair.y1 - pair.y) / steps;
	get_clr_incs(color_incs, pair, steps);
	i = 0;
	while (i <= steps)
	{
		if (pair.x >= 0 && pair.x < grid.img->width
			&& pair.y >= 0 && pair.y < grid.img->height)
		{
			color = color_pixel(color_incs, pair.color, i);
			mlx_put_pixel(grid.img, pair.x, pair.y, color);
		}
		pair.x += coord_incs[0];
		pair.y += coord_incs[1];
		i++;
	}

}

void	get_clr_incs(float *color_incs, t_pix_pair pair, int steps)
{
	int		color1;
	int		color2;
	float	r_diff;
	float	g_diff;
	float	b_diff;

	color1 = pair.color;
	color2 = pair.color1;
	b_diff = color2 % 256 - color1 % 256;
	color1 = color1 >> 8;
	color2 = color2 >> 8;
	g_diff = color2 % 256 - color1 % 256;
	color1 = color1 >> 8;
	color2 = color2 >> 8;
	r_diff = color2 % 256 - color1 % 256;
	color_incs[0] = r_diff / steps;
	color_incs[1] = g_diff / steps;
	color_incs[2] = b_diff / steps;
}

int	color_pixel(float *color_incs, int curr_color, int i)
{
	curr_color += (int)round(color_incs[0] * i) << 16;
	curr_color += (int)round(color_incs[1] * i) << 8;
	curr_color += (int)round(color_incs[2] * i);
	curr_color = curr_color << 8 | 0xFF;
	return (curr_color);
}
