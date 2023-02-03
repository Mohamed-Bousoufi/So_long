/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utilities.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbousouf <mbousouf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 14:37:01 by mbousouf          #+#    #+#             */
/*   Updated: 2022/11/15 22:13:38 by mbousouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	phexa1(unsigned long long n)
{
	char	*base;
	int		m;

	m = 0;
		base = "0123456789abcdef";
	if (n >= 16)
			m += phexa1(n / 16);
		m += ft_putchar(base[n % 16]);
	return (m);
}

int	ft_putstr(char *s)
{
	int	i;
	int	x;

	i = 0;
	x = 0;
	if (s == NULL)
	{
		ft_putstr("(null)");
		return (6);
	}
	while (s[i])
	{
		x += ft_putchar(s[i]);
			i++;
	}
	return (x);
}

int	ft_putchar(char c)
{
	if (write(1, &c, 1) == -1)
		return (-1);
	return (1);
}

int	ft_point(unsigned long long l)
{
	int	x;

	x = 0;
	x += ft_putstr("0x");
	x += phexa1(l);
	return (x);
}
