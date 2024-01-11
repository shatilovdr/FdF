/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshatilo <dshatilo@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 22:46:14 by dshatilo          #+#    #+#             */
/*   Updated: 2024/01/11 10:19:19 by dshatilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

int	dec_color_check(char *arg, int *num);
int	hex_color_check(char *arg, int *num);
int	select_hex_mode(char *arg);
int	ft_base_to_decimal(char *num, char *base);

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
	else if (*num < 0 || *num > 0xFFFFFF)
		return (1);
	else
		return (0);
}

int	hex_color_check(char *arg, int *num)
{
	size_t	i;
	int		mode;
	char	*base;

	i = 0;
	if (arg[i] == '\0' || ft_strlen(arg) > 6)
		return (1);
	i = 0;
	while (arg[i])
		if (ft_strchr("0123456789abcdefABCDEF", arg[i++]) == NULL)
			return (1);
	mode = select_hex_mode(arg);
	if (mode == -1)
		return (1);
	base = "0123456789ABCDEF\0""0123456789abcdef";
	base = base + (17 * mode);
	*num = ft_base_to_decimal(arg, base);
	return (0);
}

int	select_hex_mode(char *arg)
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
	size_t	pos;
	int		result;

	pos = 0;
	result = 0;
	while (*num)
	{
		while (*num != base[pos])
			pos++;
		result = result * 16 + pos;
		pos = 0;
		num++;
	}
	return (result);
}
