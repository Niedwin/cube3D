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

void test_struct(t_header *header)
{
	printf("struct check !\n\nfd : %d\n\n", header->fd);
	printf("ceiling : %s\nfloor : %s\n\n", header->ceiling, header->floor);
	printf("north : %s\nsouth : %s\n", header->north, header->south);
	printf("east : %s\nwest : %s\n\n", header->east, header->west);
	printf("map : %p\n\nplayer X axis : %u\n", header->map, header->pos[0]);
	printf("player Y axis : %u\n", header->pos[1]);	
}

int	main(int argc, char **argv)
{
	t_header	*header;
	int			*error;

	header = malloc(sizeof(t_header));

	header->fd = check_args_n_fd(argc, argv);//may check if file is empty 4 time

	initialize_struct(header, error);

	/*
	if (verify_header(header, error))
		test_struct(header);
	*/

	close(header->fd);
	
	free(header);
	return (0);
}
