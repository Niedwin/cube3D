/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_textures.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kguillem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 13:40:06 by kguillem          #+#    #+#             */
/*   Updated: 2026/01/23 05:49:24 by kguillem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

/*
//TODO properly use the mlx
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
	tmp = mlx_xpm_file_to_image();//free needed if not stored for mlx
	if (!tmp)
	{
		printf("Error\n\n%s cannot be used by the MLX\n", prefix);
		*error ++;
	}
	close(fd);
}
*/

//TODO FINISH
void	fill_path(char *path, char *id, char *line, int *error, int i)
{
	if (!check_postfix(line, "\n"))
	{
		printf("Error\nNo more text after %s at line %i\n", prefix, i);
		*error ++;
	}
	line = skip_char(line + 2, ' ');
}

//either assess the line to give to 'prefix' or output an error
void	check_path(char *path, char *prefix, char *line, int *error, int i)
{
	if (path == NULL)
		fill_path(path, prefix, line, error, i);
	else
	{
		printf("Error\nMultiple attribution for %s at line %i\n", prefix, i);
		*error ++;
	}
}

//TODO FINISH
void	fill_color(t_header *header, char *line, int *error, int i)
{	
	line = skip_char(line + 2, ' ');
	if (!floor_color_format(header, line))
	{
		printf("Error\nwrong floor color format at line %i\n", i);
		error ++;
		return ;
	}
}

//TODO FINISH
//either assess the line to give the color 'prefix' or output an error
void	check_color(char *color, char *prefix, char *line, int *error, int i)
{
	if (color[3] == 0)//TODO CHECK
		fill_color(color, prefix, line, error, i);
	else
	{
		printf("Error\nMultiple attribution for %s at line %i\n", prefix, i);
		*error ++;
	}
}

