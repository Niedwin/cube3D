/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guviure <guviure@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 13:46:37 by kguillem          #+#    #+#             */
/*   Updated: 2026/01/22 17:53:21 by guviure          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube.h"

int is_map(char *line)
{
	int map_status;

	map_status = 0;
	while (*line == ' ' || *line == '\t')
		line++;
	if (ft_strncmp(line, "NO", 2) == 0 || ft_strncmp(line, "SO", 2) == 0
		|| ft_strncmp(line, "EA", 2) == 0 || ft_strncmp(line, "WE", 2) == 0
		|| ft_strncmp(line, "F", 1) == 0 || ft_strncmp(line, "C", 1) == 0)
		return (0);
	while (*line)
	{
		if (*line == '0' || *line == '1' || *line == 'N' || *line == 'S'
			|| *line == 'E' || *line == 'W' || *line == ' ')
			map_status = 1;
		line++;
	}
	return (map_status); // que des espaces / tab / newline
}

void calc_size_map(t_map *map, char *line)
{
	int size;

	size = 0;
	map->heightmap++;
	size = ft_strlen(line) - 1;
	if (map->widthmap < size)
		map->widthmap = size;
}

int fill_fields(t_map *map, char *line, int i)
{
	if (is_map(line))
	{
		calc_size_map(map, line);
		return (0);
	}	
	if (line[0] == 'F' && line[1] == ' ')
		check_floor(map, line, i);
	else if (line[0] == 'C' && line[1] == ' ')
		check_ceilling(map, line, i);
	else if (line[0] == 'N' && line[1] == 'O' && line[2] == ' ')
		check_north(map, line, i);
	else if (line[0] == 'S' && line[1] == 'O' && line[2] == ' ')
		check_south(map, line, i);
	else if (line[0] == 'W' && line[1] == 'E' && line[2] == ' ')
		check_west(map, line, i);
	else if (line[0] == 'E' && line[1] == 'A' && line[2] == ' ')
		check_east(map, line, i);
	else if (only_charset(line, "\n"))
		return (1);
	else
	{
		printf("Error\nInvalid line found at : %i\n", i);
	}
	return (0);
}

// Commence a lire la map et verifier si le fichier est vide
int	read_data_file(t_game *game, int fd)
{
	char *line;
	int i;
	
	i = 1;
	line = ft_get_next_line(fd);
	if (!line)
	{
		printf("Error\n Empty file ! \n");
		return 1;
	}
	while (line)
	{
		fill_fields(game->map, line, i);
		free(line);
		line = ft_get_next_line(fd);
		i++;
	}
	return (0);
}

void	write_map_line(t_map *map, char	*line, int *i)
{
	int	j;

	j = 0;
	while (line[j] && j < map->widthmap)
	{
		if (line[j] == ' ' || line[j] == '\n' || line[j] == '\t')
			map->map_tab[*i][j] = '#';
		else
			map->map_tab[*i][j] = line[j];
		j++;
	}
	(*i)++;
}

void	fill_map(t_game *game, int fd)
{
	char *line;
	int	map_status;
	int i;

	i = 0;
	map_status = 0;
	line = ft_get_next_line(fd);
	while (line)
	{
		if (is_map(line))
			map_status = 1;
		if (map_status)
			write_map_line(game->map, line, &i);
		free(line);
		line = ft_get_next_line(fd);
	}
	close(fd);
	free(line);
}

// a modifier svp chanegr la nom des variable 
void	malloc_map(t_map *map)
{
	int	i;

	i = 0;
	map->map_tab = malloc(sizeof(char *) * map->heightmap);
	if (!map->map_tab)
		return ;
	while (i < map->heightmap)
	{
		map->map_tab[i] = malloc(sizeof(char) * (map->widthmap + 1));
		if (!map->map_tab[i])
			return ;
		ft_memset(map->map_tab[i], '#', map->widthmap);
		map->map_tab[i][map->widthmap] = '\0';
		i++;
	}
}

void	load_and_read_map(t_game *game, char *filename)
{
	int fd;
	int nd_fd;

	
	fd = open(filename, O_RDONLY);
	
	// lit et alloue la data de terrain()
	if (read_data_file(game, fd))
	{
		close(fd);
		return ;
	}
	malloc_map(game->map);
	close(fd);
	nd_fd = open(filename, O_RDONLY);
	// lit et remplis la data du terrain
	fill_map(game, nd_fd);
		
}

// void verify_header(t_header *header)
//{
//	int i;
//	char *line;
//	i = 0;
//	while (check_empty_fields(header))
//	{
//		line = ft_get_next_line(fd); // ! no free
//		if (!line)
//		{
//			printf("Error\nGet_next_line failed at line %i\n", i);
//			return;
//		}
//		fill_fields(header, line, i);
//		i++;
//	}
// }
