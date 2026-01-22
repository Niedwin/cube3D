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

int	checkpath_textures(char *path, char *prefix, int *error)
{
	char	*tmp;
	int		fd;

	fd = open(path, 0, O_RDONLY)
	if (0 > fd)
	{
		printf("Error\n\nCannot open %s as %s texture", path, prefix);
		*error ++;
		return ;
	}
	tmp = mlx_xpm_file_to_image();//might need to free !!!
	if (!tmp)
	{
		printf("Error\n\n%s cannot be used by the MLX\n", prefix);
		*error ++;
	}
	close(fd);
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
	fd = open(argv[1], 0, O_RDONLY);//not finished!!!
	if (fd == -1)
	{
		printf("Error\n\nCannot open the given '.cub'\n");
		exit(1);
	}
	return (fd);
}

void	initialize_struct(t_header *header)//initialize all fields to NULL
{
	header->ceiling = ft_memset(ceiling, 0, 4);
	header->floor = ft_memset(ceiling, 0, 4);
	header->north = NULL;
	header->south = NULL;
	header->east = NULL;
	header->west = NULL;
	header->map = NULL;
	header->pos = ft_memset(pos, 0, 2);
	return ;
}
