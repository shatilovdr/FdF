/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshatilo <dshatilo@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 18:06:55 by dshatilo          #+#    #+#             */
/*   Updated: 2023/12/19 18:13:03 by dshatilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	draw_img(t_map *map)
{
	mlx_t		*mlx;
	mlx_image_t	*img;

	mlx = mlx_init(1024, 1024, "MLX42", true);
	if (!mlx)
		exit(EXIT_FAILURE);
	img = mlx_new_image(mlx, 128, 128);
	ft_memset(img->pixels, 255, img->width * img->height * BPP);
	for (int i = 0; i < 100; i++)
	{
		for (int j = 0; j <  100; j++)
		{
			img->pixels[i] = 
		}
	}

	mlx_image_to_window(mlx, img, 100, 100);
	mlx_loop(mlx);
	mlx_terminate(mlx);
	(void)map;
}

int get_color()
{
	
}