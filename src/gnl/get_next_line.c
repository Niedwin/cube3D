/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guviure <guviure@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 17:19:03 by guviure           #+#    #+#             */
/*   Updated: 2026/02/04 13:04:03 by guviure          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "../cube.h"

char	*append_char_to_line(char *line, char c, ssize_t *line_length)
{
	if (!ft_realloc((void **)&line, *line_length, *line_length + 2))
		return (NULL);
	line[(*line_length)++] = c;
	line[*line_length] = '\0';
	return (line);
}

char	*process_buffer(char *line, char *buffer,
			ssize_t *index, ssize_t *line_length)
{
	while (buffer[(*index)])
	{
		if (buffer[*index] == '\n')
		{
			line = append_char_to_line(line, buffer[*index], line_length);
			(*index)++;
			return (line);
		}
		line = append_char_to_line(line, buffer[*index], line_length);
		(*index)++;
	}
	return (line);
}

char	*get_next_line(int fd)
{
	static char		buffer[BUFFER_SIZE];
	static ssize_t	bytes_read;
	static ssize_t	buffer_index;
	char			*line;
	ssize_t			line_length;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	line = NULL;
	line_length = 0;
	while (1)
	{
		if (buffer_index >= bytes_read)
		{
			bytes_read = read(fd, buffer, BUFFER_SIZE);
			buffer_index = 0;
			if (bytes_read < 0)
				return (free(line), line = NULL, NULL);
			buffer[bytes_read] = 0;
		}
		line = process_buffer(line, buffer, &buffer_index, &line_length);
		if (buffer[buffer_index - 1] == '\n' || bytes_read == 0)
			return (line);
	}
}
/*
#include <stdio.h>

int main(void)
{
    int fd;
    char *line;

    // Ouvrir le fichier texte.txt en lecture seule
    fd = open("texte.txt", O_RDONLY);
    if (fd == -1)  // Si l'ouverture échoue
    {
        perror("Erreur d'ouverture du fichier");
        return (1);
    }

    // Lire le fichier ligne par ligne grâce à get_next_line
    while ((line = get_next_line(fd)) != NULL)
    {
        if (line != NULL) {
            printf("%s", line);  // Afficher la ligne
            free(line);  // Libérer la mémoire allouée pour la ligne
        }
    }

    // Fermer le fichier une fois terminé
    close(fd);

    return 0;
}*/
