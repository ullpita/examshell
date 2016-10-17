/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: upierre- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/17 14:11:49 by upierre-          #+#    #+#             */
/*   Updated: 2016/10/17 19:31:25 by upierre-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		ft_atoi(char *str)
{
	int		nbr;
	int		sign;

	nbr = 0;
	sign = 1;
	while (*str == ' ' || *str == '\r' || *str == '\f' || *str == '\n' 
			|| *str == '\t' || *str == '\v')
		str++;
	if (*str == '-')
		sign = -1;
	if (*str == '+' || *str == '-')
		str++;
	while (*str && *str >= '0' && *str <= '9')
	{
		nbr = (nbr * 10) + (*str - '0');
		str++;
	}
	return(sign * (nbr));
}

int		print_hex(char *str)
{
	int		nbr;
	int		byt[64];
	int		i;

	nbr = ft_atoi(str);
	if (nbr < 0)
		return (0);
	i = 0;
	while (nbr > 0)
	{
		byt[i] = nbr % 2;
		nbr = nbr / 2;
		i++;
	}
	while (i != 4 && i != 8 && i != 16 && i != 24 && i != 32 
			&& i != 40 && i != 48 && i != 56 && i != 64)
	{
		byt[i] = 0;
		i++;
	}
	ft_putchar('\n');
	while (i > 0)
	{
		if (byt[i - 4] == 1 && byt[i - 3] == 1 && byt[i - 2] == 1 && byt[i - 1] == 1)
			write(1, "f", 1);
		if (byt[i - 4] == 1 && byt[i - 3] == 1 && byt[i - 2] == 1 && byt[i - 1] == 0)
			write(1, "7", 1);
		if (byt[i - 4] == 1 && byt[i - 3] == 1 && byt[i - 2] == 0 && byt[i - 1] == 1)
			write(1, "b", 1);
		if (byt[i - 4] == 1 && byt[i - 3] == 1 && byt[i - 2] == 0 && byt[i - 1] == 0)
			write(1, "3", 1);
		if (byt[i - 4] == 1 && byt[i - 3] == 0 && byt[i - 2] == 1 && byt[i - 1] == 1)
			write(1, "d", 1);
		if (byt[i - 4] == 1 && byt[i - 3] == 0 && byt[i - 2] == 1 && byt[i - 1] == 0)
			write(1, "5", 1);
		if (byt[i - 4] == 1 && byt[i - 3] == 0 && byt[i - 2] == 0 && byt[i - 1] == 1)
			write(1, "9", 1);
		if (byt[i - 4] == 1 && byt[i - 3] == 0 && byt[i - 2] == 0 && byt[i - 1] == 0)
			write(1, "1", 1);
		if (byt[i - 4] == 0 && byt[i - 3] == 1 && byt[i - 2] == 1 && byt[i - 1] == 1)
			write(1, "e", 1);
		if (byt[i - 4] == 0 && byt[i - 3] == 1 && byt[i - 2] == 1 && byt[i - 1] == 0)
			write(1, "6", 1);
		if (byt[i - 4] == 0 && byt[i - 3] == 1 && byt[i - 2] == 0 && byt[i - 1] == 1)
			write(1, "a", 1);
		if (byt[i - 4] == 0 && byt[i - 3] == 1 && byt[i - 2] == 0 && byt[i - 1] == 0)
			write(1, "2", 1);
		if (byt[i - 4] == 0 && byt[i - 3] == 0 && byt[i - 2] == 1 && byt[i - 1] == 1)
			write(1, "c", 1);
		if (byt[i - 4] == 0 && byt[i - 3] == 0 && byt[i - 2] == 1 && byt[i - 1] == 0)
			write(1, "4", 1);
		if (byt[i - 4] == 0 && byt[i - 3] == 0 && byt[i - 2] == 0 && byt[i - 1] == 1)
			write(1, "8", 1);
		if (byt[i - 4] == 0 && byt[i - 3] == 0 && byt[i - 2] == 0 && byt[i - 1] == 0)
			write(1, "0", 1);
		i -= 4;
	}
	return (1);
}

int		main(int ac, char **av)
{
	if (ac == 2)
		print_hex(av[1]);
	write(1, "\n", 1);
}
