/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbousouf <mbousouf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 17:54:53 by mbousouf          #+#    #+#             */
/*   Updated: 2023/02/06 19:37:59 by mbousouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}

char	*ft_strjoin(char *s1, char *s2, t_mem *mem)
{
	size_t	s1len;
	size_t	s2len;
	char	*ptr;
	int		j;

	if (!s1)
		return ((char *)s2);
	j = -1;
	s1len = ft_strlen(s1);
	s2len = ft_strlen(s2);
	ptr = (char *)my_malloc(s2len + s1len + 1, mem);
	if (!ptr)
		return (NULL);
	while (++j < (int)s1len)
			ptr[j] = s1[j];
	j = 0;
	while (s2len)
	{
			ptr[s1len++] = s2[j++];
				s2len--;
	}
		ptr[s1len+s2len] = '\0';
	return (ptr);
}

int	ft_strncmp(const char *s1, const char *s2, size_t count)
{
	size_t	i;

	i = -1;
	while (++i < count && (s1[i] || s2[i]))
	{
		if (s2[i] != s1[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
	}
	return (0);
}

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	int		i;
	char	*p;

	i = 0;
	if (*s == '\0' && len)
		return (0);
	if (start >= (unsigned int)ft_strlen(s))
	{
		return (ft_strdup(""));
	}
	if (len > ft_strlen(s) - start)
		len = ft_strlen(s) - start;
	p = (char *)malloc(len + 1);
	if (!p)
	{
		return (NULL);
	}
	while (len)
	{
		p[i] = s[start + i];
		i++;
		len--;
	}
	p[i] = '\0';
	return (p);
}

char	*ft_strdup(const char *s1)
{
	char	*p;
	size_t	i;

	i = 0;
	if (!s1)
		return (NULL);
	p = (char *)malloc(ft_strlen(s1) + 1);
	if (!p)
		return (0);
	while (i < ft_strlen(s1))
	{
		p[i] = s1[i];
		i++;
	}
	p[i] = 0;
	return (p);
}
