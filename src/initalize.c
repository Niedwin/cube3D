/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initalize.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guviure <guviure@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 19:34:00 by guviure           #+#    #+#             */
/*   Updated: 2026/01/13 18:20:49 by kguillem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

//TODO test if properly handles empty files and is to Norme
int	check_args_n_fd(int argc, char **argv)
{
	int	fd;

	if (argc != 2 || argv[1][0] == '\0')
	{
		printf("Error\n\nWrong amount of arguments\n");
		exit(1);
	}
 	if (!check_postfix(argv[1], ".cub"))
	{
		printf("Error\n\nInvalid file extension, must be '.cub'\n");
		exit(1);
	}
	fd = open(argv[1], 0, O_RDONLY);///
	if (fd == -1)
	{
		printf("Error\n\nCannot open the given '.cub'\n");
		exit(1);
	}
	if (!get_next_line(fd))
	{
		printf("Error\n\nFile is empty\n");
		exit(1);
	}
	close(fd);
	return (fd);
}

void	initialize_struct(t_header *header)
{
	header->ceiling[0] = 0;
	header->ceiling[1] = 0;
	header->ceiling[2] = 0;
	header->ceiling[3] = 0;
	header->floor[0] = 0;
	header->floor[1] = 0;
	header->floor[2] = 0;
	header->floor[3] = 0;
	header->north = NULL;
	header->south = NULL;
	header->east = NULL;
	header->west = NULL;
	header->map = NULL;
	header->pos[0] = 0;
	header->pos[1] = 0;
	return ;
}

void	free_from_header(t_header *header)
{
	if (header->north)
		free(header->north);
	if (header->south)
		free(header->south);
	if (header->east)
		free(header->east);
	if (header->west)
		free(header->west);
	free(header);
}

void	free_from_map(t_header *header)
{
	int	i;

	i = 0;
	while (header->map[i])
	{
		free(header->map[i])
		i ++;
	}
	free(header->map);
	free(header->north);
	free(header->south);
	free(header->east);
	free(header->west);
	free(header);
}
