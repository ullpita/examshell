/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: upierre- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/08 15:28:44 by upierre-          #+#    #+#             */
/*   Updated: 2017/03/08 17:48:44 by upierre-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"
#include <stdlib.h>

int		croissant(int a, int b)
{
	return (a <= b);
}

t_list	*sort_list(t_list* lst, int (*cmp)(int, int))
{
	int		tmp_lst;
	t_list	*lst_base;

	lst_base = lst;
	while (lst->next != NULL)
	{
		if ((*cmp)(lst->data, lst->next->data) == 0)
		{
			tmp_lst = lst->data;
			lst->data = lst->next->data;
			lst->next->data = tmp_lst;
			lst = lst_base;
		}
		else
			lst = lst->next;
	}
	lst = lst_base;
	return (lst);
}
