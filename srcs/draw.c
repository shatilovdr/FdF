/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshatilo <dshatilo@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 18:06:55 by dshatilo          #+#    #+#             */
/*   Updated: 2024/01/08 16:32:25 by dshatilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	draw_img(t_map *map, mlx_t *mlx);

void	draw(t_map *map)
{
	mlx_t	*mlx;

	mlx = mlx_init(1100, 1100, "MLX42", true);
	if (mlx)
		draw_img(map, mlx);
}

void	draw_img(t_map *map, mlx_t *mlx)
{
	mlx_image_t	*img;
	t_grid		grid;
	// int			scale;

	img = mlx_new_image(mlx, mlx->width, mlx->height);
	if (!img)
		return ;




	
	ft_bzero(&grid, sizeof(t_grid));
	grid.stp = (mlx->width - 100) / ft_max(map->size_x, map->size_y);
	while (grid.i < map->size_y)
	{
		while (grid.j < map->size_x)
		{
			mlx_put_pixel(img, grid.x, grid.y, map->colors[grid.i][grid.j++] << 8 | 0xFF);
			draw_line_x(img, map, grid);
			draw_line_y(img, map, grid);
			grid.x += grid.stp;
		}
		grid.x = 0;
		grid.y += grid.stp;
		grid.j = 0;
		grid.i++;
	}
	mlx_image_to_window(mlx, img, 50, 50);
	mlx_loop(mlx);
	mlx_terminate(mlx);
}
