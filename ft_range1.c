/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: upierre- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/10 16:53:32 by upierre-          #+#    #+#             */
/*   Updated: 2016/10/10 16:55:23 by upierre-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

int		*ft_range(int start, int end)
{
	int		**tab;
	int		c;
	int		i;
	int		tmp;

	c = 1;
	tmp = start;
	while (start != end)
	{
		if (start < end)
			start++;
		else
			start--;
		c++;
	}
	if (!(tab = (int **)malloc(sizeof(tab) * (c))))
		return (NULL);
	i = 0;
	start = tmp;
	c -= 1;
	while (i <= c)
	{
		tab[i] = (int*)malloc(sizeof(int) * 1);
		if (start == end)
			tab[i][0] = start;
		if (start < end)
		{
			tab[i][0] = start;
			start++;
		}
		if (start > end)
		{
			tab[i][0] = start;
			start--;
		}
		i++;
	}
	tab[i] = (int*)malloc(sizeof(int) * 1);
	tab[i][0] = '\0';
  return (*tab);
}
