/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rostring.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/13 11:31:00 by exam              #+#    #+#             */
/*   Updated: 2018/02/13 12:03:03 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

int		rostring(char *str)
{
	int		i;
	int		j;
	int		k;
	int		c;

	i = 0;
	while (str[i] == ' ' || str[i] == '\t')
	{
		i++;
		if (str[i] == '\0')
			return(0);
	}
	k = i;
	j = 0;
	while (str[i] != ' ' && str[i] != '\t' && str[i])
	{
		j++;
		i++;
	}
	c = i;
	if (str[i] == '\0')
	{
		while (k < i)
		{
			write(1, &str[k], 1);
			k++;
		}
		return(0);
	}
	else
	{
		while (str[c])
		{
			if (str[c] != ' ' && str[c] != '\t')
			{
				write(1, &str[c], 1);
				if (str[c + 1] == ' ' || str[c + 1] == '\t')
					write(1, " ", 1);
			}
			c++;
		}
	}
	if (str[c - 1] != ' ' && str[c - 1] != '\t')
		write(1, " ", 1);
	while (k < i)
	{
		write(1, &str[k], 1);
		k++;
	}
	return(0);
}

int		rostring(int ac, char **av)
{
	if (ac >= 2)
		first(av[1]);
	write(1, "\n", 1);
	return(0);
}
