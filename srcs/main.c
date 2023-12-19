/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshatilo <dshatilo@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 16:29:15 by dshatilo          #+#    #+#             */
/*   Updated: 2023/12/19 18:08:51 by dshatilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"



int	main(int argc, char **argv)
{
	t_map		*map;


	if (argc != 2)
		return (0);
	map = reader(argv[1]);
	draw_img(map);
	free_2d_array(map->field);
	free_2d_array(map->colors);
	free(map);
	return (0);
}
