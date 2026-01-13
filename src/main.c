/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kguillem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 13:40:37 by kguillem          #+#    #+#             */
/*   Updated: 2026/01/13 18:56:53 by kguillem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

int	main(int argc, char **argv)
{
	t_header	*header;

	header = malloc(sizeof(t_header));
	header->fd = check_args_n_fd(argc, argv);
	initialize_struct(header);
	printf("struct check !\n\nfd : %d\n\n", header->fd);
	printf("ceiling : %s\nfloor : %s\n\n", header->ceiling, header->floor);
	printf("north : %s\nsouth : %s\neast : %s\nwest : %s\n\n", header->north, header->south, header->east, header->west);
	printf("map : %p\n\nplayer X axis : %u\nplayer Y axis : %u\n", header->map, header->pos[0], header->pos[1]);
	close(header->fd);
	free(header);
	return (0);
}
