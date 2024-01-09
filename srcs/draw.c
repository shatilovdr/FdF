/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshatilo <dshatilo@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 18:06:55 by dshatilo          #+#    #+#             */
/*   Updated: 2024/01/09 18:50:19 by dshatilo         ###   ########.fr       */
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
	t_grid		grid;
	int			i;
	int			j;

	ft_bzero(&grid, sizeof(t_grid));
	grid.img = mlx_new_image(mlx, mlx->width, mlx->height);
	if (!grid.img)
		return ;
	i = 0;
	j = 0;
	// draw_lines(map, grid, i, j);
	while (i < map->size_y)
	{
		while (j < map->size_x )
		{
			draw_lines(map, grid, i, j);
			j++;
		}
		j = 0;
		i++;
	}
	mlx_image_to_window(mlx, grid.img, 50, 50);
	mlx_loop(mlx);
	mlx_terminate(mlx);
}
