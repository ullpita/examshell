/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: upierre- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/08 12:11:42 by upierre-          #+#    #+#             */
/*   Updated: 2017/03/08 14:58:14 by upierre-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

char	*ft_strnew(int i)
{
	char	*str;

	if (!(str = (char*)malloc(sizeof(char) * (i + 1))))
		return(NULL);
	i += 1;
	while(i >= 0)
	{
		str[i] = '\0';
		i--;
	}
	return(str);
}

static int		ft_size(int n)
{
	int			i;

	i = 0;
	if (n < 0)
		i++;
	while (n)
	{
		n /= 10;
		i++;
	}
	return (i);
}

char			*ft_itoa(int n)
{
	char		*mem;
	int			i;

	i = ft_size(n);
	if (!(mem = ft_strnew(i)))
		return (NULL);
	if (n == 0)
	{
		mem[0] = '0';
		return (mem);
	}
	if (n == -2147483648)
	{
		mem = "-2147483648";
		return(mem);
	}
	if (n < 0)
	{
		mem[0] = '-';
		n = -(n);
	}
	while (n != 0)
	{
		mem[i - 1] = (n % 10) + '0';
		n /= 10;
		i--;
	}
	return (mem);
}
