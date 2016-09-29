/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fprime2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: upierre- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/29 16:46:21 by upierre-          #+#    #+#             */
/*   Updated: 2016/09/29 17:42:23 by upierre-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int		check_prems_number(int nbr)
{
	int		base;

	base = nbr;
	nbr -= 1;
	while (nbr > 0 && ((base % nbr) != 0))
		nbr--;
	if (nbr == 1)
		return (1);
	else
		return (0);
}

int		fprime(char *str)
{
	int		nbr;
	int		i;

	nbr = atoi(str);
	if (nbr == 1)
	{
		printf("1");
		return (0);
	}
	i = 2;
	while (nbr > 1)
	{
		if ((nbr % i) == 0 && check_prems_number(i))
		{
			nbr = nbr / i;
			printf("%d", i);
			if (nbr != 1)
				printf("*");
			i -= 1;
		}
		i++;
	}
	printf("\n");
	return (1);
}

int		main(int ac, char **av)
{
	if (ac != 2)
		printf("\n");
	else
		fprime(av[1]);
	return (0);
}
