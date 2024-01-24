/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tp_initialise.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshatilo <dshatilo@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 11:30:37 by dshatilo          #+#    #+#             */
/*   Updated: 2024/01/22 13:38:00 by dshatilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

double	**create_2d_double_arr(void);
void	get_init_coordinates(t_tp *tp, int i, int j, t_node *node);
void	get_limits(t_tp *tp);
void	get_zoom(t_tp *tp);

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
	tp->map = map;
	get_zoom(tp);
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

void	get_zoom(t_tp *tp)
{
	double		x_diff;
	double		y_diff;
	t_limits	l;

	tp->zoom = 1;
	tp->limits.min_x = LONG_MAX;
	tp->limits.min_y = LONG_MAX;
	tp->limits.max_x = LONG_MIN;
	tp->limits.max_y = LONG_MIN;
	get_limits(tp);
	l = tp->limits;
	x_diff = l.max_x - l.min_x;
	y_diff = l.max_y - l.min_y;
	if ((x_diff / tp->img->width) > (y_diff / tp->img->height))
		tp->zoom = 0.9 * tp->img->width / x_diff;
	else
		tp->zoom = 0.9 * tp->img->height / y_diff;
}

void	get_limits(t_tp *tp)
{
	t_node		n;
	t_limits	*l;
	int			i;
	int			j;

	l = &(tp->limits);
	i = 0;
	j = 0;
	calculate_rotation_matrix(tp);
	while (i < tp->map->size_y)
	{
		while (j < tp->map->size_x)
		{
			get_init_coordinates(tp, i, j, &n);
			j++;
			l->min_x = l->min_x * (l->min_x < n.x) + n.x * (n.x <= l->min_x);
			l->min_y = l->min_y * (l->min_y < n.y) + n.y * (n.y <= l->min_y);
			l->max_x = l->max_x * (l->max_x > n.x) + n.x * (n.x >= l->max_x);
			l->max_y = l->max_y * (l->max_y > n.y) + n.y * (n.y >= l->max_y);
		}
		j = 0;
		i++;
	}
}

void	get_init_coordinates(t_tp *tp, int i, int j, t_node *node)
{
	double	coordinates[3];

	rotate_coordinates(tp, i, j, coordinates);
	apply_projection(coordinates, node, tp->mode);
}
