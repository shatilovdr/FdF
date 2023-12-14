/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_newline_arrays.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshatilo <dshatilo@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 13:47:48 by dshatilo          #+#    #+#             */
/*   Updated: 2023/12/14 14:40:26 by dshatilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	remove_newline_arrays(t_list **all_lines)
{
	t_list	*temp;
	size_t	i;
	char	**strings_array;

	temp = *all_lines;
	while (temp)
	{
		strings_array = (char **)temp->content;
		i = 0;
		while (strings_array[i + 1] != NULL)
			i++;
		if (*strings_array[i] == '\n')
		{
			free(strings_array[i]);
			strings_array[i] = NULL;
		}
		temp = temp->next;
	}
}
