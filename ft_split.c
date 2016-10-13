/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: upierre- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/10 18:59:29 by upierre-          #+#    #+#             */
/*   Updated: 2016/10/13 12:07:21 by upierre-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
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

char	**ft_split(char *str)
{
	char	**tab;
	int		words;
	int		i;
	int		j;
	int		c;

	i = 0;
	while (str[i] == ' ' || str[i] == '\t')
		i++;
	words = 0;
	while (str[i])
	{
		if (str[i] == ' ' || str[i] == '\t')
		{
			while (str[i] == ' ' || str[i] == '\t')
				i++;
			words++;
		}
		else
			i++;
	}
	if (!(tab = (char **)malloc(sizeof(tab) * (words + 1))))
		return (NULL);
	i = 0;
	c = 0;
	while (str[i] != '\0')
	{
		if (str[i] != ' ' && str[i] != '\t')
		{
			j = i;
			while (str[i] != ' ' && str[i] != '\t' && str[i] != '\0')
				i++;
			tab[c] = (char *)malloc(sizeof(char) * (i - j + 1));
			words = 0;
			tab[c][i - j + 1] = '\0';
			while (j < i)
			{
				tab[c][words] = str[j];
				j++;
				words++;
			}
			c++;
		}
		else
			i++;
	}
	return (tab);
}

int		main(int ac, char **av)
{
	if (ac != 2)
		write(1, "\n", 1);
	else
		ft_split(av[1]);
	return (0);
}
