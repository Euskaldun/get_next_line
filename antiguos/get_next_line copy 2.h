/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josantia <josantia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 18:17:40 by josantia          #+#    #+#             */
/*   Updated: 2024/06/04 05:16:57 by josantia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#define BUFFER_SIZE 1
#define FD_SIZE  1024
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>



char	*get_next_line(int fd);
char	*ft_find_line(int fd, char *buffret);
char	*ft_get_line(char *buffer);
char	*ft_overload(char *buffer);
char	*ft_merge(char *buff, char *temp);

char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strchr(const char *string, int searchedChar);
void	ft_bzero(void *s, size_t n);
void	*ft_calloc(size_t elementCount, size_t elementSize);
size_t	ft_strlen(const char *theString);
