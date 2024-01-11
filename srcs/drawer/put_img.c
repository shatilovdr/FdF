/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_img.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshatilo <dshatilo@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 10:50:44 by dshatilo          #+#    #+#             */
/*   Updated: 2024/01/11 17:57:21 by dshatilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	put_img(t_tp tp)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < tp.map->size_y)
	{
		while (j < tp.map->size_x)
		{
			put_lines(tp, i, j);
			j++;
		}
		j = 0;
		i++;
	}
}
