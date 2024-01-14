/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshatilo <dshatilo@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 18:06:55 by dshatilo          #+#    #+#             */
/*   Updated: 2024/01/14 13:28:56 by dshatilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	track_keys(mlx_key_data_t keydata, void *param);

void	drawer(t_map *map)
{
	int			width;
	int			height;
	t_tp		*tp;

	//mlx_get_monitor_size(0, &width, &height); check how to make it work
	width = 5120;
	height = 2880;
	tp = (t_tp *)ft_calloc(1, sizeof(t_tp));
	if (!tp)
		return ;
	tp = tp_initialise(tp, width, height, map);
	if (tp)
	{
		draw_img(tp);
		mlx_key_hook(tp->mlx, track_keys, tp);
		mlx_loop(tp->mlx);
		mlx_terminate(tp->mlx);
	}
}

void	track_keys(mlx_key_data_t keydata, void *param)
{
	t_tp	*tp;

	tp = (t_tp *)param;
	if (keydata.key == MLX_KEY_RIGHT)
		tp->shift_x += 10;
	else if (keydata.key == MLX_KEY_LEFT)
		tp->shift_x -= 10;
	else if (keydata.key == MLX_KEY_UP)
		tp->shift_y -= 10;
	else if (keydata.key == MLX_KEY_DOWN)
		tp->shift_y += 10;
	else if (keydata.key == MLX_KEY_I)
		tp->zoom *= 1.0204081632653061224489795918367346;
	else if (keydata.key == MLX_KEY_O)
		tp->zoom *= 0.98;
	else if (keydata.key == MLX_KEY_1)
		tp->alpha += 2;
	else if (keydata.key == MLX_KEY_2)
		tp->beta += 2;
	else if (keydata.key == MLX_KEY_3)
		tp->gamma += 2;
	else if (keydata.key == MLX_KEY_ESCAPE)
	{
		mlx_delete_image(tp->mlx, tp->img);
		mlx_close_window(tp->mlx);
	}
	draw_img(tp);
}
