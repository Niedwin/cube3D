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

int	only_charset(char *str, char *set)//could indicate bad char if needed
{
	int	i;
	int	j;

	i = 0;
	while (str[i])
	{
		j = 0;
		while (set[j])
		{
			if (str[i] == set[j])
				break ;
			j ++;
		}
		if (set[j] == '\0')
			return (0);
		i ++;
	}
	return (1);
}

/*
 * doesnt need to verify for a name before the extension, as the extension
 * itself count as a valid name.
 */
int	check_postfix(char *source, char *postfix)
{
	int	i;
	int	j;

	if (ft_strlen(postfix) > source)
		return (0);
	i = ft_strlen(source) - ft_strlen(postfix);
	j = 0;
	while (source[i])
	{
		if (source[i] != postfix[j])
			return (0);
		i ++;
		j ++;
	}
	return (1);
}
