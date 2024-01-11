/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshatilo <dshatilo@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 18:06:55 by dshatilo          #+#    #+#             */
/*   Updated: 2024/01/11 10:52:06 by dshatilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	drawer(t_map *map)
{
	mlx_t	*mlx;
	int		width;
	int		height;

	//mlx_get_monitor_size(0, &width, &height); check how to make it work
	width = 5120;
	height = 2880;
	mlx = mlx_init(width / 4, height / 4, "MLX42", true);
	if (mlx)
		draw_img(map, mlx);
}


