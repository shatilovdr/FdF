/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshatilo <dshatilo@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 16:29:15 by dshatilo          #+#    #+#             */
/*   Updated: 2023/12/15 19:15:26 by dshatilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"


int	main(void)
{
	int		test[3] = {1, 2, 3};
	char	*first = "ABCD";
	char	*second = "XYZ";
	char	**summ =(char **)malloc(sizeof(char *) * 2);
	void	**ptr = (void **)malloc(sizeof(void *) * 2);
	if (!ptr || !summ)
		return (0);
	summ[0] = first;
	summ[1] = second;
	ptr[0] = test;
	ptr[1] = summ;
	ft_printf("%d %s", ((int *)ptr[0])[1], ((char **)ptr[1])[1]);

	return (0);
}

// int	main(int argc, char *argv[])
// {
// 	t_map	*map;

// 	if (argc != 2)
// 		return (0);
// 	map = file_reader(argv[1]);
// 	for (size_t i = 0; i < map->size_y; i++)
// 	{
// 		for (size_t j = 0; j < map->size_x; j++)
// 		{
// 			ft_printf("%d ", map->field[i][j]);
// 		}
// 		ft_printf("\n");
// 	}
// 	return (0);
// }