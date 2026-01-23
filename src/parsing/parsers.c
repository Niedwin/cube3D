/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guviure <guviure@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 13:46:37 by kguillem          #+#    #+#             */
/*   Updated: 2026/01/23 18:58:21 by guviure          ###   ########.fr       */
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

int fill_fields(t_game *game,int *map_status, char *line, int i)
{
	if (is_map(line))
		*map_status = 1;
	if (*map_status)
	{
		calc_size_map(game->map, line);
		return (0);
	}
	if (line[0] == 'F' && line[1] == ' ')
		check_floor(game->map, line, i);
	else if (line[0] == 'C' && line[1] == ' ')
		check_ceilling(game->map, line, i);
	else if (line[0] == 'N' && line[1] == 'O' && line[2] == ' ')
		check_north(game, game->map, line, i);
	else if (line[0] == 'S' && line[1] == 'O' && line[2] == ' ')
		check_south(game, game->map, line, i);
	else if (line[0] == 'W' && line[1] == 'E' && line[2] == ' ')
		check_west(game, game->map, line, i);
	else if (line[0] == 'E' && line[1] == 'A' && line[2] == ' ')
		check_east(game, game->map, line, i);
	else if (only_charset(line, "\n"))
		return (1);
	else
	{
		printf("Error\nUnvalid Line : %i\n", i);
		return (-1);
	}
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
	line = ft_get_next_line(fd);
	if (!line)
	{
		printf("Error\nEmpty File \n");
		return 1;
	}
	while (line)
	{
		if (fill_fields(game, &map_status, line, i) == -1)
		{
			free(line);
			cleanup(game); 
			exit(1);
		}
		free(line);
		line = ft_get_next_line(fd);
		i++;
	}
	free(line);
	if(game->map->f_rgb==-1 || game->map->c_rgb==-1)
	{
		printf("Error\nMissing Color \n");//TODO exit normalement
		cleanup(game);
		exit(1);
	}
	if (!game->map->no_path || !game->map->so_path || !game->map->we_path || !game->map->ea_path)
	{
		printf("Error\nMissing Color \n");//TODO exit normalement
		cleanup(game);
		exit(1);
	}
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
	int ii;
	int jj;

	ii=i-1;
	while (ii<=i+1)
	{
		jj=j-1;
		while (jj<=j+1)
		{	
			if( !(((jj==j+1) && ((ii == i + 1) || (ii == i -1))) || ((jj==j-1) && ((ii == i + 1) || (ii == i -1)))))
			{
				if(map[ii] && map[ii][jj] && checkstrchar(map[ii][jj],"10ESWN") ==1 )
				{
					printf("Error\n la carte n'est pas ferme \n"); //TODO exit fine
					//ft_free_split(map);
					return (1);
				}
		}
			jj++;
		}
		ii++;
	}
	

return (0);
}

int check_open_map(t_game *game)
{
	int i;
	int j;

	i = 0;
	j = 0;
	if(only_charset(game->map->map_tab[0],"!1#\n") == 0 ||  only_charset(game->map->map_tab[game->map->height-1],"!1#\n") == 0)
	{
		printf("Error\n Map ouverte \n");
		cleanup(game);
		exit(1);// TODO exit 
	}
	while (i < game->map->height)
	{
		j=0;
		while (j < game->map->width)
		{
		
			if ((j == 0 || j == game->map->width -1) && checkstrchar(game->map->map_tab[i][j],"1#\n"))
			{
				printf("Error\n Map open \n");
				cleanup(game);
				exit(1);//TODO exit
			}
			if(game->map->map_tab[i][j]=='0' && check_arround(game->map->map_tab,i,j) == 1)
			{
				printf("Error\n Map open\n"); //TODO exit fine
				cleanup(game);
				exit(1);
			}
			if (game->map->height <= 0)
   			{
				printf("Error\nMissing Map \n");
  			  	cleanup(game);
   			 	exit(1);
    	}
			j++;
		}
		i++;
	}
	return 0;
}

int	write_map_line(t_map *map, char	*line, int i)
{
	int	j;
	int tem;

	tem = 0;
	j = 0;
	while (line[j] && j < map->width)
	{
		if(!(map->map_tab[i]))
		{
			printf("Error\nLine at the end \n");
			return (0);//TODO exit normalement
		}
		if((line[j] == ' ' && tem==0))
		{
			map->map_tab[i][j] = '#';
		}else if (line[j] == '\n')
		{
		
			map->map_tab[i][j] = '#';
		}
		else
		{
			if(line[j] == ' ')
			{
				map->map_tab[i][j] = '!';
			}
			else
				map->map_tab[i][j] = line[j];
			tem=1;
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
	line = ft_get_next_line(fd);
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
		line = ft_get_next_line(fd); 
	}
	close(fd);
   // cleanup_gnl(fd);
}

 
void	create_map(t_map *map)
{
	int	i;

	i = 0;
	map->map_tab = malloc(sizeof(char *) * map->height);
	if (!map->map_tab)
		return ;
	while (i < map->height)
	{
		map->map_tab[i] = malloc(sizeof(char) * (map->width + 1));
		if (!map->map_tab[i])
			return ;
		ft_memset(map->map_tab[i], '#', map->width);
		map->map_tab[i][map->width] = '\0';
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
	
	create_map(game->map);
	close(fd);
	//cleanup_gnl(fd);
	
	in_fd = open(filename, O_RDONLY);
	if (in_fd < 0)
		exit_error("Cannot reopen map file", game);
	fill_map(game, in_fd);
	check_open_map(game);
	//cleanup_gnl(in_fd); 
}
