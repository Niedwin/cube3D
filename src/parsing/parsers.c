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
	// while (*line == ' ' || *line == '\t') // TODO jai edit pour pas prendre tab, jsp
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
	if(game->map->f_rgb==-1 || game->map->c_rgb==-1)
	{
		printf("\n ME MANQUE UNE COULEUR HAHAHAHAHAHAHAHAHAA\n");//TODO exit normalement
		exit(1);
	}
	if (!game->map->no_path || !game->map->so_path || !game->map->we_path || !game->map->ea_path)
	{
		printf("\n ME MANQUE UNE TEXTRE HAHAHAHAHAHAHAHAHAA\n");//TODO exit normalement
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
					printf("PAS DE BOL NON\n ii : %i jj : %i c : %c\n",ii,jj,map[ii][jj]); //TODO exit fine
					return 1;
				}
		}
			jj++;
		}
		ii++;
	}
	

return (0);
}

int check_open_map(t_map *map)
{
	int i;
	int j;

	i=0;
	j=0;
	if(only_charset(map->map_tab[0],"!1#\n") == 0 ||  only_charset(map->map_tab[map->heightmap-1],"!1#\n") == 0)
	{
		printf("NON RATIO");
		exit(1);// TODO exit 
	}
	while (i < map->heightmap)
	{
		j=0;
		while (j < map->widthmap)
		{
		
			if ((j == 0 || j == map->widthmap -1) && checkstrchar(map->map_tab[i][j],"1#\n"))
			{
				printf("BORDURE GAUCHE OU DROITE OUVERTE HAHA");
				exit(1);//TODO exit
			}
			if(map->map_tab[i][j]=='0' && check_arround(map->map_tab,i,j) == 1)
			{
				printf("PAS DE BOL NON\n"); //TODO exit fine
				exit(1);
			}
		
			j++;
		}
		i++;
	}
	

	return 0;
}

void	write_map_line(t_map *map, char	*line, int i)
{
	int	j;
	int tem;

	tem = 0;
	j = 0;
	while (line[j] && j < map->widthmap)
	{
		if(!(map->map_tab[i]))
		{
			printf("GLOUBIBOULGA BREAK LINE AT END"); //TODO BREAK LINE END
			exit(1);//TODO exit normalement
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
			write_map_line(game->map, line, i++);
		free(line);
		line = ft_get_next_line(fd);
		//map_status = 0;//TODO si marche plus go comment
		//printf("bah ?");
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
	check_open_map(game->map);
		
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
