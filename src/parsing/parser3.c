/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guviure <guviure@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/07 19:48:00 by guviure           #+#    #+#             */
/*   Updated: 2026/02/07 19:48:03 by guviure          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube.h"

void	verify_exceptions(t_game *game, char **map, int height)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i <= height)
	{
		if (map[i][0] == '0')
		{
			printf("Error\nLigne %i nest pas ferme\n", i);
			j = 0;
            while (j <= height)
            {
                free(map[j]);
                j++;
            }
            free(map);
            cleanup(game);
            exit(EXIT_FAILURE);
		}
		i++;
	}
}
