/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbousouf <mbousouf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 18:14:58 by mbousouf          #+#    #+#             */
/*   Updated: 2023/02/10 23:01:35 by mbousouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"
#include "map.h"

void	put_string(t_data *data)
{
	char	*s;
	char	*f;

	s = ft_itoa(data->moves);
	f = "moves : ";
	f = ft_strjoin(f, s, data->mem);
	mlx_string_put(data->mlx_ptr, data->win_ptr, 0, 0, 0xFFFFFF, f);
	free(s);
}

void	find_enm(t_data *data, int x, int y)
{
	int		i;
	int		j;
	char	c;

	i = -1;
	while (++i < data->map->hght)
	{
		j = 0;
		while (j < data->map->wid)
		{
			if (data->map->m[i][j] == 'N')
			{
				if (data->map->m[i + y][j + x] == '0' )
				{
					c = data->map->m[i + y][j + x];
					data->map->m[i + y][j + x] = data->map->m[i][j];
					data->map->m[i][j] = c;
					magic(data);
				}
			}
			j++;
		}
	}
}

int	genrate(t_data *data)
{
	static int	i;
	int			x;
	int			y;
	static int	var;

	(void)data;
	if (i == 4000)
	{
	x = rand() % 3 -1;
	y = rand() % 3 -1;
	var = rand() % 3 - 2;
		if (var)
			y = 0;
		else
			x = 0;
		find_enm(data, x, y);
		genrate_col(data);
	i = 0;
	}
	i++;
	return (0);
}
