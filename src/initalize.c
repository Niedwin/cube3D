/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initalize.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guviure <guviure@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 19:34:00 by guviure           #+#    #+#             */
/*   Updated: 2025/12/10 19:34:43 by guviure          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

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
}

int	check_args_n_fd(int argc, char **argv)
{
	int	fd;

	if (argc != 2 || argv[1][0] == '\0')
	{
		ft_printf("Error\n\nWrong amount of arguments\n");
		exit(1);
	}
 	if (!check_postfix(argv[1]), ".cub")
	{
		ft_printf("Error\n\nInvalid file extension, must be '.cub'\n");
		exit(1);
	}
	fd = open(argv[1], 0, O_RDONLY);//not finished!!!
	if (fd == -1)
	{
		ft_printf("Error\n\nCannot open the given '.cub'\n");
		exit(1);
	}
	return (fd);
}

int	initialize_struct(struct *)
{
	//initialize all fields to NULL or -1
}
