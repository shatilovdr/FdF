/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshatilo <dshatilo@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 18:06:55 by dshatilo          #+#    #+#             */
/*   Updated: 2024/01/15 16:08:08 by dshatilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	drawer(t_map *map)
{
	int			width;
	int			height;
	t_tp		*tp;

	width = 5120;
	height = 2880;
	tp = (t_tp *)ft_calloc(1, sizeof(t_tp));
	if (!tp)
		return ;
	tp = tp_initialise(tp, width, height, map);
	if (tp)
	{
		draw_img(tp);
		mlx_scroll_hook(tp->mlx, track_scroll, tp);
		mlx_key_hook(tp->mlx, track_keys, tp);
		mlx_loop(tp->mlx);
		mlx_terminate(tp->mlx);
	}
}
