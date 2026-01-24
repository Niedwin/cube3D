/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_next_line.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guviure <guviure@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/24 17:35:10 by guviure           #+#    #+#             */
/*   Updated: 2026/01/24 17:40:44 by guviure          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 1024
#endif

char	*ft_get_next_line(int fd)
{
	static t_gnl_data	data = {.bytes_read = 0, .buffer_index = 0};
	t_gnl_state			state;
	int					result;

	state.line = NULL;
	state.line_length = 0;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	while (1)
	{
		if (data.buffer_index >= data.bytes_read)
		{
			if (gnl_handle_buffer_refill(fd, &data))
				return (state.line);
		}
		result = gnl_process_buffer_segment(data.buffer, &data.buffer_index,
				data.bytes_read, &state);
		if (result == -1)
			return (NULL);
		if (result == 1)
			return (state.line);
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
