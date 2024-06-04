/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josantia <josantia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 17:59:45 by josantia          #+#    #+#             */
/*   Updated: 2024/06/04 05:20:10 by josantia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "get_next_line.h"


char	*get_next_line(int fd)
{
	char		*line;
	static char	*buffer;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (NULL);
	buffer = ft_find_line(fd, buffer);
	if (buffer == NULL)
		return (NULL);
	line = ft_get_line(buffer);
	buffer = ft_overload(buffer);
	return (line);
}

char	*ft_find_line(int fd, char *buffret)
{
	int		read_chars;
	char	*temp;

    read_chars = 1;
	if (!buffret)
		buffret = ft_calloc(1, 1);
	temp = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	while (read_chars > 0 && !ft_strchr(buffret, '\n'))
	{
		read_chars = read(fd, temp, BUFFER_SIZE);
		if (read_chars == -1)
		{
			free(temp);
			return (NULL);
		}
		temp[read_chars] = '\0';
		buffret = ft_merge(buffret, temp);
//		if (ft_strchr(buffret, '\n'))
//			break ;
	}
	free(temp);
	return (buffret);
}






char	*ft_get_line(char *buffer)
{
    int i;
    char *ret_line;

    i = 0;
    if (!buffer[i])
        return (NULL);
    while(buffer[i] && buffer[i]!= '\n')
        i++;
    ret_line = ft_calloc((i + 2), sizeof(char));
    while(i >= 0)
    {
        ret_line[i]= buffer[i];
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
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (!buffer[i])
	{
		free(buffer);
		return (NULL);
	}
	overline = ft_calloc((ft_strlen(buffer) - i + 1), sizeof(char));
	i++;
    while (buffer[i])
    {
        overline[j] = buffer[i];
        i++;
        j++;
    }
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













