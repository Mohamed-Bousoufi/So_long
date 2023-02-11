/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbousouf <mbousouf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 17:47:09 by mbousouf          #+#    #+#             */
/*   Updated: 2023/02/10 20:33:59 by mbousouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

void	double_f(char **map)
{
	int	i;

	i = 0;
	while (map && map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
	map = NULL;
}

void	*my_malloc(size_t size, t_mem *mem)
{
	void	*ptr;

	ptr = ft_calloc(1, size);
	if (!ptr)
	{
		my_free(mem);
		perror("memory_problem");
		exit(1);
	}
	mem->garbage[mem->num++] = ptr;
	return (ptr);
}

void	my_free(t_mem *mem)
{
	int	i;

	i = 0;
	while (mem && mem->garbage[i])
	{
		free(mem->garbage[i]);
		i++;
	}
	free(mem);
	mem = NULL;
}

void	ft_error(int n)
{
	if (n == 1)
		perror("Error\nber_File_Not_found");
	if (n == 2)
		perror("Error\n empty_file");
	if (n == 3)
		perror("Error\n map_argument_not_correct");
	if (n == 4)
		perror("Error\n dimension_of_map_not_correct(must_be_rectangle)");
	if (n == 5)
		perror("Error\n map_not_sorounded_with_wall");
	exit(1);
}

char	*ft_strstr(char *h, char *n)
{
	int		i;

	i = -1;
	if (n[0] == '\0' || h[0] == '\0')
		return (NULL);
	while (h[++i])
	{
		if (ft_strncmp(&h[i], n, ft_strlen(n)) == 0)
			return (&h[i]);
	}
	return (NULL);
}
