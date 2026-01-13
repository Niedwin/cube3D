/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initalize.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guviure <guviure@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 19:34:00 by guviure           #+#    #+#             */
/*   Updated: 2026/01/13 15:38:19 by kguillem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"
/*
int	checkpath_textures(char *prefix, char *path)
{
	int	fd;

	fd = open(path);
	if (fd == -1)
	{
		printf("Error\n\nCannot open %s texture", prefix);
		exit(1);
	}
	if (checkformat_textures(fd))
	{
		printf("Error\n\n%s texture isn't to the right format\n", prefix);
		exit(1);
	}
	return (fd);
}*/

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
	fd = open(argv[1], 0, O_RDONLY);//not finished!!!
	if (fd == -1)
	{
		printf("Error\n\nCannot open the given '.cub'\n");
		exit(1);
	}
	return (fd);
}
/*
void	null_colors(t_header *header)
{
	header->ceiling[0] = NULL;
	header->ceiling[1] = NULL;
	header->ceiling[2] = NULL;
	header->ceiling[3] = NULL;
	header->floor[0] = NULL;
	header->floor[1] = NULL;
	header->floor[2] = NULL;
	header->floor[3] = NULL;
	return	;
}

void	null_textures(t_header *header)
{
	header->north = NULL;
	header->south = NULL;
	header->east = NULL;
	header->west = NULL;
	return ;
}

void	null_map(t_header *header)
{
	header->map = NULL;
	header->pos[0] = 0;
	header->pos[1] = 0;
	return ;
}

void	initialize_struct(t_header *header)//initialize all fields to NULL
{
	null_colors(header);
	null_textures(header);
	null_map(header);
	return ;
}*/
