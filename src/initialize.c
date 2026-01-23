/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guviure <guviure@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 19:34:00 by guviure           #+#    #+#             */
/*   Updated: 2026/01/23 08:00:46 by guviure          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

int	checkpath_textures(char *path, char *prefix)
{
	int	fd;

	fd = open(path, 0, O_RDONLY);
	if (0 > fd)
	{
		printf("Error\n\nCannot open %s as %s texture", path, prefix);
		return (1);
	}
	close(fd);
	return (0);
}

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
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
	{
		printf("Error\n\nCannot open the given '.cub'\n");
		exit(1);
	}
	return (1);
}
