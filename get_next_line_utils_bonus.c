/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josantia <josantia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 18:33:26 by josantia          #+#    #+#             */
/*   Updated: 2024/06/28 18:09:37 by josantia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_strjoin(char *s1, char *s2)
{
	char	*ret;
	size_t	i;
	size_t	j;

	if (!s1)
		s1 = ft_calloc(1, sizeof(char));
	if (!s1)
		return (NULL);
	ret = ft_calloc((ft_strlen(s1) + ft_strlen(s2) + 1), sizeof(char));
	if (!ret)
		return (NULL);
	i = 0;
	while (s1[i] && s1[i] != '\0')
	{
		ret[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j] && s2[j] != '\0')
		ret[i++] = s2[j++];
	ret[ft_strlen(s1) + ft_strlen(s2)] = '\0';
	free (s1);
	return (ret);
}

char	*ft_strchr(const char *s, int c)
{
	char	*mark;

	mark = NULL;
	if (!s)
		return (NULL);
	while (*s)
	{
		if (*s == c)
		{
			mark = (char *)s;
			return (mark);
		}
		else
			s++;
	}
	return (mark);
}

void	ft_bzero(void *s, size_t n)
{
	char	*str;
	size_t	i;

	str = (char *)s;
	i = 0;
	while (i < n)
	{
		str[i] = '\0';
		i++;
	}
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*ret;

	ret = malloc (size * count);
	if (!ret)
		return (NULL);
	ft_bzero(ret, size * count);
	return (ret);
}

size_t	ft_strlen(const char *s)
{
	size_t	count;

	count = 0;
	while (*s != '\0')
	{
		count++;
		s++;
	}
	return (count);
}
