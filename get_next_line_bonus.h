/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josantia <josantia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 18:17:40 by josantia          #+#    #+#             */
/*   Updated: 2024/06/04 15:56:18 by josantia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h>
#include <sys/types.h>
#include <sys/uio.h>



#ifndef BUFFER_SIZE
#define BUFFER_SIZE 1024
#endif



char	*get_next_line(int fd);
char	*ft_find_line(int fd, char *buffret);
char	*ft_get_line(char *buffer);
char	*ft_overload(char *buffer);
char	*ft_merge(char *buff, char *temp);

char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strchr(const char *s, int c);
void	ft_bzero(void *s, size_t n);
void	*ft_calloc(size_t count, size_t size);
size_t	ft_strlen(const char *s);
