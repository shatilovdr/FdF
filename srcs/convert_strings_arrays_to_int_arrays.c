/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_strings_arrays_to_int_arrays.c             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshatilo <dshatilo@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 14:38:37 by dshatilo          #+#    #+#             */
/*   Updated: 2023/12/14 18:47:38 by dshatilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	*check_strings_array(size_t len, char **arr);
int	check_arg(char *arg, int *num);

void	convert_strings_arrays_to_int_arrays(t_list **all_lines, size_t len)
{
	t_list	*curr;
	int		*int_arr;

	curr = *all_lines;
	while (curr)
	{
		int_arr = check_strings_array(len, (char **)curr->content);
		if (!int_arr)
			clear_tlist_mixed(all_lines, curr, free, free_strings_array);
		free_strings_array(curr->content);
		curr->content = int_arr;
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
