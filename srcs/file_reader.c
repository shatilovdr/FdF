/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_reader.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshatilo <dshatilo@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 22:27:46 by dshatilo          #+#    #+#             */
/*   Updated: 2023/12/12 23:09:58 by dshatilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

t_map	*file_reader(char *filename);

int	main(int argc, char *argv[])
{
	if (argc != 2)
		return (0);
	return (0);
}

t_map	*file_reader(char *filename)
{
	int		fd;
	t_map	*map;
	t_list	*curr_l;
	t_list	*all_lines;
	char	*curr;

	fd = open(filename, O_RDONLY);
	curr = get_next_line(fd);
	while (curr)
	{
		curr_l = ft_lstnew(curr);
		if (!curr_l)
		{
			ft_lstclear(&all_lines, free);
			return (NULL);
		}
		ft_lstadd_back(&all_lines, curr_l);
		curr = get_next_line(fd); //How to distinguish EOF and error in gnl?
	}
	
	return (map);
}
