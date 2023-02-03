/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbousouf <mbousouf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 14:40:38 by mbousouf          #+#    #+#             */
/*   Updated: 2022/11/16 16:46:48 by mbousouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include<string.h>
# include<stdarg.h>
# include<unistd.h>
# include<stdio.h>

int	flags(va_list p, char ob);
int	ft_printf(char *n, ...);
int	ft_putstr(char *s);
int	ft_hexa(unsigned int p, char sg);
int	ft_putchar(char s);
int	ft_putnbr(int n);
int	unsigne(unsigned int n);
int	ft_point(unsigned long long l);
#endif