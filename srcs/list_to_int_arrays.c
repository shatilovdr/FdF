/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_to_int_arrays.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshatilo <dshatilo@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 15:23:00 by dshatilo          #+#    #+#             */
/*   Updated: 2023/12/19 16:59:12 by dshatilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	**list_to_colors(t_list **list, t_map *map, size_t	size_y)
{
	int		**colors;
	t_list	*curr;
	size_t	i;

	colors = (int **)ft_calloc(size_y + 1, sizeof(int *));
	if (!colors)
	{
		free(map);
		ft_lstclear(list, free_2d_array);
		exit(1);
	}
	i = 0;
	curr = *list;
	while (i < size_y)
	{
		colors[i++] = ((int **)(curr->content))[0];
		curr = curr->next;
	}
	return (colors);
}

int	**list_to_field(t_list **list, t_map *map, size_t	size_y)
{
	int		**field;
	t_list	*curr;
	size_t	i;

	field = (int **)ft_calloc(size_y + 1, sizeof(int *));
	if (!field)
	{
		free(map->colors);
		free(map);
		ft_lstclear(list, free_2d_array);
		exit(1);
	}
	i = 0;
	curr = *list;
	while (i < size_y)
	{
		field[i++] = ((int **)(curr->content))[1];
		curr = curr->next;
	}
	return (field);
}
