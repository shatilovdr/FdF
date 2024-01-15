/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tp_initialise.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshatilo <dshatilo@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 11:30:37 by dshatilo          #+#    #+#             */
/*   Updated: 2024/01/15 15:57:37 by dshatilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

double	**create_2d_double_arr(void);

t_tp	*tp_initialise(t_tp *tp, int width, int height, t_map *map)
{
	tp->mlx = mlx_init(width / 4, height / 4, "FdF", true);
	if (!tp->mlx)
	{
		free(tp);
		return (NULL);
	}
	tp->img = mlx_new_image(tp->mlx, tp->mlx->width, tp->mlx->height);
	if (!tp->img)
	{
		mlx_terminate(tp->mlx);
		free(tp);
		return (NULL);
	}
	tp->r_mtx = create_2d_double_arr();
	if (!tp->r_mtx)
	{
		mlx_terminate(tp->mlx);
		free(tp);
		return (NULL);
	}
	tp->zoom = 0.3 * height / ft_max(map->size_x, map->size_y);
	tp->shift_x = 250;
	tp->shift_y = 100;
	tp->map = map;
	return (tp);
}

double	**create_2d_double_arr(void)
{
	double	**arr;

	arr = (double **)ft_calloc(4, sizeof(double *));
	if (!arr)
		return (NULL);
	arr[0] = (double *)ft_calloc(3, sizeof(double));
	if (!arr[0])
	{
		free(arr);
		return (NULL);
	}
	arr[1] = (double *)ft_calloc(3, sizeof(double));
	if (!arr[1])
	{
		free_2d_array(arr);
		return (NULL);
	}
	arr[2] = (double *)ft_calloc(3, sizeof(double));
	if (!arr[2])
	{
		free_2d_array(arr);
		return (NULL);
	}
	return (arr);
}
