/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tp.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshatilo <dshatilo@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 11:30:37 by dshatilo          #+#    #+#             */
/*   Updated: 2024/01/11 18:56:31 by dshatilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	calculate_trig(double angle, double *cosine, double *sine);

void	tp_initialise(t_tp *tp)
{
	tp->zoom = 50;
	tp->shift_x = (tp->img->width - tp->map->size_x * tp->zoom) / 2;
	tp->shift_y = (tp->img->height - tp->map->size_y * tp->zoom) / 2;
	tp->angle = 10;
	calculate_trig(tp->angle, &tp->cosine, &tp->sine);
}

void	calculate_trig(double angle, double *cosine, double *sine)
{
	angle = angle / (180 / acos(-1));
	*cosine = cos(angle);
	*sine = sin(angle);
}
