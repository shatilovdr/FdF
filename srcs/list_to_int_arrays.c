/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_to_int_arrays.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshatilo <dshatilo@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 15:23:00 by dshatilo          #+#    #+#             */
/*   Updated: 2023/12/14 18:38:35 by dshatilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	**list_to_int_arrays(t_list **list, t_map *map, size_t	size_y)
{
	int		**field;
	t_list	*curr;
	size_t	i;

	field = (int **)malloc(sizeof(int *) * size_y);
	if (!field)
	{
		free(map);
		ft_lstclear(list, free);
		exit(1);
	}
	i = 0;
	curr = *list;
	while (i < size_y)
	{
		field[i++] = (int *)curr->content;
		curr = curr->next;
	}
	ft_lstclear(list, do_nothing);
	return (field);
}
