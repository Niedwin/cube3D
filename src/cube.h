/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guviure <guviure@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 19:02:48 by guviure           #+#    #+#             */
/*   Updated: 2026/01/13 13:45:00 by kguillem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE_H
# define CUBE_H

//COMMON LIBRARIES//
# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>

//OTHER LIBRARIES//
# include "Libft/libft.h"

//STRUCTS//
typedef struct	s_header
{
char ceiling[4];//saves each 0 to 255 color value as chars to save memory
char floor[4];//last byte is set as NULL to indicate a faulty format
char *north_texture;
char *south_texture;
char *east_texture;
char *west_texture;
char **map;
unsigned int pos[2];//store position of player to facilitate rendering
}	t_header;

//PROTOTYPES//

#endif
