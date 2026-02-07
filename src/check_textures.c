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

/*
remove_newline_n_spaces
*/

//TODO FINISH
int	fill_path(char *path, char *id, char *line)
{
	if (!check_postfix(line, "\n"))
	{
		printf("Error\nNo more text after %s\n", prefix);
		*error ++;
	}
	line = skip_char(line + 2, ' ');
}

//either assess the line to give to 'prefix' or output an error
void	check_path(char *path, char *prefix, char *line)
{
	if (path == NULL)
		return (fill_path(path, prefix, line, error));
	else
		printf("Error\nMultiple attribution for %s\n", prefix);
	return (0);
}

int	valid_channels(char *line)
{
	int	i;

	i = 0;
	if (line[0] == ',')
		return (0);
	while (line[i] && line[i] != ',')
		i ++;
	if (!line[i] || line[i + 1] == ',')
		return (0);
	return (1);
}

int	valid_ranges(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] == ',')
			i ++;

		i ++;
	}
	return (1);
}

int	color_format()//TODO
{
	if (!only_charset(line, "0123456789 ,\n"))
	{
		printf("Error\nInvalid color format for %s\n", prefix);
		return (0);
	}
	if (char_count(line, ',') != 2)
	{
		printf("Error\nInvalid amount of channels for %s\n", prefix);
		return (0);
	}
	if (!valid_channels(line))
	{
		printf("Error\nMissing values beetween channels for %s\n", prefix);
		return (0);
	}
	if (!valid_ranges(line))
	{
		printf("Error\nInvalid numeric range in channels for %s\n", prefix);
		return (0);
	}
	return (1);
}

//TODO FINISH
int	check_color(int *color, char *prefix, char *line)
{
	int	i;

	if (color[0] == -1)
	{
		line = skip_char(line + 2, ' ');//might need to free beforehand
		if (!color_format(line, prefix))
			return (0);
		i = 0;
		color[0] = //atoi
		while (str[i] != ',')
			i ++;
		color[1] = //atoi
		i ++;
		while (str[i] != ',')
			i ++;
		color[2] = //atoi
	}
	else
	{
		printf("Error\nMultiple attribution for %s\n", prefix);
		return (0);
	}
	return (1);
}

