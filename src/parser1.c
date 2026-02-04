/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kguillem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 13:46:37 by kguillem          #+#    #+#             */
/*   Updated: 2026/01/23 05:52:28 by kguillem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

//must be used to process any line within the header, could be an hashtable*
void	fill_fields(t_header *header, char *line, int *error)
{
	if (line[0] == 'F' && line[1] == ' ')
		check_color(header->floor, "F", line, error);
	else if (line[0] == 'C' && line[1] == ' ')
		check_color(header->ceiling, "C", line, error);
	else if (line[0] == 'N' && line[1] == 'O' && line[2] == ' ')
		check_path(header->north, "NO", line, error);
	else if (line[0] == 'S' && line[1] == 'O' && line[2] == ' ')
		check_path(header->south, "SO", line, error);
	else if (line[0] == 'W' && line[1] == 'E' && line[2] == ' ')
		check_path(header->west, "WE", line, error);
	else if (line[0] == 'E' && line[1] == 'A' && line[2] == ' ')
		check_path(header->east, "EA", line, error);
	else if (only_charset(line, "\n"))
		return ;
	else
	{
		*error ++;
		printf("Error\nLine is neither empty nor useable\n");
	}
}

int	check_empty_fields(t_header *header)
{
	if (header->ceiling[3] == 0 || header->floor[3] == 0)
		return (1);
	if (header->north == NULL || header->south == NULL ||
			 header->east == NULL || header->west == NULL)
		return (1);
	return (0);
}

//TODO verify that re-opening the file indeed restart gnl
void	verify_header(t_header *header, int *error)
{
	int	i;
	char *line;

	i = 0;
	open(header->fd);//sus
	while (check_empty_fields(header))
	{
		line = get_next_line(fd);// ! no free
		if (!line)
		{
			printf("Error\nReached 'EOF' at line %i\n", i);//EOF
			*error ++;
			return ;
		}
		fill_fields(header, line, error);
		i ++;
	}
}
