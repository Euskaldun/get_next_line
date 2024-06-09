/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josantia <josantia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 17:59:45 by josantia          #+#    #+#             */
/*   Updated: 2024/06/07 21:32:17 by josantia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char		*line;
	static char	*buffer;

	if (BUFFER_SIZE < 1 || fd < 0)
		return (NULL);
	buffer = ft_find_line(fd, buffer);
	if (!buffer)
		return (NULL);
	line = ft_get_line(buffer);
	buffer = ft_overload(buffer);
	return (line);
}

char	*ft_find_line(int fd, char *buffret)
{
	char		buff[BUFFER_SIZE + 1];
	int			read_chars;

	read_chars = 1;
	while ((read_chars > 0) && !ft_strchr(buffret, '\n'))
	{
		read_chars = read(fd, buff, BUFFER_SIZE);
		if (read_chars == -1)
		{
			free(buffret);
			return (NULL);
		}
		buff[read_chars] = '\0';
		buffret = ft_strjoin(buffret, buff);
		if (!buffret)
		{
			free(buffret);
			return (NULL);
		}
	}
	if (read_chars == -1)
		free(buffret);
	return (buffret);
}

char	*ft_get_line(char *buffer)
{
	int		i;
	char	*ret_line;

	i = 0;
	if (!buffer[i])
		return (NULL);
	while (buffer[i] && buffer[i] != '\n')
		i++;
	ret_line = ft_calloc((i + 2), sizeof(char));
	if (!ret_line)
		return (NULL);
	if (buffer[i] == '\n')
		ret_line[i + 1] = '\0';
	while (i >= 0)
	{
		ret_line[i] = buffer[i];
		i--;
	}
	return (ret_line);
}

char	*ft_overload(char *buffer)
{
	size_t	i;
	size_t	j;
	char	*overline;

	i = 0;
	j = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (!buffer[i])
	{
		free (buffer);
		return (NULL);
	}
	overline = ft_calloc((ft_strlen(buffer) - i + 1), sizeof(char));
	if (!overline)
		return (NULL);
	i++;
	while (buffer[i])
		overline[j++] = buffer[i++];
	overline[j] = '\0';
	free (buffer);
	return (overline);
}
