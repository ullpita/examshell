/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_prime_sum.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: upierre- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/29 12:05:04 by upierre-          #+#    #+#             */
/*   Updated: 2016/09/29 14:54:21 by upierre-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int n)
{
	if (n < 0)
	{
		ft_putchar('-');
		n = -n;
	}
	if (n >= 10)
	{
		ft_putnbr(n / 10);
		ft_putnbr(n % 10);
	}
	else
		ft_putchar(n + '0');
}

int		ft_atoi(char *str)
{
	int		i;
	int		res;
	int		negative;

	res = 0;
	negative = 0;
	i = 0;
	while ((str[i] == '\n') || (str[i] == '\t') || (str[i] == '\v') ||
			(str[i] == ' ') || (str[i] == '\f') || (str[i] == '\r'))
		i++;
	if (str[i] == '-')
		negative = 1;
	if (str[i] == '+' || str[i] == '-')
		i++;
	while (str[i] && (str[i] >= '0') && (str[i] <= '9'))
	{
		res *= 10;
		res += (int)str[i] - '0';
		i++;
	}
	if (negative == 1)
		return (-res);
	else
		return (res);
}

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

void	add_prime_sum(char *str)
{
	int		nbr;
	int		res;

	nbr = ft_atoi(str);
	res = 0;
	while (nbr > 0)
	{
		if (check_prems_number(nbr))
			res += nbr;
		nbr--;
	}
	ft_putnbr(res);
	ft_putchar('\n');
}

int		main(int ac, char **av)
{
	if (ac != 2)
		write(1, "\n", 1);
	else
		add_prime_sum(av[1]);
	return (0);
}
