/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_lines_to_strings_arrays.c                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshatilo <dshatilo@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 14:28:56 by dshatilo          #+#    #+#             */
/*   Updated: 2023/12/16 16:54:21 by dshatilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	convert_lines_to_strings_arrays(t_list **all_lines)
{
	t_list	*curr;
	char	**strings_array;

	curr = *all_lines;
	while (curr)
	{
		strings_array = ft_split((char *)curr->content, ' ');
		if (!strings_array)
			clear_tlist_mixed(all_lines, curr, free_2d_array, free);
		free(curr->content);
		curr->content = strings_array;
		curr = curr->next;
	}
}
