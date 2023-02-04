/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_int.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbousouf <mbousouf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 22:08:49 by mbousouf          #+#    #+#             */
/*   Updated: 2023/02/04 22:43:35 by mbousouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
	if (keycode == 126)
		move_up(data);
	else if (keycode == 125)
		move_down(data);
	else if (keycode == 124)
		move_right(data);
	else if (keycode == 123)
		move_left(data);
	else
	{
		mlx_clear_window(data->mlx_ptr, data->win_ptr);
		draw_map(data, data->map);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_mem		*mem;
	t_data		*data;
	t_map		*map;
	t_xmp		*xmp;
	t_images	*img;

	mem = calloc(sizeof(t_mem), MAX);
	data = my_malloc(sizeof(t_data), mem);
	xmp = my_malloc(sizeof(t_xmp), mem);
	map = my_malloc(sizeof(t_map), mem);
	img = my_malloc(sizeof(t_images), mem);
	data_init(data, map, xmp, img);
	data->mem = mem;
	if (argc == 2)
	{
		data->mlx_ptr = mlx_init();
		dimension(argv[1], map);
		data->win_ptr = mlx_new_window(data->mlx_ptr, 50 * map->wid,
				50 * map->hght, "WOW");
		num_col(data);
		draw_map(data, map);
		mlx_hook(data->win_ptr, 2, 0, &key, data);
		// system("leaks so_long");
		mlx_loop(data->mlx_ptr);
	}
}
