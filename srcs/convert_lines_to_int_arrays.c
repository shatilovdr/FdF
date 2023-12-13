/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_lines_to_int_arrays.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshatilo <dshatilo@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 11:24:48 by dshatilo          #+#    #+#             */
/*   Updated: 2023/12/13 17:59:29 by dshatilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

size_t	convert_lines_to_int_arrays(t_list **all_lines)
{
	size_t	line_len;

	convert_lines_to_strings_arrays(all_lines);
	line_len = check_arrays_len(all_lines);
	convert_strings_arrays_to_int_arrays(all_lines, line_len);
	return (line_len);
}



