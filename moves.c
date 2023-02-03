/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbousouf <mbousouf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 17:14:45 by mbousouf          #+#    #+#             */
/*   Updated: 2023/02/03 20:07:33 by mbousouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	*send_image(t_data *data, char c)
{
	void	*img;

	if (c == '0')
		img = data->img->g;
	if (c == '1')
		img = data->img->w;
	if (c == 'C')
		img = data->img->c;
	if (c == 'P')
		img = data->img->p;
	if (c == 'E')
		img = data->img->e;
	return (img);
}

void magic(t_data *data)
{
	int		i;
	int		j;
	void	*img;

	i = 0;
	j = 0;
	while (i < data->map->hght)
	{
		while (j < data->map->wid)
		{
			img = send_image(data, data->map->m[i][j]);
			mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, img,
				j * 50, i * 50);
			j++;
		}
	j = 0;
	i++;
	}
}

void	move_up(t_data *data)
{
	if (data->map->m[data->map->p_y - 1][data->map->p_x] != '1')
	{
		data->map->m[data->map->p_y - 1][data->map->p_x]
			= data->map->m[data->map->p_y][data->map->p_x];
		data->map->m[data->map->p_y][data->map->p_x] = '0';
		mlx_clear_window(data->mlx_ptr,data->win_ptr);
		magic(data);
		data->moves++;
		ft_printf("\nnombres de moves :%d\n", data->moves);
	}
}

void	move_down(t_data *data)
{
	if (data->map->m[data->map->p_y + 1][data->map->p_x] != '1')
	{
		data->map->m[data->map->p_y + 1][data->map->p_x]
			= data->map->m[data->map->p_y][data->map->p_x];
		data->map->m[data->map->p_y][data->map->p_x] = '0';
		mlx_clear_window(data->mlx_ptr,data->win_ptr);
		magic(data);
		data->moves++;
		ft_printf("\nnombres de moves :%d\n", data->moves);
	}
}

void	move_left(t_data *data)
{
	if (data->map->m[data->map->p_y][data->map->p_x -1] != '1')
	{
		data->map->m[data->map->p_y][data->map->p_x -1]
			= data->map->m[data->map->p_y][data->map->p_x];
		data->map->m[data->map->p_y][data->map->p_x] = '0';
		mlx_clear_window(data->mlx_ptr,data->win_ptr);
		magic(data);
		data->moves++;
		ft_printf("\nnombres de moves :%d\n", data->moves);
	}
}

void	move_right(t_data *data)
{
	if (data->map->m[data->map->p_y][data->map->p_x +1] != '1')
	{
		data->map->m[data->map->p_y][data->map->p_x +1]
			= data->map->m[data->map->p_y][data->map->p_x];
		data->map->m[data->map->p_y][data->map->p_x] = '0';
		mlx_clear_window(data->mlx_ptr,data->win_ptr);
		magic(data);
		data->moves++;
		ft_printf("\nnombres de moves :%d\n", data->moves);
	}
}
