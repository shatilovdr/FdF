/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_color_coefs.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshatilo <dshatilo@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 11:46:15 by dshatilo          #+#    #+#             */
/*   Updated: 2023/12/22 11:47:23 by dshatilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	get_clr_coefs(float *color_coefs, int color1, int color2, t_grid grid)
{
	int	r_diff;
	int	g_diff;
	int	b_diff;

	r_diff = ((color1 >> 16) & 0xFF) - ((color2 >> 16) & 0xFF);
	g_diff = ((color1 >> 8) & 0xFF) - ((color2 >> 8) & 0xFF);
	b_diff = (color1 & 0xFF) - (color2 & 0xFF);
	color_coefs[0] = (float)r_diff / grid.stp;
	color_coefs[1] = (float)g_diff / grid.stp;
	color_coefs[2] = (float)b_diff / grid.stp;
}
