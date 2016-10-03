/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hidenp.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: upierre- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/03 20:16:22 by upierre-          #+#    #+#             */
/*   Updated: 2016/10/03 20:32:49 by upierre-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		hidenp(char *str, char *found)
{
	while (*found)
	{
		if (*str == *found)
		{
			str++;
			found++;
			if (*str == '\0')
			{
				write(1, "1\n", 2);
				return (1);
			}
		}
		else
			found++;
	}
	write(1, "0\n", 2);
	return (0);
}

int		main(int ac, char **av)
{
	if (ac != 3)
		write(1, "\n", 1);
	else
		hidenp(av[1], av[2]);
	return (0);
}
