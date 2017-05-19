/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rostring.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: upierre- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/19 16:45:57 by upierre-          #+#    #+#             */
/*   Updated: 2017/05/19 18:39:44 by upierre-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		rostring(char *str)
{
	int		i;
	int		j;
	int		k;

	i = 0;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n')
		i++;
	j = i;
	while (str[i] != ' ' && str[i] != '\t' && str[i] != '\n')
		i++;
	k = i;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n' || str[i] == '\0')
	{
		if (str[i] != '\0')
			i++;
		if (str[i] == '\0')
		{
			write(1, &str[j], (k - j));
			return(0);
		}
	}
	while (str[i])
	{
		if (str[i] == ' ' || str[i] == '\t' || str[i] == '\n')
		{
			while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n')
				i++;
			if (str[i])
				write(1, " ", 1);
		}
		if (str[i] != ' ' && str[i] != '\t' && str[i] != '\n')
			write(1, &str[i], 1);
		i++;
	}
	write(1, " ", 1);
	write(1, &str[j], (k - j));
	return(0);
}

int		main(int ac, char **av)
{
	if (ac != 2)
		write(1, "\n", 1);
	else
		rostring(av[1]);
	return(0);
}
