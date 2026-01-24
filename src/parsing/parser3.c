/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npederen <npederen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 17:53:16 by guviure           #+#    #+#             */
/*   Updated: 2026/01/23 13:21:18 by npederen         ###   ########.fr       */
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
