/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hidenp.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: upierre- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/13 15:34:13 by upierre-          #+#    #+#             */
/*   Updated: 2016/10/13 15:47:40 by upierre-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	hidenp(char *str, char *found)
{
	while (*str && *found)
	{
		if (*str == *found)
			str++;
		found++;
	}
	if (*str == '\0')
		write(1, "1\n", 2);
	else
		write(1, "0\n", 2);
}

int		main(int ac, char **av)
{
	if (ac != 3)
		write(1, "\n", 1);
	else
		hidenp(av[1], av[2]);
	return (0);
}
