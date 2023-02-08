/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbousouf <mbousouf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 18:14:58 by mbousouf          #+#    #+#             */
/*   Updated: 2023/02/08 16:43:29 by mbousouf         ###   ########.fr       */
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

void	enemy_animation(t_data *data, char *s)
{
	int	i;
	int	j;

	i = 0;
	while (i < data->map->hght)
	{
		j = 0;
		while (j < data->map->wid)
		{
			if (data->map->m[i][j] == 'N')
			{
				redraw(data, i, j, s);
			}
			j++;
		}
		i++;
	}
}

int	genrate(t_data *data)
{
	static int	i;

	genrate_col(data);
	if (i % 4 == 0)
	{
		xpm_check(data, "images/1.xpm", data->xmp);
		enemy_animation(data, "images/1.xpm");
	}
	if (i % 4 == 1)
	{
		xpm_check(data, "images/2.xpm", data->xmp);
		enemy_animation(data, "images/2.xpm");
	}
	if (i % 4 == 2)
	{
		xpm_check(data, "images/3.xpm", data->xmp);
		enemy_animation(data, "images/3.xpm");
	}
	if (i % 4 == 3)
	{
		xpm_check(data, "images/4.xpm", data->xmp);
		enemy_animation(data, "images/4.xpm");
	}
	i++;
	return (0);
}

void	redraw(t_data *data, int i, int j, char *s)
{
	void	*img;

	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, \
		data->img->g, j * 50, i * 50);
	img = mlx_xpm_file_to_image(data->mlx_ptr, s,
			&data->xmp->widht, &data->xmp->hieght);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, \
		img, j * 50, i * 50);
}
