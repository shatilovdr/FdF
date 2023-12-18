/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_to_int_arrays.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshatilo <dshatilo@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 15:23:00 by dshatilo          #+#    #+#             */
/*   Updated: 2023/12/18 23:05:04 by dshatilo         ###   ########.fr       */
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
		free(map); //edit this part.
		ft_lstclear(list, free_2d_array);
		exit(1);
	}
	i = 0;
	curr = *list;
	while (i < size_y)
	{
		field[i++] = ((int **)(curr->content))[0];
		curr = curr->next;
	}
	return (field);
}
