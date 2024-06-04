/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line copy.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josantia <josantia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 17:59:45 by josantia          #+#    #+#             */
/*   Updated: 2024/06/04 04:21:15 by josantia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "get_next_line.h"




int ft_find(const char *str, int c)
{
	int i;

	i = 0;
	while ((str)[i] != '\0')
	{
		if ((str)[i] == c)
		{
			return (1);
		}
		i++;
	}
	return (0);
}

size_t	ft_strlen(const char *str)
{
	size_t i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	int		a;
	int		b;
	int		i;

	if (!s1 || !s2)
		return (NULL);
	a = ft_strlen(s1);
	b = ft_strlen(s2);
	i = 0;
	if (!(str = malloc((a + b + 1))) || !str)
		return (NULL);
	while (a--)
	{
		str[i] = s1[i];
		i++;
	}
	a = i;
	i = 0;
	while (b--)
		str[a++] = s2[i++];
	str[a] = '\0';
	return (str);
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*result;

	result = malloc(count * size);
	if (!result)
		return (NULL);
	else
	{
		ft_bzero(result, (count * size));
		return (result);
	}
}

void	ft_bzero(void *str, size_t n)
{
	size_t i;

	i = 0;
	while (i < n)
	{
		((char*)str)[i] = 0;
		i++;
	}
}


/*
char *get_next_line(int fd)
{
    static char *buffer;
    char *line;
    if (fd < 0 || BUFFER_SIZE <= 0)
        return (NULL);
    buffer = read_file (fd, buffer);
    if (!buffer)
        return (NULL);
}

char    *read_file(int fd, char *buff)
{
    char *buffer;
    int     read_ok;

    if (!buff)
        ft_calloc(1, 1);
    buffer = ft_calloc(BUFFER_SIZE +1, sizeof(char));
    read_ok = 1;
    while (read_char > 0 && ft_strchr(buffer,'\n'))
    {
        read_ok = read(fd, buffer, BUFFER_SIZE);
        if (read_ok == -1)
        {
            free (buffer);
            return (NULL);
        }
        buffer[read_ok]= '\0';
        buff = ft_join_free(buff,buffer);
    }
    free (buffer);
    return (buff);
}

*/
char *ft_join_free(char *buff, char *buffer)
{
    char *temp;

    temp = ft_strjoin(buff, buffer);
    free (buff);
    return (temp);
}






char *get_next_line(int fd)
{
    static char *buffer;
    if (fd < 0 || BUFFER_SIZE <= 0)
        return (NULL);
    buffer = read_line (fd, buffer);
   
    if (!buffer)
        return (NULL);    
    return (ft_get_line(buffer));
}

char *ft_get_line(char *buffer)
{
    int i;
    char *ret;

    i = 0;
    if (!buffer)
        return (NULL);
    while(buffer[i] && buffer[i]!= '\n')
        i++;
    ret = malloc((i * sizeof(char)) + 1);
    ret [i] = '\n';
    i--;
    while(i > 0)
    {
        ret[i]= buffer[i];
        i--;
    }
    return (ret);
}




char *read_line (int fd, char *ret)
{
    int read_char;
    char *line;
    char *temp;

/*     if (!ret)
        ret = ft_calloc(1,1); */
    line = malloc((BUFFER_SIZE *sizeof(char)) + 1);
    read_char = 1;
   
    while (read_char > 0 && !ft_find(ret,'\n'))
    {
        read_char = read(fd, line, BUFFER_SIZE);
         if (read_char > 0)
        { 
            temp = ft_strjoin(ret, line);
            ret = temp;
        }
    }
    printf ("%s",ret);
    free (line);
    return (ret);
}






















