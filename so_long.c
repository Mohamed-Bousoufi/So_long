/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbousouf <mbousouf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 22:11:41 by mbousouf          #+#    #+#             */
/*   Updated: 2023/02/05 22:24:14 by mbousouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "map.h"

void	so_long(t_data *data, char *s)
{
	data->mlx_ptr = mlx_init();
	if (!data->mlx_ptr)
	{
		perror("Memory Error");
		exit(1);
	}
	dimension(s, data->map);
		data->win_ptr = mlx_new_window(data->mlx_ptr, 50 * data->map->wid,
			50 * data->map->hght, "WOW");
	if (!data->win_ptr)
	{
		perror("Mlx Error");
		exit(1);
	}
	num_col(data);
	draw_map(data, data->map);
	mlx_hook(data->win_ptr, 2, 0, &key, data);
	mlx_hook(data->win_ptr, 17, 1L, &exit_by, data);
	mlx_loop(data->mlx_ptr);
}
