/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbousouf <mbousouf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 12:41:15 by mbousouf          #+#    #+#             */
/*   Updated: 2023/02/08 22:52:50 by mbousouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "mlx.h"
# include "mandatory/map.h"
# include "ft_print/ft_printf.h"

typedef struct s_map
{
	char	**m;
	int		wid;
	int		hght;
	int		p_x;
	int		p_y;
	int		col;
}	t_map;
typedef struct s_images
{
	void	*g;
	void	*w;
	void	*p;
	void	*e;
	void	*c;
	void	*eo;
}t_images;
typedef struct s_xpm
{
	int	widht;
	int	hieght;
}	t_xmp;

typedef struct s_data
{
	void		*mlx_ptr;
	void		*win_ptr;
	int			moves;
	t_map		*map;
	t_xmp		*xmp;
	t_images	*img;
	t_mem		*mem;
}t_data;
void	move_up(t_data *data);
void	move_down(t_data *data);
void	move_left(t_data *data);
void	move_right(t_data *data);
void	draw_map(t_data *data, t_map *map);
void	*wall(t_data *data);
void	*ground(t_data *data);
void	*col(t_data *data);
void	*player(t_data *data);
void	*ext(t_data *data);
void	xpm_check(t_data *data, char *s, t_xmp *xmp);
void	*get_image(t_data *data, char c);
void	find_p(t_map *map);
void	data_init(t_data *data, t_map *map, t_xmp *xmp, t_images *img);
int		key(int keycode, t_data *data);
void	*send_image(t_data *data, char c);
void	num_col(t_data *data);
int		exit_by(t_data *data);
void	so_long(t_data *data, char *s);
void	dimension(char *s, t_map *map);
void	draw_map(t_data *data, t_map *map);
void	*ft_calloc(size_t count, size_t size);
#endif