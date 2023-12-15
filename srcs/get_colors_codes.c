/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_colors_codes.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshatilo <dshatilo@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 19:25:21 by dshatilo          #+#    #+#             */
/*   Updated: 2023/12/15 19:40:46 by dshatilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	get_colors_codes(t_list **all_lines, size_t line_len)
{
	t_list	*curr;
	char	**color_arr;

	curr = *all_lines;
	while (curr)
	{
		color_arr = curr_line_colors((char **)curr->content, line_len);
		if (!color_arr)
			clear_tlist_mixed(); 

	}
}

char	**curr_line_colors(char **strings_arr, size_t line_len)
{
	char	**color_arr;

	color_arr = (char **)ft_calloc(line_len + 1, sizeof(char *));

}
