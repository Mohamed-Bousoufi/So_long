/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_nbrutils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbousouf <mbousouf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 10:52:40 by mbousouf          #+#    #+#             */
/*   Updated: 2022/11/15 15:45:29 by mbousouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_hexa(unsigned int p, char sg)
{
	char	*base;
	int		n;

	n = 0;
	if (sg == 'x')
	{
		base = "0123456789abcdef";
		if (p > 16)
			n += ft_hexa(p / 16, sg);
		n += ft_putchar(base[p % 16]);
	}
	if (sg == 'X')
	{
		base = "0123456789ABCDEF";
		if (p > 16)
			n += ft_hexa(p / 16, sg);
		n += ft_putchar(base[p % 16]);
	}
	return (n);
}

int	ft_putnbr(int n)
{
	char		b;
	long long	num;
	int			x;

	x = 0;
	num = n;
	if (n < 0)
	{
		x += ft_putchar('-');
		num = num * -1;
	}
	if (num < 10)
	{
		b = (num + 48);
		x += ft_putchar(b);
	}
	if (num >= 10)
	{
		x += ft_putnbr(num / 10);
		x += ft_putnbr(num % 10);
	}
	return (x);
}

int	unsigne(unsigned int n )

{
	char			b;
	unsigned int	num;
	int				x;

	x = 0;
	num = n;
	if (n < 0)
	{
		x = -1;
		return (x);
	}
	if (num < 10)
	{
		b = (num + 48);
		x += ft_putchar(b);
	}
	if (num >= 10)
	{
		x += unsigne(num / 10);
		x += unsigne(num % 10);
	}
	return (x);
}
