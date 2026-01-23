/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_textures_kerloye.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guviure <guviure@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 19:38:50 by kguillem          #+#    #+#             */
/*   Updated: 2026/01/23 08:25:06 by kguillem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube.h"

void check_north(t_map *map, char *line, int i)
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
		printf("Error\nMultiple attribution for 'NO' at line %i\n", i);
		exit(EXIT_FAILURE);//TODO exit normalement
	}
	if (check_postfix(map->no_path,".xpm")==0) // check si bien xpm
	{
		printf("\n NO HAHAHAHA PAS UN XPM\n");
		exit(1);//TODO exit normalement
	}

	tmpfd=open(map->no_path,O_RDONLY);
	if (tmpfd < 0)
	{
		printf("\n NO HAHAHAHA PAS UN FICHIER QUI EXISTE RATIO\n"); //TODO exit correctement
		exit(1);
	}
	close(tmpfd);
}

void check_south(t_map *map, char *line, int i)
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
		printf("Error\nMultiple attribution for 'SO' at line %i\n", i);
		exit(EXIT_FAILURE);//TODO exit normalement
	}
	if (check_postfix(map->so_path,".xpm")==0)
	{
		printf("\n SO HAHAHAHA PAS UN XPM\n");//TODO exit normalement
		exit(1);
	}
	tmpfd=open(map->so_path,O_RDONLY);
	if (tmpfd < 0)
	{
		printf("\n SO HAHAHAHA PAS UN FICHIER QUI EXISTE RATIO\n"); //TODO exit correctement
		exit(1);
	}
	close(tmpfd);	
}

void check_west(t_map *map, char *line, int i)
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
		printf("Error\nMultiple attribution for 'WE' at line %i\n", i);
		exit(EXIT_FAILURE);//TODO exit normalement
	}
	if (check_postfix(map->we_path,".xpm")==0)
	{
		printf("\n WE HAHAHAHA PAS UN XPM\n");//TODO exit normalement
		exit(1);
	}
	tmpfd=open(map->we_path,O_RDONLY);
	if (tmpfd < 0)
	{
		printf("\n WE HAHAHAHA PAS UN FICHIER QUI EXISTE RATIO\n"); //TODO exit correctement
		exit(1);
	}
	close(tmpfd);	
}

void check_east(t_map *map, char *line, int i)
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
		printf("Error\nMultiple attribution for 'EUW' at line %i\n", i);
	    exit(EXIT_FAILURE);//TODO exit normalement
	}
	if (check_postfix(map->ea_path,".xpm")==0)
	{//TODO exit normalement
		printf("\n EUW HAHAHAHA PAS UN XPM\n");
		exit(1);
	}
	tmpfd=open(map->ea_path,O_RDONLY);
	if (tmpfd < 0)
	{
		printf("\n LE SERV LEAGUE QUI MARCH PAS RATIO NTM\n"); //TODO exit correctement
		exit(1);
	}
	close(tmpfd);	
}
