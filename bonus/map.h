/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbousouf <mbousouf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 15:27:30 by mbousouf          #+#    #+#             */
/*   Updated: 2023/02/08 23:25:43 by mbousouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
# define MAP_H

# include <errno.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <limits.h>
# include<stdio.h>
# include <fcntl.h>

# define MAX	1000

typedef struct s_num
{
	int	arg_p;
	int	arg_e;
	int	arg_c;
	int	arg_n;
}	t_num;

typedef struct s_mem
{
	void	*garbage[MAX];
	int		num;

}	t_mem;

typedef struct s_player
{
	int		x;
	int		y;
}	t_player;

char	*ft_join(char *s1, char *s2);
size_t	ft_strlen(const char *s);
char	*ft_strjoin(char	*s1, char	*s2, t_mem *mem);
int		ft_strncmp(const char *s1, const char *s2, size_t count);
char	*ft_strstr(char *h, char *n);
char	*ft_substr(const char *s, unsigned int start, size_t len);
char	**ft_split(char const *s, char c);
char	*ft_strdup(const char *s1);
void	ft_error(int n, t_mem *mem);
void	double_f(char **map);
void	check_dem(char *s, t_mem *mem);
void	first_check(char *s, t_mem *mem);
char	*empty_check(char *s, t_mem *mem);
void	check_wall_b(char **map, int x, int y, t_mem *mem);
char	**check_ar(char *s, t_mem *mem);
void	nbr_arg(char **map, t_mem *mem);
void	check_wall_a(char **map, t_mem *mem);
char	**track_track(char *s);
void	check_col(char **map);
char	*empty_check(char *s, t_mem *mem);
void	*my_malloc(size_t size, t_mem *mem);
void	my_free(t_mem *mem);
char	*get_next_line(int fd);
void	check_c(char **map);
void	exist(char **map);
void	find_path(int x, int y, char **map);
char	**check_path(int x, int y, char **map);
char	**find_player(char **map);
#endif