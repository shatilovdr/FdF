/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_lines.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshatilo <dshatilo@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 14:18:52 by dshatilo          #+#    #+#             */
/*   Updated: 2024/01/14 23:17:00 by dshatilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	put_line(mlx_image_t *img, t_node a, t_node b);
void	get_clr_incs(float *color_incs, int color1, int color2, int steps);
int		color_pixel(float *color_incs, int curr_color, int i);

void	put_lines(t_tp *tp, int i, int j)
{
	t_node	a;
	t_node	b;

	get_screen_coordinates(tp, i, j, &a);
	if (j != tp->map->size_x - 1)
	{
		get_screen_coordinates(tp, i, j + 1, &b);
		put_line(tp->img, a, b);
	}
	if (i != tp->map->size_y - 1)
	{
		get_screen_coordinates(tp, i + 1, j, &b);
		put_line(tp->img, a, b);
	}
}

void	put_line(mlx_image_t *img, t_node a, t_node b)
{
	float	coord_incs[2];
	float	color_incs[3];
	int		color;
	size_t	steps;
	size_t	i;

	steps = ft_max(ft_abs((long)(b.x - a.x)),
			ft_abs((long)(b.y - a.y)));
	coord_incs[0] = (b.x - a.x) / steps;
	coord_incs[1] = (b.y - a.y) / steps;
	get_clr_incs(color_incs, a.color, b.color, steps);
	i = 0;
	while (i <= steps)
	{
		if (a.x >= 0 && a.x < img->width
			&& a.y >= 0 && a.y < img->height)
		{
			color = color_pixel(color_incs, a.color, i);
			mlx_put_pixel(img, a.x, a.y, color);
		}
		a.x += coord_incs[0];
		a.y += coord_incs[1];
		i++;
	}
}

void	get_clr_incs(float *color_incs, int color1, int color2, int steps)
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
