/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kguillem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 13:46:37 by kguillem          #+#    #+#             */
/*   Updated: 2026/01/13 15:07:00 by kguillem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

//must be used to process any line within the header, could be an hashtable*
void	fill_fields(t_header *header, char *line, int *error, int i)
{
	if (line[0] == 'F' && line[1] == ' ')
		check_floor(header, line, error, i);
	else if (line[0] == 'C' && line[1] == ' ')
		check_ceilling(header, line, error, i);
	else if (line[0] == 'N' && line[1] == 'O' && line[2] == ' ')
		check_north(header, line, error, i);
	else if (line[0] == 'S' && line[1] == 'O' && line[2] == ' ')
		check_south(header, line, error, i);
	else if (line[0] == 'W' && line[1] == 'E' && line[2] == ' ')
		check_west(header, line, error, i);
	else if (line[0] == 'E' && line[1] == 'A' && line[2] == ' ')
		check_east(header, line, error, i);
	else if (only_newline(line))
		return ;
	else
	{
		*error ++;
		printf("Error\nInvalid line found at : %i\n", i);
	}
}
void	verify_header(t_header *header, int *error)
{
	int	i;
	char *line;

	i = 0;
	while (check_empty_fields(header))
	{
		line = get_next_line(fd);// ! no free
		if (!line)
		{
			printf("Error\nGet_next_line failed at line %i\n", i);
			*error ++;
			return ;
		}
		fill_fields(header, line, error, i);
		i ++;
	}
}
