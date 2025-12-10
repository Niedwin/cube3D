/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_colors.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guviure <guviure@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 22:04:21 by kguillem          #+#    #+#             */
/*   Updated: 2025/12/10 19:25:52 by guviure          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void	check_floor(t_header *header, char *line, int *error, int i)
{

	{
		if ()//verify said field to proceed only if empty
			truc;//indicate error, or fill associated field
		else
		{
			printf("Error\nDouble attribution for 'F' at line %i\n", i);
			*error ++;
		}
	}

}

void	check_ceilling(struct*, char *line, int *error, int i)
{	
	{
		if ()//verify said field to proceed only if empty
			truc;//indicate error, or fill associated field
		else
		{
			printf("Error\nDouble attribution for 'C' at line %i\n", i);
			*error ++;
		}
	}
}

