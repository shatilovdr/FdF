/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_close_file.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshatilo <dshatilo@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 16:02:36 by dshatilo          #+#    #+#             */
/*   Updated: 2024/01/16 15:56:46 by dshatilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

int	open_close_file(char *mode, char *filename, int *fd)
{
	if (!ft_strncmp(mode, "open", 4))
	{
		*fd = open(filename, O_RDONLY);
		if (*fd < 0)
			return (-1);
		return (0);
	}
	else if (!ft_strncmp(mode, "close", 5))
	{
		if (close(*fd) < 0)
			return (-1);
		return (0);
	}
	return (1);
}
