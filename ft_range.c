/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: upierre- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/04 11:11:23 by upierre-          #+#    #+#             */
/*   Updated: 2016/10/04 14:44:09 by upierre-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int     *ft_range(int start, int end)
{
	int		*tab;
	int		i;
	int		c;

	i = start;
	c = 1;
	while (i != end)
	{
		if (i < end)
			i++;
		if (i > end)
			i--;
		c++;
	}
	if (!(tab = (int*)malloc(sizeof(tab) * (c))))
		return (NULL);
	i = 1;
	while (i <= c)
	{
		tab[i] = start;
		if (start < end)
			start++;
		if (start > end)
			start--;
		i++;
	}
	tab[i] = '\0';
	return (tab);
}
