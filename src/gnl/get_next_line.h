/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guviure <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 17:20:31 by guviure           #+#    #+#             */
/*   Updated: 2025/01/24 00:11:37 by guviure          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

char	*get_next_line(int fd);
ssize_t	read(int fd, void *buf, size_t nbyte);
size_t	ft_realloc(void **buffer, size_t old_size, size_t nez_size);
void	*ft_memcpy(void *dest, const void *src, size_t n);
char	*process_buffer(char *line, char *buffer, ssize_t *index,
			ssize_t *line_length);
char	*append_char_to_line(char *line, char c, ssize_t *line_length);

#endif
