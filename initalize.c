#include <fcntl.h>

int	checkpath_textures(char *prefix, char *path)
{
	int	fd;

	fd = open(path);
	if (fd == -1)
	{
		printf("Error\n\nCannot open %s texture", prefix)
		exit(1);
	}
	if (checkformat_textures(fd))
	{
		printf("Error\n\n%s texture isn t to the right format", prefix)
		exit(1);
	}
	return (fd);
}

int	check_elements(t_elements *elements, ) //memset libft the struct B4...
{
	struct	elements;
}

int	check_map()
{

}

/*
 * doesnt need to verify for a name before the extension, as the extension
 * itself count as a valid name.
 */
int	check_cub_type(char *str)//better with strcmp
{
	int	i;

	i = 0;
	while (str[i] && str[i + 3])
	{
		if (str[i] == '.')
		{
			if (str[i + 1] == 'c' && str[i + 2] == 'u'
					&& str[i + 3] == 'b' && str[i + 4] == '\0')
				return (0);
		}
		i ++;
	}
	return (1);
}

int	check_xpm_type(char *str)//better with strcmp
{
	int	i;

	i = 0;
	while (str[i] && str[i + 3])
	{
		if (str[i] == '.')
		{
			if (str[i + 1] == 'x' && str[i + 2] == 'p'
					&& str[i + 3] == 'm' && str[i + 4] == '\0')
				return (0);
		}
		i ++;
	}
	return (1);
}


int	check_args_n_fd(int argc, char **argv)
{
	int	fd;

	if (argc != 2 || argv[1][0] == '\0')
	{
		ft_printf("Error\n\nWrong amount of arguments\n");
		exit(1);
	}
 	if (check_file_type(argv[1]))
	{
		ft_printf("Error\n\nInvalid file extension, must be '.cub'\n");
		exit(1);
	}
	fd = open(argv[1], 0, O_RDONLY);//not finished!!!
	if (fd == -1)
	{
		ft_printf("Error\n\nCannot open the given '.cub'\n");
		exit(1);
	}
	return (fd);
}
