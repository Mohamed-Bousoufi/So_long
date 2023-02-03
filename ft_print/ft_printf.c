/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbousouf <mbousouf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 14:34:41 by mbousouf          #+#    #+#             */
/*   Updated: 2022/11/16 18:19:02 by mbousouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	flags(va_list p, char ob)
{
	int	num;

	num = 0;
	if (ob == 'c')
		num += ft_putchar(va_arg(p, int));
	else if (ob == 's')
		num += ft_putstr(va_arg(p, char *));
	else if (ob == 'x' || ob == 'X')
		num += ft_hexa(va_arg(p, unsigned int), ob);
	else if (ob == 'd' || ob == 'i')
		num += ft_putnbr(va_arg(p, int));
	else if (ob == 'u')
		num += unsigne(va_arg(p, unsigned int));
	else if (ob == 'p')
		num += ft_point(va_arg(p, long long));
	else if (ob == '%')
		num += ft_putchar('%');
	else
		num += ft_putchar(ob);
	return (num);
}

int	ft_printf(char *n, ...)
{
	int		i;
	va_list	p;
	int		count;

	i = 0;
	count = 0;
	va_start(p, n);
	while (n[i] != '\0')
	{
		if (n[i] == '%' && n[i +1] == '\0')
			return (i);
		if (n[i] == '%')
		{
			count += flags(p, n[i + 1]);
					i++;
		}
		else
			count += ft_putchar(n[i]);
		i++;
	}
	if (n[i] == '%' && n[i +1] == '0')
				count = 0;
	va_end(p);
	return (count);
}
