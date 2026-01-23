/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_textures_kerloye.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guviure <guviure@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 19:38:50 by kguillem          #+#    #+#             */
/*   Updated: 2026/01/23 10:24:51 by guviure          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube.h"

void check_north(t_game *game, t_map *map, char *line, int i)
{
	char	*new_line;
	int		tmpfd;
	
	tmpfd = 0;
	if (!map->no_path)
	{
		new_line = ft_strtrim(line + 2, " \n");
		map->no_path = ft_strdup(new_line);
		free(new_line);
	}
	else
	{
		printf("Error\nMultiple attribution de NO a la ligne %i\n", i);
		cleanup(game);
		exit(EXIT_FAILURE);//TODO exit normalement
	}
	if (check_postfix(map->no_path,".xpm")==0) 
	{
		printf("Error\n pas un fichier xpm\n");
		cleanup(game);
		exit(1);//TODO exit normalement
	}

	tmpfd=open(map->no_path,O_RDONLY);
	if (tmpfd < 0)
	{
		printf("Error\nce fichier n'existe pas\n"); //TODO exit correctement
		cleanup(game);
		exit(1);
	}
	close(tmpfd);
}

void check_south(t_game *game, t_map *map, char *line, int i)
{
	char	*new_line;
	int     tmpfd;
	
	tmpfd = 0;
	if (!map->so_path)
	{
		new_line = ft_strtrim(line + 2, " \n");
		map->so_path = ft_strdup(new_line);
		free(new_line);
	}
	else
	{
		printf("Error\nMultiple attribution de 'SO' a la ligne %i\n", i);
		cleanup(game);
		exit(EXIT_FAILURE);//TODO exit normalement
	}
	if (check_postfix(map->so_path,".xpm")==0)
	{
		printf("Error\n pas un fichier xpm\n");//TODO exit normalement
		cleanup(game);
		exit(1);
	}
	tmpfd=open(map->so_path,O_RDONLY);
	if (tmpfd < 0)
	{
		printf("Error\n le fichier n'existe pas\n"); //TODO exit correctement
		cleanup(game);
		exit(1);
	}
	close(tmpfd);	
}

void check_west(t_game *game, t_map *map, char *line, int i)
{
	char	*new_line;
	int		tmpfd;

	tmpfd = 0;	
	if (!map->we_path)
	{
		new_line = ft_strtrim(line + 2, " \n");
		map->we_path = ft_strdup(new_line);
		free(new_line);
	}
	else
	{
		printf("Error\nMultiple attribution de 'WE' a la ligne %i\n", i);
		cleanup(game);
		exit(EXIT_FAILURE);//TODO exit normalement
	}
	if (check_postfix(map->we_path,".xpm")==0)
	{
		printf("Error\n pas un fichier XPM\n");//TODO exit normalement
		cleanup(game);
		exit(1);
	}
	tmpfd=open(map->we_path,O_RDONLY);
	if (tmpfd < 0)
	{
		printf("Error\n ce fichier n'existe pas \n"); //TODO exit correctement
		cleanup(game);
		exit(1);
	}
	close(tmpfd);	
}

void check_east(t_game *game, t_map *map, char *line, int i)
{
	char	*new_line;
	int    tmpfd;

	tmpfd = 0;	
	if (!map->ea_path)
	{
		new_line = ft_strtrim(line + 2, " \n");
		map->ea_path = ft_strdup(new_line);
		free(new_line);
	}
	else
	{
		printf("Error\nMultiple attribution de 'EUW' a la ligne %i\n", i);
		cleanup(game);
	    exit(EXIT_FAILURE);//TODO exit normalement
	}
	if (check_postfix(map->ea_path,".xpm")==0)
	{//TODO exit normalement
		printf("Error\n pas un fichier xpm\n");
		cleanup(game);
		exit(1);
	}
	tmpfd=open(map->ea_path,O_RDONLY);
	if (tmpfd < 0)
	{
		printf("Error\n texture EA n'existe pas \n"); //TODO exit correctement
		cleanup(game);
		exit(1);
	}
	close(tmpfd);	
}
