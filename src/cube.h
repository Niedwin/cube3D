/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guviure <guviure@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 19:02:48 by guviure           #+#    #+#             */
/*   Updated: 2025/12/10 19:20:38 by guviure          ###   ########.fr       */
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
char floor[4];//might be NULL terminated or undoable because ascii limits
char *north_texture;
char *south_texture;
char *east_texture;
char *west_texture;
}	t_header;
//PROTOTYPES//

#endif
