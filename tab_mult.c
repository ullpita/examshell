/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tab_mult.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: upierre- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/03 17:53:05 by upierre-          #+#    #+#             */
/*   Updated: 2016/10/03 20:06:56 by upierre-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	while (*str)
	{
		ft_putchar(*str);
		str++;
	}
}

void	ft_putnbr(int nb)
{
	if (nb < 0)
	{
		ft_putchar('-');
		nb = -nb;
	}
	if (nb >= 10)
	{
		ft_putnbr(nb / 10);
		ft_putnbr(nb % 10);
	}
	else
		ft_putchar(nb + '0');
}

int		ft_atoi(char *str)
{
	int		sign;
	int		nbr;

	sign = 1;
	nbr = 0;
	while (*str == ' ' || *str == '\r' || *str == '\f' || *str == '\n' || *str == '\t' || *str == '\v')
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
	return (sign * (nbr));
}

void	tab_mult(char *str)
{
	int		nbr;
	int		i;

	nbr = ft_atoi(str);
	i = 1;
	while (i <= 9)
	{
		ft_putnbr(i);
		ft_putstr(" x ");
		ft_putnbr(nbr);
		ft_putstr(" = ");
		ft_putnbr(nbr * i);
		ft_putchar('\n');
		i++;
	}
}


int	 	main(int ac, char **av)
{
	if (ac != 2)
		ft_putchar('\n');
	else
		tab_mult(av[1]);
	return (0);
}
