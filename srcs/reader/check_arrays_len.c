/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arrays_len.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshatilo <dshatilo@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 14:03:11 by dshatilo          #+#    #+#             */
/*   Updated: 2024/01/11 10:19:10 by dshatilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

size_t	check_arrays_len(t_list **all_lines)
{
	size_t	line_len;
	size_t	len;
	t_list	*temp;

	line_len = 0;
	temp = *all_lines;
	while (((char **)temp->content)[line_len])
		line_len++;
	while (temp)
	{
		len = 0;
		while (((char **)temp->content)[len])
			len++;
		if (len != line_len)
		{
			ft_lstclear(all_lines, free_2d_array);
			exit(1);
		}
		temp = temp->next;
	}
	return (line_len);
}
