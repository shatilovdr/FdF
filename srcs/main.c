/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshatilo <dshatilo@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 16:29:15 by dshatilo          #+#    #+#             */
/*   Updated: 2023/12/14 19:14:34 by dshatilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"


int	main(int argc, char *argv[])
{
	t_map	*map;

	if (argc != 2)
		return (0);
	map = file_reader(argv[1]);
	for (size_t i = 0; i < map->size_y; i++)
	{
		for (size_t j = 0; j < map->size_x; j++)
		{
			ft_printf("%d ", map->field[i][j]);
		}
		ft_printf("\n");
	}
	return (1);
}
