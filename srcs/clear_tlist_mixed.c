/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_tlist_mixed.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshatilo <dshatilo@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 13:06:04 by dshatilo          #+#    #+#             */
/*   Updated: 2023/12/13 13:22:01 by dshatilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	clear_tlist_mixed(t_list **list, t_list *switch_point,
		void (*f1)(void *), void (*f2)(void *))
{
	t_list	*curr;

	curr = *list;
	if (curr == switch_point)
		ft_lstclear(list, f2);
	while (curr->next != switch_point)
		curr = curr->next;
	curr->next = NULL;
	ft_lstclear(list, f1);
	ft_lstclear(&switch_point, f2);
	exit(1);
}
