#include "cube.h"

void	check_north(t_header *header, char *line, int *error, int i)
{
	if (header->north_texture == NULL)
		fill_floor(header, line, error, i);//fill associated field
	else
	{
		printf("Error\nMultiple attribution for 'NO' at line %i\n", i);
		*error ++;
	}
}

void	check_south(t_header *header, char *line, int *error, int i)
{
	if (header->south_texture == NULL)
		fill_floor(header, line, error, i);//fill associated field
	else
	{
		printf("Error\nMultiple attribution for 'SO' at line %i\n", i);
		*error ++;
	}
}

void	check_west(t_header *header, char *line, int *error, int i)
{
	if (header->west_texture == NULL)
		fill_floor(header, line, error, i);//fill associated field
	else
	{
		printf("Error\nMultiple attribution for 'WE' at line %i\n", i);
		*error ++;
	}
}

void	check_east(t_header *header, char *line, int *error, int i)
{
	if (header->east_texture == NULL)
		fill_floor(header, line, error, i);//fill associated field
	else
	{
		printf("Error\nMultiple attribution for 'EA' at line %i\n", i);
		*error ++;
	}
}
