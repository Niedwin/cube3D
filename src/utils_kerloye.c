/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_kerloye.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guviure <guviure@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/07 19:49:21 by guviure           #+#    #+#             */
/*   Updated: 2026/02/07 22:18:24 by guviure          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

char	*skip_char(char *str, char c)
{
	int	i;

	i = 0;
	while (str[i] == c)
		i++;
	return (str + i);
}

void	render_frame(t_game *game)
{
	fill_screen(game->mlx->img, 0x00333333);
	raycast(game);
	mlx_put_image_to_window(game->mlx->ptr,
		game->mlx->win, game->mlx->img->img, 0, 0);
}

void	exit_error(char *msg, t_game *game)
{
	if (game)
		cleanup(game);
	ft_putstr_fd("Error\n", 2);
	ft_putendl_fd(msg, 2);
	exit(1);
}

void	exit_error_free_line(char *msg, t_game *game, char *line)
{
	free(line);
	if (game)
		cleanup(game);
	ft_putstr_fd("Error\n", 2);
	ft_putendl_fd(msg, 2);
	exit(1);
}
