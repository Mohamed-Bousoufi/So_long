/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validator.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbousouf <mbousouf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 17:46:43 by mbousouf          #+#    #+#             */
/*   Updated: 2023/02/10 20:17:48 by mbousouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

char	*empty_check(char *s, t_mem *mem)
{
	char	*line;
	char	*tmp;
	int		fd;

	line = NULL;
	tmp = NULL;
	first_check(s);
	fd = open(s, O_RDONLY);
	if (fd == -1)
		ft_error(1);
	line = get_next_line(fd);
	if (!line)
		ft_error(2);
	while (line)
	{
		mem->garbage[mem->num++] = line;
		tmp = ft_strjoin(tmp, line, mem);
		line = get_next_line(fd);
	}
	check_dem(tmp);
	close(fd);
	return (tmp);
}

void	check_wall_b(char **map, int x, int y)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < x)
	{
		while (j < y)
		{
			if (i == x - 1)
				if (map[i][j] != '1')
					ft_error(5);
			if (j == y - 1)
				if (map[i][j] != '1')
					ft_error(5);
			j++;
		}
		j = 0;
		i++;
	}
}

char	**check_ar(char *s)
{
	char	**map;
	int		i;
	int		j;
	int		len;

	i = -1;
	j = -1;
	len = 0;
	map = ft_split(s, '\n');
	while (map[++i])
	{
		while (map[i][++j])
		{
			if (map[i][j] != '0' && map[i][j] != '1' && map[i][j] != 'P'
			&& map[i][j] != 'C' && map[i][j] != 'E')
				ft_error(3);
			if (i == 0)
				len = j +1;
		}
		if (j != len)
			ft_error(4);
		j = -1;
	}
	check_wall_b(map, i, len);
	return (map);
}

void	nbr_arg(char **map)
{
	int		i;
	int		j;
	t_num	com;

	i = -1;
	com.arg_p = 0;
	com.arg_e = 0;
	com.arg_c = 0;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			if (map[i][j] == 'P')
				com.arg_p += 1;
			if (map[i][j] == 'E')
				com.arg_e += 1;
			if (map[i][j] == 'C')
				com.arg_c += 1;
		}
	}
	if (com.arg_p != 1 || com.arg_e != 1 || com.arg_c < 1)
		ft_error(3);
}

void	check_wall_a(char **map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (map[i])
	{
		while (map[i][j])
		{
			if (i == 0)
				if (map[i][j] != '1')
					ft_error(5);
			if (j == 0)
				if (map[i][j] != '1')
					ft_error(5);
			j++;
		}
		j = 0;
		i++;
	}
}
