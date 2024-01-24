/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   track_keys.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshatilo <dshatilo@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 12:10:07 by dshatilo          #+#    #+#             */
/*   Updated: 2024/01/21 23:54:41 by dshatilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	track_translation(mlx_key_data_t keydata, t_tp *tp);
void	track_rotation(mlx_key_data_t keydata, t_tp *tp);
void	track_projectiontion(mlx_key_data_t keydata, t_tp *tp);

void	track_keys(mlx_key_data_t keydata, void *param)
{
	t_tp	*tp;

	tp = (t_tp *)param;
	track_translation(keydata, tp);
	track_rotation(keydata, tp);
	track_projectiontion(keydata, tp);
	if (keydata.key == MLX_KEY_C)
		tp->color_mode = (tp->color_mode + 1) % 4;
	else if (keydata.key == MLX_KEY_I)
		tp->inverse_mode = 1;
	else if (keydata.key == MLX_KEY_O)
		tp->inverse_mode = 0;
	else if (keydata.key == MLX_KEY_ESCAPE)
	{
		mlx_close_window(tp->mlx);
		return ;
	}
	draw_img(tp);
}

void	track_translation(mlx_key_data_t keydata, t_tp *tp)
{
	if (keydata.key == MLX_KEY_W)
		tp->shift_y -= 10;
	else if (keydata.key == MLX_KEY_A)
		tp->shift_x -= 10;
	else if (keydata.key == MLX_KEY_S)
		tp->shift_y += 10;
	else if (keydata.key == MLX_KEY_D)
		tp->shift_x += 10;
}

void	track_rotation(mlx_key_data_t keydata, t_tp *tp)
{
	if (keydata.key == MLX_KEY_PERIOD)
		tp->alpha += 3;
	else if (keydata.key == MLX_KEY_COMMA)
		tp->alpha -= 3;
	else if (keydata.key == MLX_KEY_RIGHT)
		tp->beta += 3;
	else if (keydata.key == MLX_KEY_LEFT)
		tp->beta -= 3;
	else if (keydata.key == MLX_KEY_UP)
		tp->gamma += 3;
	else if (keydata.key == MLX_KEY_DOWN)
		tp->gamma -= 3;
}

void	track_projectiontion(mlx_key_data_t keydata, t_tp *tp)
{
	if (keydata.key == MLX_KEY_1)
		tp->mode = 1;
	else if (keydata.key == MLX_KEY_2)
		tp->mode = 2;
}
