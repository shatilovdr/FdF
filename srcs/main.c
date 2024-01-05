/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshatilo <dshatilo@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 16:29:15 by dshatilo          #+#    #+#             */
/*   Updated: 2024/01/04 15:45:22 by dshatilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	find_hw(int *dimensions, t_map *map);

int	main(int argc, char **argv)
{
	t_map	*map;
	mlx_t	*mlx;

	if (argc != 2)
		return (0);
	map = reader(argv[1]);
	mlx = mlx_init(1100, 1100, "MLX42", true);
	if (!mlx)
	{
		//free map;
		exit(EXIT_FAILURE);
	}
	draw_img(map, mlx);
	free_2d_array(map->field);
	free_2d_array(map->colors);
	free(map);
	return (0);
}
