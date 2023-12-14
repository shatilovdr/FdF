/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_reader.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshatilo <dshatilo@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 22:27:46 by dshatilo          #+#    #+#             */
/*   Updated: 2023/12/14 18:16:58 by dshatilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_map	*file_reader(char *filename)
{
	t_map	*map;
	t_list	*all_lines;
	size_t	size_x;
	char	*file_content;

	file_content = read_file(filename);
	all_lines = create_list(file_content);
	if (!all_lines)
		exit(0);
	size_x = convert_lines_to_int_arrays(&all_lines);
	map = list_to_map(&all_lines, size_x);
	return (map);
}
