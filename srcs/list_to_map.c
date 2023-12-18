/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_to_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshatilo <dshatilo@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 15:25:26 by dshatilo          #+#    #+#             */
/*   Updated: 2023/12/18 23:01:59 by dshatilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
t_map	*list_to_map(t_list **list, size_t size_x)
{
	t_map	*map;
	size_t	size_y;

	map = (t_map *)malloc(sizeof(t_map) * 1);
	if (!map)
	{
		ft_lstclear(list, free_2d_array);
		exit(1);
	}
	size_y = ft_lstsize(*list);
	map->field = list_to_int_arrays(list, map, size_y);
	map->colors = list_to_int_arrays(list, map, size_y);
	map->size_x = size_x;
	map->size_y = size_y;
	return (map);
}

