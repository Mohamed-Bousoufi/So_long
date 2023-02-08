/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbousouf <mbousouf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 15:36:59 by mbousouf          #+#    #+#             */
/*   Updated: 2023/02/08 16:45:15 by mbousouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

void	*enemy(t_data *data)
{
	void	*img_ptr;

	img_ptr = NULL;
	xpm_check(data, "images/1.xpm", data->xmp);
		img_ptr = mlx_xpm_file_to_image(data->mlx_ptr, "images/1.xpm",
			&data->xmp->widht, &data->xmp->hieght);
			data->img->n = img_ptr;
	return (img_ptr);
}

void	end(t_data *data, int n)
{
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	double_f(data->map->m);
	my_free(data->mem);
	if (n == 0)
		ft_printf("YOU WIN");
	if (n == 1)
		ft_printf("YOU LOSE");
	exit(0);
}
