/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plus.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbousouf <mbousouf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 18:36:21 by mbousouf          #+#    #+#             */
/*   Updated: 2023/02/09 14:09:26 by mbousouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"
#include "../so_long_bonus.h"

char	**track_track(char	*s)
{
	t_mem	*memo;
	char	*p;
	char	**map;

	map = NULL;
	memo = ft_calloc(sizeof(t_mem), MAX);
	if (!memo)
	{
		perror("Error\n Memory probleme");
		exit(1);
	}
	p = empty_check(s, memo);
	map = check_ar(p, memo);
	nbr_arg(map, memo);
	check_wall_a(map, memo);
	my_free(memo);
	return (map);
}

void	check_dem(char *s, t_mem *mem)
{
	int	i;

	i = 0;
	if (s[i] != '\n')
	{
		while (s[i])
		{
			if (s[i] == '\n' && s[i +1] == '\n')
			{
				ft_error(4, mem);
			}
			i++;
		}
		if (s[i] == '\0' && s[i -1] == '\n')
		{
			ft_error(4, mem);
		}
	}
	else
		ft_error(4, mem);
}

void	first_check(char *s, t_mem *mem)
{
	if (!strstr(s, ".ber") || ft_strlen(strstr(s, ".ber")) != 4)
	{
		ft_error(1, mem);
	}
}

void	check_col(char **map)
{
	map = find_player(map);
	check_c(map);
	exist(map);
	double_f(map);
}

int	exit_by(t_data *data)
{
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	double_f(data->map->m);
	my_free(data->mem);
	exit(0);
}
