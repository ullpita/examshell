/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fprime.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: upierre- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 12:13:13 by upierre-          #+#    #+#             */
/*   Updated: 2018/01/15 13:26:21 by upierre-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int		main(int ac, char **av)
{
	int		i;
	int		nbr;

	if(ac != 2)
	{
		printf("\n");
		return(0);
	}
	nbr = atoi(av[1]);
	if(nbr == 1)
	{
		printf("1\n");
		return(0);
	}
	while(1)
	{
		i = 1;
		while (i++ <= nbr)
		{
			if (nbr % i == 0)
			{
				printf("%d", i);
				nbr = nbr / i;
				break;
			}
		}
		if (nbr == 1)
			break;
		else
			printf("*");
	}
	printf("\n");
}
