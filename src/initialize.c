/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guviure <guviure@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 19:34:00 by guviure           #+#    #+#             */
/*   Updated: 2026/01/22 17:53:49 by guviure          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

int checkpath_textures(char *path, char *prefix)
{
	// char *tmp;
	int fd;

	fd = open(path, 0, O_RDONLY);
	if (0 > fd)
	{
		printf("Error\n\nCannot open %s as %s texture", path, prefix);
		return (1);
	}
	// tmp = mlx_xpm_file_to_image(); // might need to free !!!
	// if (!tmp)
	//{
	//	printf("Error\n\n%s cannot be used by the MLX\n", prefix);
	// }
	close(fd);
	return (0);
}


/* Verif valid argument valid .cub and valid file*/
int check_args_n_fd(int argc, char **argv)
{
	int fd;

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
	fd = open(argv[1], O_RDONLY); // not finished!!!
	if (fd < 0)
	{
		printf("Error\n\nCannot open the given '.cub'\n");
		exit(1);
	}
	return (1);
}


