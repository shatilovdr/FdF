/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshatilo <dshatilo@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 17:55:59 by dshatilo          #+#    #+#             */
/*   Updated: 2023/12/13 14:47:03 by dshatilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_list	*create_list(char *filename)
{
	int		fd;
	char	*curr_line;
	t_list	*list;
	t_list	*temp;

	fd = open(filename, O_RDONLY);
	if (open < 0)
		exit (1);
	curr_line = get_next_line(fd);
	list = 0;
	while (curr_line)
	{
		temp = ft_lstnew(curr_line);
		if (!temp)
		{
			free(curr_line);
			ft_lstclear(&list, free);
			close(fd);
			exit(1);
		}
		ft_lstadd_back(&list, temp);
		curr_line = get_next_line(fd); //How to distinguish EOF and error in gnl?
	}
	close(fd);
	return (list);
}
//if gnl ends with error you have to close fd;