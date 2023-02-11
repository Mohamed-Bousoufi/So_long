/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   imges.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbousouf <mbousouf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 15:38:39 by mbousouf          #+#    #+#             */
/*   Updated: 2023/02/10 20:33:20 by mbousouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	*wall(t_data *data)
{
	void	*img_ptr;

	img_ptr = NULL;
	xpm_check(data, "images/wall.xpm", data->xmp);
		img_ptr = mlx_xpm_file_to_image(data->mlx_ptr, "images/wall.xpm",
			&data->xmp->widht, &data->xmp->hieght);
			data->img->w = img_ptr;
	return (img_ptr);
}

void	*ground(t_data *data)
{
	void	*img_ptr;

	img_ptr = NULL;
	xpm_check(data, "images/ground.xpm", data->xmp);
		img_ptr = mlx_xpm_file_to_image(data->mlx_ptr, "images/ground.xpm",
			&data->xmp->widht, &data->xmp->hieght);
					data->img->g = img_ptr;
	return (img_ptr);
}

void	*col(t_data *data)
{
	void	*img_ptr;

	img_ptr = NULL;
	xpm_check(data, "images/col.xpm", data->xmp);
		img_ptr = mlx_xpm_file_to_image(data->mlx_ptr, "images/col.xpm",
			&data->xmp->widht, &data->xmp->hieght);
					data->img->c = img_ptr;
	return (img_ptr);
}

void	*player(t_data *data)
{
	void	*img_ptr;

	img_ptr = NULL;
	xpm_check(data, "images/player.xpm", data->xmp);
		img_ptr = mlx_xpm_file_to_image(data->mlx_ptr, "images/player.xpm",
			&data->xmp->widht, &data->xmp->hieght);
					data->img->p = img_ptr;
	return (img_ptr);
}

void	*ext(t_data *data)
{
	void	*img_ptr;
	void	*img_ptr1;

	img_ptr = NULL;
	xpm_check(data, "images/exit.xpm", data->xmp);
	xpm_check(data, "images/exit1.xpm", data->xmp);
	img_ptr = mlx_xpm_file_to_image(data->mlx_ptr, "images/exit.xpm",
			&data->xmp->widht, &data->xmp->hieght);
	img_ptr1 = mlx_xpm_file_to_image(data->mlx_ptr, "images/exit1.xpm",
			&data->xmp->widht, &data->xmp->hieght);
	data->img->e = img_ptr;
	data->img->eo = img_ptr1;
	return (img_ptr);
}
