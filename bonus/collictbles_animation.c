/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collictbles_animation.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbousouf <mbousouf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 22:06:26 by mbousouf          #+#    #+#             */
/*   Updated: 2023/02/08 16:44:54 by mbousouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

void	col_animation(t_data *data, char *s)
{
	int	i;
	int	j;

	i = 0;
	while (i < data->map->hght)
	{
		j = 0;
		while (j < data->map->wid)
		{
			if (data->map->m[i][j] == 'C')
			{
				redraw(data, i, j, s);
			}
			j++;
		}
		i++;
	}
}

int	genrate_col(t_data *data)
{
	static int	i;
	int			j;

	j = 1;
	if (i % 2 == 0 && j == 1)
	{
		if (i % 3 == 0 && i % 11 == 0)
			j = 1;
		xpm_check(data, "images/col3.xpm", data->xmp);
		col_animation(data, "images/col3.xpm");
	}
	if (i % 2 == 1)
	{
		if (i % 5 == 0 && i % 7 == 0)
			j = 1;
		xpm_check(data, "images/col.xpm", data->xmp);
		col_animation(data, "images/col.xpm");
	}
	j = 0;
	i++;
	return (0);
}

void	redraw_col(t_data *data, int i, int j, char *s)
{
	void	*img;

	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, \
		data->img->g, j * 50, i * 50);
	img = mlx_xpm_file_to_image(data->mlx_ptr, s,
			&data->xmp->widht, &data->xmp->hieght);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, \
		img, j * 50, i * 50);
}
