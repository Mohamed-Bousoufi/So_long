/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbousouf <mbousouf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 22:11:41 by mbousouf          #+#    #+#             */
/*   Updated: 2023/02/07 18:33:37 by mbousouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"
#include "map.h"

void	so_long(t_data *data, char *s)
{
	dimension(s, data->map);
	data->mlx_ptr = mlx_init();
	if (!data->mlx_ptr)
	{
		perror("Memory Error");
		exit(1);
	}
		data->win_ptr = mlx_new_window(data->mlx_ptr, 50 * data->map->wid,
			50 * data->map->hght, "WOW");
	if (!data->win_ptr)
	{
		perror("Mlx Error");
		exit(1);
	}
	num_col(data);
	draw_map(data, data->map);
	put_string(data);
	mlx_loop_hook(data->mlx_ptr, &genrate, data);
	mlx_hook(data->win_ptr, 2, 0, &key, data);
	mlx_hook(data->win_ptr, 17, 1L, &exit_by, data);
	mlx_loop(data->mlx_ptr);
}

// void	leak(void)
// {
// 	system("leaks so_long");
// }

int	main(int argc, char **argv)
{
	t_mem		*mem;
	t_data		*data;
	t_map		*map;
	t_xmp		*xmp;
	t_images	*img;

	mem = calloc(sizeof(t_mem), MAX);
	if (!mem)
	{
		perror("Error\nMemory Problem");
		exit(1);
	}
	// atexit(leak);
	data = my_malloc(sizeof(t_data), mem);
	xmp = my_malloc(sizeof(t_xmp), mem);
	map = my_malloc(sizeof(t_map), mem);
	img = my_malloc(sizeof(t_images), mem);
	data_init(data, map, xmp, img);
	data->mem = mem;
	if (argc == 2)
	{
		so_long(data, argv[1]);
	}
	else
		perror("Error\nArgument Not Correct Must be => ./So_long map");
}
