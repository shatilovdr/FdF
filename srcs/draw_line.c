/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshatilo <dshatilo@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 14:18:52 by dshatilo          #+#    #+#             */
/*   Updated: 2024/01/09 19:01:24 by dshatilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	get_clr_coefs(float *color_coefs, t_pix_pair pair, int steps);
void	draw_line(t_grid grid, t_pix_pair pair);

void	draw_lines(t_map *map, t_grid grid, int i, int j)
{
	t_pix_pair	pair;

	pair.x = j * 100;
	pair.y = i * 100;
	pair.color = map->colors[i][j];
	if (j != map->size_x - 1)
	{
		pair.x1 = (j + 1) * 100;
		pair.y1 = i * 100;
		pair.color1 = map->colors[i][j + 1];
		draw_line(grid, pair);
	}
	if (i != map->size_y - 1)
	{
		pair.x1 = j * 100;
		pair.y1 = (i + 1) * 100;
		pair.color1 = map->colors[i + 1][j];
		draw_line(grid, pair);
	}
}

int	color_pixel(float *color_coefs, int curr_color, int i)
{
	curr_color += (int)round(color_coefs[0] * i) << 16;
	curr_color += (int)round(color_coefs[1] * i) << 8;
	curr_color += (int)round(color_coefs[2] * i);
	curr_color = curr_color << 8 | 0xFF;
	return (curr_color);
}

void	draw_line(t_grid grid, t_pix_pair pair)
{
	float	coord_coefs[2];
	float	color_coefs[3];
	int		color;
	int		max;
	int		i;

	max = (int)ft_max(ft_abs((long)(pair.x1 - pair.x)),
			ft_abs((long)(pair.y1 - pair.y)));
	coord_coefs[0] = (pair.x1 - pair.x) / max;
	coord_coefs[1] = (pair.y1 - pair.y) / max;
	get_clr_coefs(color_coefs, pair, max);
	i = 0;
	while ((int)(pair.x - pair.x1) || (int)(pair.y - pair.y1))
	{
		color = color_pixel(color_coefs, pair.color, i);
		mlx_put_pixel(grid.img, pair.x, pair.y, color);
		pair.x += coord_coefs[0];
		pair.y += coord_coefs[1];
		i++;
	}

}

void	get_clr_coefs(float *color_coefs, t_pix_pair pair, int steps)
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
	color_coefs[0] = r_diff / steps;
	color_coefs[1] = g_diff / steps;
	color_coefs[2] = b_diff / steps;
}


