/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josantia <josantia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 18:17:40 by josantia          #+#    #+#             */
/*   Updated: 2024/06/04 02:28:10 by josantia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


# define BUFFER_SIZE 1
# define FD_SIZE  1024


char *get_next_line(int fd);
char *read_line (int fd, char *ret);
char *ft_get_line(char *buffer);
void	*ft_calloc(size_t count, size_t size);
void	ft_bzero(void *str, size_t n);
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlen(const char *str);
int ft_find(const char *str, int c);