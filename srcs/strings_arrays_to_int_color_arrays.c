/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strings_arrays_to_int_color_arrays.c               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshatilo <dshatilo@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 14:38:37 by dshatilo          #+#    #+#             */
/*   Updated: 2023/12/16 16:57:19 by dshatilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	*check_strings_array(size_t len, char **arr);
int	check_arg(char *arg, int *num);

void	strings_arrays_to_int_color_arrays(t_list **all_lines, size_t len)
{
	t_list	*curr;
	int		**color_and_int;

	curr = *all_lines;
	while (curr)
	{
		color_and_int = (int **)ft_calloc(3, sizeof(int *));
		if (!color_and_int)
			clear_tlist_mixed(all_lines, curr, free, free_2d_array);
		color_and_int[0] = get_color(len, (char **)curr->content);
		if (!color_and_int[0])
		{
			free_2d_array(color_and_int);
			clear_tlist_mixed(all_lines, curr, free, free_2d_array);
		}
		color_and_int[1] = check_strings_array(len, (char **)curr->content);
		if (!color_and_int[1])
		{
			free_2d_array(color_and_int);
			clear_tlist_mixed(all_lines, curr, free, free_2d_array);
		}
		free_2d_array(curr->content);
		curr->content = color_and_int;
		curr = curr->next;
	}
}

int	*check_strings_array(size_t len, char **arr)
{
	size_t	i;
	int		*args;

	args = (int *)malloc(sizeof(int) * (len));
	if (!args)
		return (NULL);
	i = 0;
	while (i < len)
	{
		if (check_arg(arr[i], &args[i]))
		{
			free (args);
			return (NULL);
		}
		i++;
	}
	return (args);
}

int	check_arg(char *arg, int *num)
{
	int	pos;

	pos = 0;
	if (arg[pos] == '+' || arg[pos] == '-')
		pos++;
	if (!arg[pos])
		return (1);
	while (arg[pos])
	{
		if (!ft_isdigit(arg[pos]))
			return (1);
		pos++;
	}
	*num = ft_atoi(arg);
	if (*num == 0)
	{
		while (--pos)
			if (arg[pos] != '0')
				return (1);
		if (arg[pos] != '0' && arg[pos] != '+' && arg[pos] != '-')
			return (1);
	}
	return (0);
}
