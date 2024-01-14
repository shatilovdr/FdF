/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_min_max_2d_array.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshatilo <dshatilo@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 22:17:39 by dshatilo          #+#    #+#             */
/*   Updated: 2024/01/14 22:26:32 by dshatilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

int	max_2d_array(int **arr, int size_y, int size_x)
{
	int	max;
	int	i;
	int	j;

	max = arr[0][0];
	i = 0;
	j = 1;
	while (i < size_y)
	{
		while (j < size_x)
		{
			if (arr[i][j] > max)
				max = arr[i][j];
			j++;
		}
		j = 0;
		i++;
	}
	return (max);
}

int	min_2d_array(int **arr, int size_y, int size_x)
{
	int	min;
	int	i;
	int	j;

	min = arr[0][0];
	i = 0;
	j = 1;
	while (i < size_y)
	{
		while (j < size_x)
		{
			if (arr[i][j] < min)
				min = arr[i][j];
			j++;
		}
		j = 0;
		i++;
	}
	return (min);
}
