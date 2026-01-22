//will assess the map, checking that the characters are good whilst storing it

/* ................................ONGOING.....................................
 * target an empty space on the map, checks every neighboors of said empty space
 * if adjacent spaces are neither filled with walls or other empty space
 * map is not closed
 *
 * may be better to use whitespaces next to other valid chars to do the checks
 * to reduce the amount of checks to only the perimeter
 */``
int	verify_map(t_header *header, char *first, int *error)
{
	int		height;
	char	*line;
	char 	**map;

	height = 1
	map[0] = first;
	while (1)
	{
		line = get_next_line(header->fd);
		if (!line)
			break ;
		map[height] = line;
		if (!only_charset(map[height]), " 01NSEW\n")
		{
			printf("Error\nLine %d contains invalid characters", height);
			*error ++;
		}
		height ++;
	}
	if (*error)
		height = 0;//as height cannot be null allows faster checks
	return (height);
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

