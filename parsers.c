/* ................................ONGOING.....................................
 * target an empty space on the map, checks every neighboors of said empty space
 * if adjacent spaces are neither filled with walls or other empty space
 * map is not closed
 *
 * may be better to use whitespaces next to other valid chars to do the checks
 * to reduce the amount of checks to only the perimeter
 */
int	closed_map(char **map)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while ()
}


/*
 * verify the map when there are no whitespaces, such as no open spaces in
 * column 0, no open spaces at max width'
 *
 */
void	verify_exceptions(char **map, int height, int *error)
{
	int	i;

	i = 0;
	while (i <= height)
	{
		if (map[i][0] == '0')
		{
			printf("Error\nLine %i is not closed\n", i);
			*error ++;
		}
		i ++;
	}
}

void	verify_perimeter(char **map, int height, int *error)
{
int	
}

/*
 * aims to fill a struct with all fields initialized to NULL for char *paths
 * or -1 for integers to give a warning
 * when any field is already set as to avoid doubles attributes in the "header"
 *
 * whenever a path is set, tries to open said path after filling its field
 * so that the error count doesnt count both the field being empty and being
 * unopenable.
 */
void	verify_header(int fd, int *error)
{
	int	i;
	char *line;

	i = 0;
	line = get_next_line(fd);

	if (!line)//either gnl malloc failed or gnl instantly reached EOF
	{
		// (@) may use smthing else than 'printf' to gain 'ERRNO' for context
		return ;
	}
	while ( || )//verify each field to see if they're still empty
	{
		line = get_next_line(fd);
		if (!line)
		{
			// (@) printf("Error\nGet_next_line failed at line %i\n", i);
			*error ++;
			return ;
		}
		fill_fields(&struct, line, error, i);
		i ++;
	}
}

//aims to process every line within the header
void	fill_fields(struct *, char *line, int *error, int i)
{
	if (line[0] == 'F' && line[1] == ' ')
		check_floor(struct, line, error, i);
	else if (line[0] == 'C' && line[1] == ' ')
		check_ceilling(struct, line, error, i);
	else if (line[0] == 'N' && line[1] == 'O')
		check_north(struct, line, error, i);
	else if (line[0] == 'S' && line[1] == 'O')
		check_south(struct, line, error, i);
	else if (line[0] == 'W' && line[1] == 'E')
		check_west(struct, line, error, i);
	else if (line[0] == 'E' && line[1] == 'A')
		check_east(struct, line, error, i);
	else if (only_newline(line))
		return ;
	else
	{
		*error ++;
		printf("Error\nInvalid line found at : %i\n", i);
	}
}

/*
	{
		if ()//verify said field to proceed only if empty
			truc;
		else
		{
			printf("Error\nDouble attribution for 'F' at line %i\n", i);
			*error ++;
		}
	}

