/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guviure <guviure@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 19:38:50 by kguillem          #+#    #+#             */
/*   Updated: 2026/01/23 06:53:58 by kguillem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void	fill_path(char *path, char *id, char *line, int *error, int i)
{
	{
		if (path == NULL)//verify said field to proceed only if empty
		//	fill_path(path, id, line, error, i);//fill associated field
		else
		{
			printf("Error\nMultiple attribution for %s at line %i\n", id, i);
			*error ++;
		}
	}
}

