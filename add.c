/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbousouf <mbousouf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 17:06:03 by mbousouf          #+#    #+#             */
/*   Updated: 2023/02/04 21:31:36 by mbousouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	xpm_check(t_data *data, char *s, t_xmp *xmp)
{
	if (!(mlx_xpm_file_to_image(data->mlx_ptr, s,
				&xmp->widht, &xmp->hieght)))
	{
		perror("xpm_not_found");
		exit(1);
	}
}

void	data_init(t_data *data, t_map *map, t_xmp *xmp, t_images *img)
{
		data->moves = 0;
		data->map = map;
		data->xmp = xmp;
		data->img = img;
		data->map->col = 0;
}

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

void	find_p(t_map *map)
{
	int	i;
	int	j;

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

void	num_col(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < data->map->hght)
	{
		while (j < data->map->wid)
		{
			if (data->map->m[i][j] == 'C')
				data->map->col++;
			j++;
		}
		j = 0;
		i++;
	}
}