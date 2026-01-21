//will assess the map, checking that the characters are good whilst storing it

/* ................................ONGOING.....................................
 * target an empty space on the map, checks every neighboors of said empty space
 * if adjacent spaces are neither filled with walls or other empty space
 * map is not closed
 *
 * may be better to use whitespaces next to other valid chars to do the checks
 * to reduce the amount of checks to only the perimeter
 */``
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

int	parse3(t_header *header)
{

}
