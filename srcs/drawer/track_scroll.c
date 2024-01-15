/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   track_scroll.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshatilo <dshatilo@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 13:03:03 by dshatilo          #+#    #+#             */
/*   Updated: 2024/01/15 13:08:39 by dshatilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	track_scroll(double xdelta, double ydelta, void *param)
{
	t_tp	*tp;

	tp = (t_tp *)param;
	if (ydelta > 0)
		tp->zoom *= 1.0204081632653061224489795918367346;
	else if (ydelta < 0)
		tp->zoom *= 0.98;
	(void)xdelta;
	draw_img(tp);
}
