/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collictbles.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbousouf <mbousouf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 15:22:21 by mbousouf          #+#    #+#             */
/*   Updated: 2023/02/10 16:19:44 by mbousouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

void	check_c(char **map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (map[i])
	{
		while (map[i][j])
		{
			if (map[i][j] == 'C')
			{
				perror("Error\n NOT_PATH_FROM_COL_TO_EXIT");
				exit(EXIT_FAILURE);
			}
			j++;
		}
		j = 0;
		i++;
	}
}

void	exist(char **map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (map[i])
	{
		while (map[i][j])
		{
			if (map[i][j] == 'E')
			{
				if (map[i + 1][j] != '.' && map[i][j + 1] != '.' &&
					map[i - 1][j] != '.' && map[i][j - 1] != '.')
				{
					perror("Error\nNO_PATH_FROM_PLAYER_TO_EXIT");
					exit(EXIT_FAILURE);
				}
			}
			j++;
		}
		j = 0;
		i++;
	}
}

void	find_path(int x, int y, char **map)
{
	if (map[x][y] == 'C' || map[x][y] == '0' || map[x][y] == 'P'
	|| map[x][y] == 'N')
	{
		map[x][y] = '.';
		find_path(x + 1, y, map);
		find_path(x, y + 1, map);
		find_path(x - 1, y, map);
		find_path(x, y - 1, map);
	}
}

char	**check_path(int x, int y, char **map)
{
	find_path(x + 1, y, map);
	find_path(x, y + 1, map);
	find_path(x - 1, y, map);
	find_path(x, y - 1, map);
	return (map);
}

char	**find_player(char **map)
{
	int			i;
	int			j;
	t_player	p;

	i = 0;
	j = 0;
	while (map[i])
	{
		while (map[i][j])
		{
			if (map[i][j] == 'P')
			{
				p.x = i;
				p.y = j;
			}
			j++;
		}
		j = 0;
		i++;
	}
	check_path(p.x, p.y, map);
	return (map);
}
