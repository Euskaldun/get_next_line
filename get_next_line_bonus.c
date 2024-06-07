/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josantia <josantia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 17:59:45 by josantia          #+#    #+#             */
/*   Updated: 2024/06/07 22:16:06 by josantia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_next_line(int fd)
{
	char		*line;
	static char	*buffer[1024];

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (NULL);
	buffer[fd] = ft_find_line(fd, buffer[fd]);
	if (buffer[fd] == NULL)
		return (NULL);
	line = ft_get_line(buffer[fd]);
	buffer[fd] = ft_overload(buffer[fd]);
	return (line);
}

char	*ft_find_line(int fd, char *buffret)
{
	int		read_chars;
	char	*bufftemp;

	read_chars = 1;
	if (!buffret)
		buffret = ft_calloc(1, 1);
	if (!ft_strchr(buffret, '\n'))
	{
		bufftemp = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
		while ((read_chars > 0) && !ft_strchr(buffret, '\n'))
		{
			read_chars = read(fd, bufftemp, BUFFER_SIZE);
			if (read_chars == -1)
			{
				free(bufftemp);
				return (NULL);
			}
			bufftemp[read_chars] = '\0';
			buffret = ft_merge(buffret, bufftemp);
		}
		free(bufftemp);
	}
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
	while (i >= 0)
	{
		ret_line[i] = buffer[i];
		i--;
	}
	return (ret_line);
}

char	*ft_overload(char *buffer)
{
	int		i;
	int		j;
	char	*overline;

	i = 0;
	j = 0;
	while (buffer[i] != '\0' && buffer[i] != '\n')
		i++;
	if (buffer[i] == '\0')
	{
		free(buffer);
		return (NULL);
	}
	overline = ft_calloc((ft_strlen(buffer) - i + 1), sizeof(char));
	if (!overline)
		return (NULL);
	i++;
	while (buffer[i])
		overline[j++] = buffer[i++];
	overline[j + 1] = '\0';
	free(buffer);
	return (overline);
}

char	*ft_merge(char *buff, char *temp)
{
	char	*ret;

	ret = ft_strjoin(buff, temp);
	free(buff);
	return (ret);
}
