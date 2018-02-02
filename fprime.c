/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fprime.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: upierre- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/02 16:16:54 by upierre-          #+#    #+#             */
/*   Updated: 2018/02/02 16:55:56 by upierre-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int		main(int ac, char **av)
{
	int		nbr;
	int		i;

	if (ac != 2)
	{
		printf("\n");
		return(0);
	}
	nbr = atoi(av[1]);
	if (nbr == 1)
	{
		printf("1\n");
		return(0);
	}
	while (1)
	{
		i = 1;
		while (i++ <= nbr)
		{
			if ((nbr % i) == 0)
			{
				printf("%d", i);
				nbr = nbr / i;
				break;
			}
		}
		if (nbr == 1 || nbr == 0)
			break;
		else
			printf("*");
	}
	printf("\n");
	return(0);
}
