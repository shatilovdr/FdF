/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_rotation_matrix.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshatilo <dshatilo@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 07:12:33 by dshatilo          #+#    #+#             */
/*   Updated: 2024/01/15 13:36:15 by dshatilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	calculate_rotation_matrix(t_tp *tp)
{
	double	**mtx;
	double	alpha;
	double	beta;
	double	gamma;

	mtx = tp->r_mtx;
	alpha = tp->alpha / (180 / M_PI);
	beta = tp->beta / (180 / M_PI);
	gamma = tp->gamma / (180 / M_PI);
	mtx[0][0] = cos(alpha) * cos(beta);
	mtx[0][1] = cos(alpha) * sin(beta) * sin(gamma) - sin(alpha) * cos(gamma);
	mtx[0][2] = cos(alpha) * sin(beta) * cos(gamma) + sin(alpha) * sin(gamma);
	mtx[1][0] = sin(alpha) * cos(beta);
	mtx[1][1] = sin(alpha) * sin(beta) * sin(gamma) + cos(alpha) * cos(gamma);
	mtx[1][2] = sin(alpha) * sin(beta) * cos(gamma) - cos(alpha) * sin(gamma);
	mtx[2][0] = -sin(beta);
	mtx[2][1] = cos(beta) * sin(gamma);
	mtx[2][2] = cos(beta) * cos(gamma);
}
