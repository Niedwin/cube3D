/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guviure <guviure@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 13:46:37 by kguillem          #+#    #+#             */
/*   Updated: 2026/02/07 17:33:45 by guviure          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube.h"

int is_map(char *line)
{
	int map_status;

	map_status = 0;
	while (*line == ' ')
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
	return (map_status);
}

void calc_size_map(t_map *map, char *line)
{
	int size;

	size = 0;
	map->height++;
	size = ft_strlen(line) - 1;
	if (map->width < size)
		map->width = size;
}

int fill_fields(t_game *game,int *map_status, char *line)
{
	if (is_map(line))
		*map_status = 1;
	if (*map_status)
	{
		calc_size_map(game->map, line);
		return (0);
	}
	if (line[0] == 'F' && line[1] == ' ')
		check_floor(game, line);
	else if (line[0] == 'C' && line[1] == ' ')
		check_ceilling(game, line);
	else if (line[0] == 'N' && line[1] == 'O' && line[2] == ' ')
		check_north(game, game->map, line);
	else if (line[0] == 'S' && line[1] == 'O' && line[2] == ' ')
		check_south(game, game->map, line);
	else if (line[0] == 'W' && line[1] == 'E' && line[2] == ' ')
		check_west(game, game->map, line);
	else if (line[0] == 'E' && line[1] == 'A' && line[2] == ' ')
		check_east(game, game->map, line);
	else if (only_charset(line, "\n"))
		return (1);
	else
		exit_error(" Invalid Line", game);
	return (0);
}

// Commence a lire la map et verifier si le fichier est vide
int    read_data_file(t_game *game, int fd)
{
	char *line;
	int i;
	int map_status;
	
	map_status = 0;
	i = 1;
	line = get_next_line(fd);
	if (!line)
	{
		printf("Error\nFichier Vide \n");
		return 1;
	}
	while (line)
	{
		fill_fields(game, &map_status, line);
		free(line);
		line = get_next_line(fd);
		i++;
	}
	free(line);
	if(game->map->f_rgb==-1 || game->map->c_rgb==-1)
		exit_error(" Missing Color RGB", game);
	if (!game->map->no_path || !game->map->so_path || !game->map->we_path || !game->map->ea_path)
		exit_error(" Miss Texture", game);
	return (0);
}


int checkstrchar(char c, char *str)
{
	int i;

	i = 0;
	while(str[i])
	{
		if(str[i]==c)
		{
			return (0);
		}
			
		i++;
	}
	return (1);
}


int check_arround(char **map, int i, int j)
{
	if(checkstrchar(map[i][j + 1],"10ESWN"))
		return (1);
	if(checkstrchar(map[i][j - 1],"10ESWN"))
		return (1);
	if(checkstrchar(map[i + 1][j],"10ESWN"))
		return (1);
	if(checkstrchar(map[i - 1][j],"10ESWN"))
		return (1);
	return (0);
}
int check_char_map(t_game *game)
{
	int i;

	i = 0;
	while (i < game->map->height)
	{
		if (only_charset(game->map->map_tab[i], "01NSEW ") == 0)
			exit_error(" Invalid char in map", game);
		i++;
	}
	return (0);	
}

int check_open_map(t_game *game)
{
	int i;
	int j;

	i = 1;
	j = 0;
	if (only_charset(game->map->map_tab[0],"1 ") == 0 ||  only_charset(game->map->map_tab[game->map->height - 1],"1 ") == 0)
		exit_error(" Open Map1", game);
	while (i < game->map->height - 1)
	{
		j = 1;
		if (checkstrchar(game->map->map_tab[i][0],"1 ") || checkstrchar(game->map->map_tab[i][game->map->width - 1],"1 "))
			exit_error(" Open Map2", game);
		while (j < game->map->width - 1)
		{
			if (checkstrchar(game->map->map_tab[i][j],"0NSEW") == 0 && check_arround(game->map->map_tab, i, j) == 1)
			{
				exit_error(" Open Map", game);
			}	
			j++;
		}
		i++;
	}
	return (0);
}

int	write_map_line(t_map *map, char	*line, int i)
{
	int	j;

	j = 0;
	while (line[j] && j < map->width)
	{
		/*if(!(map->map_tab[i]))
		{
			printf("Error\n ligne a la fin \n");
			return (0);//TODO exit normalement
		}*/
		if(line[j] == ' ')
		{
			map->map_tab[i][j] = ' ';
		}
		else if (line[j] == '\n')
		{
		
			map->map_tab[i][j] = ' ';
		}
		else
		{
			map->map_tab[i][j] = line[j];
		}
		j++;
	}
	return (1);
}

void fill_map(t_game *game, int fd)
{
	char *line;
	int map_status;
	int i;

	i = 0;
	map_status = 0;
	line = get_next_line(fd);
	while (line)
	{
		if (is_map(line))
			map_status = 1;
		if (map_status)
		{
			if (!write_map_line(game->map, line, i++))
			{
				free(line);
				//cleanup_gnl(fd);
				cleanup(game);
				exit(1);
			}
		}
		free(line);
		line = get_next_line(fd); 
	}
	close(fd);
   // cleanup_gnl(fd);
}

 
void	create_map(t_game *game)
{
	int	i;

	i = 0;
	if (game->map->height == 0 || game->map->width == 0)
	{
		exit_error("No map in File", game);
		return ;
	}
	game->map->map_tab = malloc(sizeof(char *) * game->map->height);
	if (!game->map->map_tab)
		return ;
	while (i < game->map->height)
	{
		game->map->map_tab[i] = malloc(sizeof(char) * (game->map->width + 1));
		if (!game->map->map_tab[i])
			return ;
		ft_memset(game->map->map_tab[i], ' ', game->map->width);
		game->map->map_tab[i][game->map->width] = '\0';
		i++;
	}
}

void load_and_read_map(t_game *game, char *filename)
{
	int fd;
	int in_fd;
	
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		exit_error("Cannot open map file", game);
	
	if (read_data_file(game, fd))
	{
		close(fd);
		cleanup(game); 
		exit_error("Error reading map file", game);
	}
	create_map(game);
	close(fd);
	//cleanup_gnl(fd);
	
	in_fd = open(filename, O_RDONLY);
	if (in_fd < 0)
		exit_error("Cannot reopen map file", game);
	fill_map(game, in_fd);
	check_char_map(game);
	check_open_map(game);
	//cleanup_gnl(in_fd); 
}
