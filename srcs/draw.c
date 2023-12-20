/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshatilo <dshatilo@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 18:06:55 by dshatilo          #+#    #+#             */
/*   Updated: 2023/12/20 18:54:17 by dshatilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

long	max(long a, long b);

// void	draw_line_x(size_t	dx)
// {
// 	size_t	i = 0;
// 	while();
// }

void	draw_img(t_map *map, mlx_t *mlx)
{
	mlx_image_t	*img;
	size_t		i;
	size_t		j;
	t_grid		grid;

	i = 0;
	j = 0;
	img = mlx_new_image(mlx, 1024, 1024);
	if (!img)
		return ;
	ft_bzero(&grid, sizeof(t_grid));
	grid.stp = (1024 - 1) / (max(map->size_x, map->size_y) - 1);
	while (i < map->size_y)
	{
		while (j < map->size_x)
		{
			mlx_put_pixel(img, grid.x, grid.y, map->colors[i][j++] << 8 | 0xFF);
			grid.x += grid.stp;
		}
		i++;
		grid.y += grid.stp;
		j = 0;
		grid.x = 0;
	}

	mlx_image_to_window(mlx, img, 100, 100);
	mlx_loop(mlx);
	mlx_terminate(mlx);
	(void)map;
	(void)mlx;
}

long	max(long a, long b)
{
	return (a * (a >= b) + b * (a < b));
}

long	min(long a, long b)
{
	return (a * (a <= b) + b * (a > b));
}
