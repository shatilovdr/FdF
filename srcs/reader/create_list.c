/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshatilo <dshatilo@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 17:55:59 by dshatilo          #+#    #+#             */
/*   Updated: 2024/01/11 10:19:29 by dshatilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

t_list	*create_list(char *file_content)
{
	char	**file_by_lines;
	t_list	*list;
	t_list	*temp;
	size_t	i;

	file_by_lines = ft_split(file_content, '\n');
	free(file_content);
	if (!file_by_lines)
		exit(1);
	list = 0;
	i = 0;
	while (file_by_lines[i])
	{
		temp = ft_lstnew(file_by_lines[i++]);
		if (!temp)
		{
			ft_lstclear(&list, do_nothing);
			free_2d_array(file_by_lines);
			exit(1);
		}
		ft_lstadd_back(&list, temp);
	}
	free(file_by_lines);
	return (list);
}

