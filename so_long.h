/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbousouf <mbousouf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 12:41:15 by mbousouf          #+#    #+#             */
/*   Updated: 2023/02/03 19:24:03 by mbousouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #ifndef "SO_LONG_H"
// #define "SO_LONG_H"

#include "mlx.h"
#include "map.h"
#include "ft_print/ft_printf.h"

typedef struct s_map
{
	char **m;
	int	wid;
	int	hght;
	int p_x;
	int p_y;
}	t_map;
typedef struct s_images
{
	void	*g;
	void	*w;
	void	*p;
	void	*e;
	void	*c;
}t_images;
typedef struct s_xpm
{
    int widht;
    int hieght;
} t_xmp;

typedef struct s_data
{
	void	*mlx_ptr;
	void	*win_ptr;
	int		moves;
	t_map	*map;
	t_xmp	*xmp;
	t_images *img;
}t_data;
void	move_up(t_data *data);
void	move_down(t_data *data);
void	move_left(t_data *data);
void	move_right(t_data *data);
void	draw_map(t_data *data, t_map *map,t_xmp *xmp);
// #endif