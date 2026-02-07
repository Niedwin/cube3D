/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_n_fill_colors.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guviure <guviure@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 22:04:21 by kguillem          #+#    #+#             */
/*   Updated: 2026/02/07 20:32:28 by guviure          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void	check_floor(t_game *game, char *line)
{
	if (game->map->f_rgb == -1)
		parsing_rgb(game, line, line[0]);
	else
		exit_error(" Multiple F iteration", game);
}

void	check_ceilling(t_game *game, char *line)
{
	if (game->map->c_rgb == -1)
		parsing_rgb(game, line, line[0]);
	else
		exit_error(" Multiple C iteration", game);
}

void	ft_free(char **result)
{
	int	i;

	i = 0;
	while (result[i])
	{
		free(result[i]);
		i++;
	}
}

int	ft_verif_digit(char *str)
{
	int	i;

	i = 0;
	if (str == NULL)
		return (0);
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

int	check_rgb_value(char *new_value, char **tab_value)
{
	if (new_value)
		free(new_value);
	if (!tab_value[0] || !tab_value[1] || !tab_value[2] || tab_value[3])
	{
		ft_free(tab_value);
		free(tab_value);
		return (1);
	}
	return (0);
}
