/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_img.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshatilo <dshatilo@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 17:46:05 by dshatilo          #+#    #+#             */
/*   Updated: 2024/01/14 10:05:27 by dshatilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	clear_img(t_tp *tp);

void	draw_img(t_tp *tp)
{
	clear_img(tp);
	put_img(tp);
	mlx_image_to_window(tp->mlx, tp->img, 0, 0);
}

void	clear_img(t_tp *tp)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < tp->mlx->height)
	{
		while (j < tp->mlx->width)
		{
			mlx_put_pixel(tp->img, j, i, 0x0);
			j++;
		}
		j = 0;
		i++;
	}
}
