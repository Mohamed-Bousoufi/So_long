/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbousouf <mbousouf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 15:40:03 by mbousouf          #+#    #+#             */
/*   Updated: 2023/02/10 22:42:53 by mbousouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# include "mlx.h"
# include "bonus/map.h"
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
	void	*n;
}	t_images;
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
void	*enemy(t_data *data);
void	put_string(t_data *data);
// void	redraw(t_data *data, void *img, int x, int y);
int		genrate(t_data *data);
void	enemy_animation(t_data *data, char *s);
void	end(t_data *data, int n);
char	*ft_itoa(int n);
void	col_animation(t_data *data, char *s);
void	redraw_col(t_data *data, int i, int j, char *s);
void	*ft_calloc(size_t count, size_t size);
void	magic(t_data *data);
void	col_animation(t_data *data, char *s);
int		genrate_col(t_data *data);
void	redraw_col(t_data *data, int i, int j, char *s);
#endif