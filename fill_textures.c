/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kguillem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 19:38:50 by kguillem          #+#    #+#             */
/*   Updated: 2025/11/27 22:12:13 by kguillem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


void	check_north(struct*, char *line, int *error, int i)
{
	{
		if ()//verify said field to proceed only if empty
			truc;//indicate error, or fill associated field
		else
		{
			printf("Error\nDouble attribution for 'NO' at line %i\n", i);
			*error ++;
		}
	}
}

void	check_south(struct*, char *line, int *error, int i)
{
	{
		if ()//verify said field to proceed only if empty
			truc;//indicate error, or fill associated field
		else
		{
			printf("Error\nDouble attribution for 'SO' at line %i\n", i);
			*error ++;
		}
	}
}

void	check_west(struct*, char *line, int *error, int i)
{
	{
		if ()//verify said field to proceed only if empty
			truc;//indicate error, or fill associated field
		else
		{
			printf("Error\nDouble attribution for 'WE' at line %i\n", i);
			*error ++;
		}
	}
}

void	check_east(struct*, char *line, int *error, int i)
{
	{
		if ()//verify said field to proceed only if empty
			truc;//indicate error, or fill associated field
		else
		{
			printf("Error\nDouble attribution for 'EA' at line %i\n", i);
			*error ++;
		}
	}
}
