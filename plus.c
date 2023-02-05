/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plus.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbousouf <mbousouf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 18:36:21 by mbousouf          #+#    #+#             */
/*   Updated: 2023/02/05 22:46:20 by mbousouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"
#include "so_long.h"

char	**track_track(char	*s)
{
	t_mem	*memo;
	char	*p;
	char	**map;

	map = NULL;
	memo = calloc(sizeof(t_mem), MAX);
	if (!memo)
	{
		perror("Error\n Memory probleme");
		exit(1);
	}
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

int	exit_by(t_data *data)
{
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	double_f(data->map->m);
	my_free(data->mem);
	exit(0);
}
