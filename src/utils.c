/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guviure <guviure@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 18:51:48 by guviure           #+#    #+#             */
/*   Updated: 2025/12/10 19:26:26 by guviure          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "cube.h"
//charset for map : " 01NSEW" subject indicate 6 but exemple shows 7 for spaces
int	only_charset(char *str, char *set)//could indicate bad chars if needed
{
	int	i;
	int	j;

	i = 0;
	while (str[i])
	{
		j = 0;
		while (set[j])
		{
			if (str[i] == set[j])
				break ;
			j ++;
		}
		if (set[j] == '\0')
			return (0);
		i ++;
	}
	return (1);
}

/*
 * doesnt need to verify for a name before the extension, as the extension
 * itself count as a valid name.
 */
int	check_postfix(char *source, char *postfix)
{
	int	i;
	int	j;

	if (ft_strlen(postfix) > source)
		return (0);
	i = ft_strlen(source) - ft_strlen(postfix);
	j = 0;
	while (source[i])
	{
		if (source[i] != postfix[j])
			return (0);
		i ++;
		j ++;
	}
	return (1);
}

int	count_charset(char *str, char *charset)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		j = 0;
		while (charset[j])
		{
			if (str[i] == charset[j])
				count ++;
			j ++;
		}
		i ++;
	}
	return (count);
}

//might be better to not touch the path in case the spaces beetween are useful
char	*remove_newline_n_spaces(char *str)
{
	int	i;
	int	to_remove;
	char	*new;

	i = ft_strlen(str);//need to make either a cast or change func return type
	to_remove = count_charset(str, " \n");
	new = malloc(sizeof(char) * (i + 1) - to_remove);
	if (!new)
		return (NULL);
	to_remove = i - to_remove;
	while (to_remove >= 0)
	{
		while (str[i] == ' ' || str[i] == '\n')
			i --;
		new[to_remove] = str[i];
		i --;
		to_remove --;
	}
	return (new);
}
