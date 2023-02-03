/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_int.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbousouf <mbousouf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 22:08:49 by mbousouf          #+#    #+#             */
/*   Updated: 2023/02/03 23:47:39 by mbousouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "mlx.h"

void xpm_check(t_data *data, char *s, t_xmp *xmp)
{
	if (!(mlx_xpm_file_to_image(data->mlx_ptr, s,
				&xmp->widht, &xmp->hieght)))
	{
		perror("xpm_not_found");
		exit(1);
	}
}

void	*get_image(t_data *data, char c, t_xmp *xmp)
{
	void *img_ptr;

	if (c == '1')
	{
		xpm_check(data, "images/wall.xpm", xmp);
		img_ptr = mlx_xpm_file_to_image(data->mlx_ptr, "images/wall.xpm",
				&xmp->widht, &xmp->hieght);
		data->img->w = img_ptr;
	}
	if (c == '0')
	{
		xpm_check(data, "images/ground.xpm", xmp);
		img_ptr = mlx_xpm_file_to_image(data->mlx_ptr, "images/ground.xpm",
				&xmp->widht, &xmp->hieght);
		data->img->g = img_ptr;
	}
	if (c == 'C')
	{
		xpm_check(data, "images/col.xpm", xmp);
		img_ptr = mlx_xpm_file_to_image(data->mlx_ptr, "images/col.xpm",
				&xmp->widht, &xmp->hieght);
		data->img->c = img_ptr;
	}
	if (c == 'P')
	{
		xpm_check(data, "images/player.xpm", xmp);
		img_ptr = mlx_xpm_file_to_image(data->mlx_ptr, "images/player.xpm",
				&xmp->widht, &xmp->hieght);
		data->img->p = img_ptr;
	}
	if (c == 'E')
	{
		xpm_check(data, "images/exit.xpm", xmp);
		img_ptr = mlx_xpm_file_to_image(data->mlx_ptr, "images/exit.xpm",
				&xmp->widht, &xmp->hieght);
		data->img->e = img_ptr;
	}
	return (img_ptr);
}

void dimension(char *s, t_map *map)
{
	int i;
	int j;

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

void draw_map(t_data *data, t_map *map, t_xmp *xmp)
{
	int i;
	int j;
	void *img;

	i = 0;
	j = 0;
	while (i < map->hght)
	{
		while (j < map->wid)
		{
			img = get_image(data, map->m[i][j], xmp);
			mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, img,
				j * 50, i * 50);
			j++;
		}
		j = 0;
		i++;
	}
}

void find_p(t_map *map)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (map->m[i])
	{
		while (map->m[i][j])
		{
			if (map->m[i][j] == 'P')
			{
				map->p_x = j;
				map->p_y = i;
			}
			j++;
		}
		j = 0;
		i++;
	}
}

int key(int keycode, t_data *data)
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
		draw_map(data, data->map, data->xmp);
	}
	return (0);
}
int main(int argc ,char **argv)
{
	t_mem *mem;
	t_data *data;
	t_map *map;
	t_xmp *xmp;
	t_images *img;

	if(argc == 2)
	{
		mem = calloc(sizeof(t_mem), MAX);
		data = my_malloc(sizeof(t_data), mem);
		xmp = my_malloc(sizeof(t_xmp), mem);
		map = my_malloc(sizeof(t_map), mem);
		img = my_malloc(sizeof(t_images), mem);
		data->moves = 0;
		data->map = map;
		data->xmp = xmp;
		data->img = img;
		data->mlx_ptr = mlx_init();
		dimension(argv[1], map);
		data->win_ptr = mlx_new_window(data->mlx_ptr, 50 * map->wid, 50 * map->hght, "WOW");
		draw_map(data, map, xmp);
		mlx_hook(data->win_ptr, 2, 0, &key, data);
		mlx_loop(data->mlx_ptr);
	}
}