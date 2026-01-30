/*
//TODO``
//assess if the line is empty or an error and print accordingly
void	check_in_beetween(t_header *header, char *line, int *error, int i)
{
	if (line[0] == 'F' && line[1] == ' ')
		//check_color(header->floor, "F", line, error, i);
	else if (line[0] == 'C' && line[1] == ' ')
		//check_color(header->ceiling, "C", line, error, i);
	else if (line[0] == 'N' && line[1] == 'O' && line[2] == ' ')
		//check_path(header->north, "NO", line, error, i);
	else if (line[0] == 'S' && line[1] == 'O' && line[2] == ' ')
		//check_path(header->south, "SO", line, error, i);
	else if (line[0] == 'W' && line[1] == 'E' && line[2] == ' ')
		//check_path(header->west, "WE", line, error, i);
	else if (line[0] == 'E' && line[1] == 'A' && line[2] == ' ')
		//check_path(header->east, "EA", line, error, i);
	else if (only_charset(line, "\n"))
		return ;
	else
	{
		*error ++;
		printf("Error\nInvalid line found at : %i\n", i);
	}
}

//TODO
//aims to return either the line to the start of the map, or NULL on error(s)
char	*verify_in_beetween(t_header *header, int *error)
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
}*/
