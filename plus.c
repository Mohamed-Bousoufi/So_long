/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plus.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbousouf <mbousouf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 18:36:21 by mbousouf          #+#    #+#             */
/*   Updated: 2023/02/04 18:41:42 by mbousouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

char	**track_track(char	*s)
{
	t_mem	*memo;
	char	*p;
	char	**map;

	map = NULL;
	memo = calloc(sizeof(t_mem), MAX);
	p = empty_check(s, memo);
	map = check_ar(p);
	nbr_arg(map);
	check_wall_a(map);
	my_free(memo);
	return (map);
}

void	check_dem(char *s)
{
	int	i;

	i = 0;
	if (s[i] != '\n')
	{
		while (s[i])
		{
			if (s[i] == '\n' && s[i +1] == '\n')
			{
				ft_error(4);
			}
			i++;
		}
		if (s[i] == '\0' && s[i -1] == '\n')
		{
			ft_error(4);
		}
	}
	else
		ft_error(4);
}

void	first_check(char *s)
{
	if (!strstr(s, ".ber") || ft_strlen(strstr(s, ".ber")) != 4)
	{
		ft_error(1);
	}
}

void	check_col(char **map)
{
	map = find_player(map);
	check_c(map);
	exist(map);
	double_f(map);
}
