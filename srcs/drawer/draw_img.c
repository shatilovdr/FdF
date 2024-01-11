/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_img.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshatilo <dshatilo@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 10:50:44 by dshatilo          #+#    #+#             */
/*   Updated: 2024/01/11 10:51:12 by dshatilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	draw_img(t_map *map, mlx_t *mlx)
{
	t_grid		grid;
	int			i;
	int			j;

	ft_bzero(&grid, sizeof(t_grid));
	grid.img = mlx_new_image(mlx, mlx->width, mlx->height);
	grid.angle = 10 / (180 / acos(-1));
	grid.zoom = 50;
	grid.cos = cos(grid.angle);
	grid.sin = sin(grid.angle);
	if (!grid.img)
		return ;
	i = 0;
	j = 0;
	while (i < map->size_y)
	{
		while (j < map->size_x)
		{
			draw_lines(map, grid, i, j);
			j++;
		}
		j = 0;
		i++;
	}
	mlx_image_to_window(mlx, grid.img, (grid.img->width - map->size_x * grid.zoom)/ 2,
		(grid.img->height - map->size_y * grid.zoom) / 2);
	// mlx_image_to_window(mlx, grid.img, 0, 0);
	mlx_loop(mlx);
	mlx_terminate(mlx);
}
