/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_int.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbousouf <mbousouf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 22:08:49 by mbousouf          #+#    #+#             */
/*   Updated: 2023/02/06 15:25:08 by mbousouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	*get_image(t_data *data, char c)
{
	void	*img_ptr;

	if (c == '1')
		img_ptr = wall(data);
	if (c == '0')
		img_ptr = ground(data);
	if (c == 'C')
		img_ptr = col(data);
	if (c == 'P')
		img_ptr = player(data);
	if (c == 'E')
		img_ptr = ext(data);
	if (!data->img->g)
		ground(data);
	return (img_ptr);
}

void	dimension(char *s, t_map *map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	map->m = track_track(s);
	while (map->m[i])
	{
		while (map->m[i][j])
		{
			j++;
		}
		map->wid = j;
		j = 0;
		i++;
	}
	map->hght = i;
	check_col(track_track(s));
}

void	draw_map(t_data *data, t_map *map)
{
	int		i;
	int		j;
	void	*img;

	i = 0;
	j = 0;
	while (i < map->hght)
	{
		while (j < map->wid)
		{
			img = get_image(data, map->m[i][j]);
			mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, img,
				j * 50, i * 50);
			j++;
		}
		j = 0;
		i++;
	}
}

int	key(int keycode, t_data *data)
{
	find_p(data->map);
	if (keycode == 126 || keycode == 13)
		move_up(data);
	else if (keycode == 125 || keycode == 1)
		move_down(data);
	else if (keycode == 124 || keycode == 2)
		move_right(data);
	else if (keycode == 123 || keycode == 0)
		move_left(data);
	else if (keycode == 53)
	{
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
		double_f(data->map->m);
		my_free(data->mem);
		exit(0);
	}
	return (0);
}
// void leak(void)
// {
// 	system("leaks so_long");
// }


