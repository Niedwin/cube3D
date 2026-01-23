/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guviure <guviure@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 17:53:16 by guviure           #+#    #+#             */
/*   Updated: 2026/01/23 13:37:38 by guviure          ###   ########.fr       */
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
			printf("Error\nLine %i not closed\n", i);
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
