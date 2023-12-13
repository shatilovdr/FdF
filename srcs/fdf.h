/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshatilo <dshatilo@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 22:24:11 by dshatilo          #+#    #+#             */
/*   Updated: 2023/12/13 16:34:58 by dshatilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "../libft/libft.h"

# include <fcntl.h>

typedef struct s_map
{
	int		**field;
	size_t	size_x;
	size_t	size_y;
}	t_map;

t_map	*file_reader(char *filename);
t_list	*create_list(char *filename);
size_t	convert_lines_to_int_arrays(t_list **all_lines);
void	convert_lines_to_strings_arrays(t_list **all_lines);
void	clear_tlist_mixed(t_list **list, t_list *switch_point,
			void (*f1)(void *), void (*f2)(void *));
void	free_strings_array(void *ptr);
size_t	check_arrays_len(t_list **all_lines);
void	convert_strings_arrays_to_int_arrays(t_list **all_lines, size_t len);
int		**list_to_int_arrays(t_list **list, t_map *map, size_t	size_y);
t_map	*list_to_map(t_list **list, size_t size_x);

#endif
