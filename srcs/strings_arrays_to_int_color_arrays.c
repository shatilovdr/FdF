/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strings_arrays_to_int_color_arrays.c               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshatilo <dshatilo@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 14:38:37 by dshatilo          #+#    #+#             */
/*   Updated: 2023/12/18 17:58:21 by dshatilo         ###   ########.fr       */
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
			ft_lstclear(all_lines, free_2d_array);
		color_and_int[0] = get_color(len, (char **)curr->content);
		if (!color_and_int[0])
		{
			free_2d_array(color_and_int);
			clear_tlist_mixed(all_lines, curr, free_2d_array, free_2d_array);
		}
		color_and_int[1] = check_strings_array(len, (char **)curr->content);
		if (!color_and_int[1])
		{
			free_2d_array(color_and_int);
			clear_tlist_mixed(all_lines, curr, free_2d_array, free_2d_array);
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

int	*get_color(size_t len, char **arr)
{
	size_t	i;
	int		*colors;

	colors = (int *)malloc(sizeof(int) * (len));
	if (!colors)
		return (NULL);
	i = 0;
	while (i < len)
	{
		if (check_color(arr[i], &colors[i]))
		{
			free (colors);
			return (NULL);
		}
		i++;
	}
	return (colors);
}

int	check_color(char *arg, int *num)
{
	char	*pos;

	pos = ft_strchr(arg, ',');
	if (!pos)
	{
		*num = 0xFFFFFF;
		return (0);
	}
	if (ft_strlen(pos) == 1)
		return (1);
	*pos = '\0';
	if (!ft_strncmp(pos + 1, "0x", 2))
		return (hex_color_check(pos + 3, num));
	else
		return (dec_color_check(pos + 1, num));
}

int	dec_color_check(char *arg, int *num)
{
	int	pos;

	pos = 0;
	while (arg[pos])
	{
		if (!ft_isdigit(arg[pos]))
			return (1);
		pos++;
	}
	*num = ft_atoi(arg);
	if (*num != 0 && *arg == '0')
		return (1);
	if (*num == 0 && ft_strlen(arg) != 1)
		return (1);
	else if (*num < 0 || *num > 16777215)
		return (1);
	else
		return (0);
}

int	hex_color_check(char *arg, int *num)
{
	size_t	i;
	int		mode;
	char	*base;

	if (arg[i] == '\0' || ft_strlen(arg) > 6)
		return (1);
	i = 0;
	while (arg[i])
		if (ft_strchr("0123456789abcdefABCDEF", arg[i++]) == NULL)
			return (1);
	mode = select_mode(arg);
	if (mode == -1)
		return (1);
	base = "0123456789ABCDEF\0""0123456789abcdef";
	base = base + (17 * mode);
}

int	select_mode(char *arg)
{
	size_t	low;
	size_t	cap;
	size_t	i;

	low = 0;
	cap = 0;
	i = 0;
	while (arg[i])
	{
		if (ft_strchr("ABCDEF", arg[i]))
			cap++;
		else if (ft_strchr("abcdef", arg[i]))
			low++;
		if (low != 0 && cap != 0)
			return (-1);
		i++;
	}
	return (1 * (low != 0));
}

int	ft_base_to_decimal(char *num, char *base)
{
	size_t	i;
	size_t	pos;
	size_t	len;
	int		result;


	len = ft_strlen(num);
	i = 0;
	pos = 0;
	result = 0;
	while (len - i != 0)
	{
		while (num[len - 1 - i] != base[pos])
			pos++;
		result += ft_iterative_power(16, i) * pos;
		pos = 0;
		i++;
	}
	return (result);
}
