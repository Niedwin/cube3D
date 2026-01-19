/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_next_line.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guviure <guviure@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 17:19:03 by guviure           #+#    #+#             */
/*   Updated: 2026/01/18 23:16:33 by guviure          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

char	*append_char_to_line(char *line, char c, ssize_t *line_length)
{
	if (!ft_realloc((void **)&line, *line_length, *line_length + 2))
		return (NULL);
	line[(*line_length)++] = c;
	line[*line_length] = '\0';
	return (line);
}

int process_buffer_segment(char *buffer, ssize_t *index,
        ssize_t bytes_read, char **line, ssize_t *line_length)
{
    while (*index < bytes_read)
    {
        *line = append_char_to_line(*line, buffer[*index], line_length);
        if (buffer[*index] == '\n')
        {
            (*index)++;
            return (1); // ligne complète
        }
        (*index)++;
    }
    return (0); // pas encore de ligne complète
}

ssize_t read_into_buffer(int fd, char *buffer)
{
    ssize_t bytes = read(fd, buffer, BUFFER_SIZE);
    if (bytes < 0)
        return -1;
    if (bytes < BUFFER_SIZE)
        buffer[bytes] = '\0';
    return bytes;
}


char *ft_get_next_line(int fd)
{
    static char buffer[BUFFER_SIZE];
    static ssize_t bytes_read = 0;
    static ssize_t buffer_index = 0;
    char *line = NULL;
    ssize_t line_length = 0;
    int done = 0;

    if (fd < 0 || BUFFER_SIZE <= 0)
        return NULL;
    while (!done)
    {
        if (buffer_index >= bytes_read)
        {
            bytes_read = read_into_buffer(fd, buffer);
            buffer_index = 0;
            if (bytes_read <= 0)
                return line;
        }
        done = process_buffer_segment(buffer, &buffer_index,
                bytes_read, &line, &line_length);
    }
    return line;
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
