/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_strings_array.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshatilo <dshatilo@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 13:21:25 by dshatilo          #+#    #+#             */
/*   Updated: 2023/12/13 14:32:00 by dshatilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	free_strings_array(void *ptr)
{
	char	**arr;
	size_t	i;

	arr = (char **)ptr;
	i = 0;
	while (arr[i])
		free(arr[i++]);
	free(arr);
}
