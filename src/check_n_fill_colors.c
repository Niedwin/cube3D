/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_n_fill_colors.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guviure <guviure@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 22:04:21 by kguillem          #+#    #+#             */
/*   Updated: 2026/01/13 15:03:29 by kguillem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*
#include "cube.h"

void	check_floor(t_header *header, char *line, int *error, int i)
{
	if (header->floor[3] == NULL)//verify said field to proceed only if empty
		fill_floor(header, line, error, i);//fill associated field
	else
	{
		printf("Error\nMultiple attribution for 'F' at line %i\n", i);
		*error ++;
	}
}

void	check_ceilling(t_header *header, char *line, int *error, int i)
{	
	if (header->ceiling[3] == NULL)//verify said field to proceed only if empty
		fill_ceiling(header, line, error, i);//fill associated field
	else
	{
		printf("Error\nMultiple attribution for 'C' at line %i\n", i);
		*error ++;
	}
}

void	fill_floor(t_header *header, char *line, int *error, int i)
{	
	line = skip_char(line + 2, ' ');
	//assess colors	
	printf("Error\n at line %i\n", i);
	error ++;
}

void	fill_ceiling(t_header *header, char *line, int *error, int i)
{
	line = skip_char(line + 2, ' ');
	//assess colors
}*/
