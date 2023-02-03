#ifndef MAP_H
#define MAP_H


#include <errno.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <limits.h>
# include<stdio.h>
#include <fcntl.h>

#define MAX	100

typedef struct s_num
{
	int arg_p;
	int arg_e;
	int	arg_c;
} t_num;

 typedef struct s_mem
{
	void * garbage[MAX];
	int num;

}	t_mem;

char    *ft_join(char *s1, char *s2);
size_t	ft_strlen(const char *s);
char	*ft_strjoin(char  *s1, char  *s2,t_mem *mem);
int	ft_strncmp(const char *s1, const char *s2, size_t count);
char	*ft_strstr(char *h, char *n);
char	*ft_substr(const char *s, unsigned int start, size_t len);
char	**ft_split(char const *s, char c);
char	*ft_strdup(const char *s1);
void    ft_error(int);
void	double_f(char **map);
char	**track_track(char *s);
char	**check_col(char **map);
char	*empty_check(char *s,t_mem *mem);
void *my_malloc(size_t size,t_mem *mem);
void my_free(t_mem *mem);
void	first_check(char *s);
char	*get_next_line(int fd);
#endif