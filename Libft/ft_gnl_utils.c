/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gnl_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guviure <guviure@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/24 17:40:12 by guviure           #+#    #+#             */
/*   Updated: 2026/01/24 17:41:47 by guviure          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 1024
#endif

char	*gnl_append_char(char *line, char c, ssize_t *line_length)
{
	if (!ft_realloc((void **)&line, *line_length, *line_length + 2))
		return (NULL);
	line[(*line_length)++] = c;
	line[*line_length] = '\0';
	return (line);
}

int	gnl_process_one_char(char **line, char c, ssize_t *line_length)
{
	*line = gnl_append_char(*line, c, line_length);
	if (!*line)
		return (-1);
	if (c == '\n')
		return (1);
	return (0);
}

int	gnl_process_buffer_segment(char *buffer, ssize_t *index,
		ssize_t bytes_read, t_gnl_state *state)
{
	int	result;

	while (*index < bytes_read)
	{
		result = gnl_process_one_char(&state->line, buffer[*index],
				&state->line_length);
		if (result == -1)
			return (-1);
		(*index)++;
		if (result == 1)
			return (1);
	}
	return (0);
}

ssize_t	gnl_read_into_buffer(int fd, char *buffer)
{
	ssize_t	bytes;

	bytes = read(fd, buffer, BUFFER_SIZE);
	if (bytes < 0)
		return (-1);
	if (bytes < BUFFER_SIZE)
		buffer[bytes] = '\0';
	return (bytes);
}

int	gnl_handle_buffer_refill(int fd, t_gnl_data *data)
{
	data->bytes_read = gnl_read_into_buffer(fd, data->buffer);
	data->buffer_index = 0;
	if (data->bytes_read <= 0)
		return (1);
	return (0);
}
