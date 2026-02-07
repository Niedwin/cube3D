/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_textures_kerloye.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guviure <guviure@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 19:38:50 by kguillem          #+#    #+#             */
/*   Updated: 2026/02/07 17:03:48 by guviure          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube.h"

void check_north(t_game *game, t_map *map, char *line)
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
		free(line);
		exit_error(" Multiple NO iteration", game);
	}
	if (check_postfix(map->no_path,".xpm")==0)
	{
		free(line);
		exit_error(" Not an XPM file", game);
	}
	tmpfd=open(map->no_path,O_RDONLY);
	if (tmpfd < 0)
	{
		free(line);
		exit_error(" Can't open texture file", game);
	}
	close(tmpfd);	
}

void check_south(t_game *game, t_map *map, char *line)
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
		free(line);
		exit_error(" Multiple SO iteration", game);
	}
	if (check_postfix(map->so_path,".xpm")==0)
	{
		free(line);
		exit_error(" Not an XPM file", game);
	}
	tmpfd=open(map->so_path,O_RDONLY);
	if (tmpfd < 0)
	{
		free(line);
		exit_error(" Can't open texture file", game);
	}
	close(tmpfd);	
}

void check_west(t_game *game, t_map *map, char *line)
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
		free(line);
		exit_error(" Multiple WE iteration", game);
	}
	if (check_postfix(map->we_path,".xpm")==0)
	{
		free(line);
		exit_error(" Not an XPM file", game);
	}
	tmpfd=open(map->we_path,O_RDONLY);
	if (tmpfd < 0)
	{
		free(line);
		exit_error(" Can't open texture file", game);
	}
	close(tmpfd);	
}

void check_east(t_game *game, t_map *map, char *line)
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
		free(line);
		exit_error(" Multiple EA iteration", game);
	}
	if (check_postfix(map->ea_path,".xpm")==0)
	{
		free(line);
		exit_error(" Not an XPM file", game);
	}
	tmpfd=open(map->ea_path,O_RDONLY);
	if (tmpfd < 0)
	{
		free(line);
		exit_error(" Can't open texture file", game);
	}
	close(tmpfd);	
}
