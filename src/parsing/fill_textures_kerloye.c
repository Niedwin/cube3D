/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_textures_kerloye.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guviure <guviure@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 19:38:50 by kguillem          #+#    #+#             */
/*   Updated: 2026/01/22 18:35:31 by guviure          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube.h"

void check_north(t_map *map, char *line, int i)
{
	char	*new_line;
	
	if (map->no_path == NULL)
	{
		new_line = ft_strtrim(line + 2, " \t\n");
		map->no_path = ft_strdup(new_line);
		free(new_line);
	}	 // verify said field to proceed only if empty
	else
	{
		printf("Error\nMultiple attribution for 'NO' at line %i\n", i);
		exit(EXIT_FAILURE);
	}
}

void check_south(t_map *map, char *line, int i)
{
	char	*new_line;
	
	if (map->so_path == NULL)
	{
		new_line = ft_strtrim(line + 2, " \t\n");
		map->so_path = ft_strdup(new_line);
		free(new_line);
	}	 // verify said field to proceed only if empty
	else
		printf("Error\nMultiple attribution for 'NO' at line %i\n", i);
}

void check_west(t_map *map, char *line, int i)
{
	char	*new_line;
	
	if (map->we_path == NULL)
	{
		new_line = ft_strtrim(line + 2, " \t\n");
		map->we_path = ft_strdup(new_line);
		free(new_line);
	}	 // verify said field to proceed only if empty
	else
		printf("Error\nMultiple attribution for 'NO' at line %i\n", i);
}

void check_east(t_map *map, char *line, int i)
{
	char	*new_line;
	
	if (map->ea_path == NULL)
	{
		new_line = ft_strtrim(line + 2, " \t\n");
		map->ea_path = ft_strdup(new_line);
		free(new_line);
	}	 // verify said field to proceed only if empty
	else
		printf("Error\nMultiple attribution for 'NO' at line %i\n", i);
}
