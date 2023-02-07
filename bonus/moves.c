/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbousouf <mbousouf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 17:14:45 by mbousouf          #+#    #+#             */
/*   Updated: 2023/02/07 17:19:25 by mbousouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

void	magic(t_data *data)
{
	int		i;
	int		j;
	void	*img;

	i = 0;
	while (i < data->map->hght)
	{
		j = 0;
		while (j < data->map->wid)
		{
			img = send_image(data, data->map->m[i][j]);
			mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, img,
				j * 50, i * 50);
			j++;
		}
		i++;
	}
}

void	move_up(t_data *data)
{
	if (data->map->m[data->map->p_y - 1][data->map->p_x] != '1')
	{
		if (data->map->m[data->map->p_y - 1][data->map->p_x] != 'E' &&
			data->map->m[data->map->p_y - 1][data->map->p_x] != 'N' )
		{
			if (data->map->m[data->map->p_y - 1][data->map->p_x] == 'C')
				data->map->col--;
			data->map->m[data->map->p_y - 1][data->map->p_x]
				= data->map->m[data->map->p_y][data->map->p_x];
			data->map->m[data->map->p_y][data->map->p_x] = '0';
			data->moves++;
			mlx_clear_window(data->mlx_ptr, data->win_ptr);
			magic(data);
			put_string(data);
		}
		else if (data->map->m[data->map->p_y - 1][data->map->p_x]
		== 'E' && data->map->col == 0)
			end(data, 0);
		else if (data->map->m[data->map->p_y - 1][data->map->p_x] == 'N')
			end (data, 1);
	}
}

void	move_down(t_data *data)
{
	if (data->map->m[data->map->p_y + 1][data->map->p_x] != '1')
	{
		if (data->map->m[data->map->p_y + 1][data->map->p_x] != 'E'
		&& data->map->m[data->map->p_y + 1][data->map->p_x] != 'N')
		{
			if (data->map->m[data->map->p_y + 1][data->map->p_x] == 'C')
				data->map->col--;
			data->map->m[data->map->p_y + 1][data->map->p_x]
				= data->map->m[data->map->p_y][data->map->p_x];
			data->map->m[data->map->p_y][data->map->p_x] = '0';
			data->moves++;
			mlx_clear_window(data->mlx_ptr, data->win_ptr);
			magic(data);
			put_string(data);
		}
		else if (data->map->m[data->map->p_y + 1][data->map->p_x]
		== 'E' && data->map->col == 0)
			end(data, 0);
		else if (data->map->m[data->map->p_y + 1][data->map->p_x] == 'N')
			end (data, 1);
	}
}

void	move_left(t_data *data)
{
	if (data->map->m[data->map->p_y][data->map->p_x -1] != '1')
	{
		if (data->map->m[data->map->p_y][data->map->p_x -1] != 'E'
		&&data->map->m[data->map->p_y][data->map->p_x -1] != 'N')
		{
			if (data->map->m[data->map->p_y][data->map->p_x -1] == 'C')
				data->map->col--;
			data->map->m[data->map->p_y][data->map->p_x -1]
				= data->map->m[data->map->p_y][data->map->p_x];
			data->map->m[data->map->p_y][data->map->p_x] = '0';
			data->moves++;
			mlx_clear_window(data->mlx_ptr, data->win_ptr);
			magic(data);
			put_string(data);
		}
		else if (data->map->m[data->map->p_y][data->map->p_x -1]
		== 'E' && data->map->col == 0)
			end(data, 0);
		else if (data->map->m[data->map->p_y][data->map->p_x -1] == 'N')
			end (data, 1);
	}
}

void	move_right(t_data *data)
{
	if (data->map->m[data->map->p_y][data->map->p_x +1] != '1')
	{
		if (data->map->m[data->map->p_y][data->map->p_x +1] != 'E'
		&&data->map->m[data->map->p_y][data->map->p_x + 1] != 'N')
		{
			if (data->map->m[data->map->p_y][data->map->p_x +1] == 'C')
				data->map->col--;
			data->map->m[data->map->p_y][data->map->p_x +1]
				= data->map->m[data->map->p_y][data->map->p_x];
			data->map->m[data->map->p_y][data->map->p_x] = '0';
			data->moves++;
			mlx_clear_window(data->mlx_ptr, data->win_ptr);
			magic(data);
			put_string(data);
		}
		else if (data->map->m[data->map->p_y][data->map->p_x +1] == 'N')
			end (data, 1);
		else if (data->map->m[data->map->p_y][data->map->p_x +1]
			== 'E' && data->map->col == 0)
			end(data, 0);

	}
}
