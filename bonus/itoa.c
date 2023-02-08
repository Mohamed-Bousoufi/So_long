/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   itoa.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbousouf <mbousouf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 20:27:28 by mbousouf          #+#    #+#             */
/*   Updated: 2023/02/08 16:45:36 by mbousouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

static char	*filput(char *num, int c, int number)
{
	int	n;
	int	m;

	n = number;
	m = c;
	if (number < 0)
	{
		num[0] = '-';
		number *= -1;
	}
		c--;
	while (number != 0)
	{
		n = (char)(number % 10 + 48);
		if (n >= 48 && n <= 57)
			num[c--] = n;
		number /= 10;
	}
	num[m] = '\0';
	return (num);
}

static char	*checker(int n, int c)
{
	char		*num;

	if (n && c)
		if (n < 0)
			c++;
	num = (char *)malloc(sizeof(char) * c + 1);
	if (!num)
		return (0);
	num = filput(num, c, n);
	return (num);
}

static int	count(int n)
{
	int	c;

	c = 0;
	while (n != 0)
	{
		n /= 10;
		c++;
	}
	return (c);
}

char	*ft_itoa(int n)
{
	int		c;
	int		number;
	char	*num;

	number = n;
	if (n == 0)
	{
		num = (char *)ft_strdup("0");
		return (num);
	}
	else if (n == -2147483648)
	{
		num = (char *)ft_strdup("-2147483648");
		return (num);
	}
	else
	{
		c = count(number);
		num = checker(n, c);
	}
	if (!num)
		return (0);
	return (num);
}
