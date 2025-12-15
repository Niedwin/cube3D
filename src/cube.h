/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guviure <guviure@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 19:02:48 by guviure           #+#    #+#             */
/*   Updated: 2025/12/15 19:00:45 by guviure          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE_H
# define CUBE_H

#define mapWidth 24
#define mapHeight 24
#define screenWidth 640
#define screenHeight 480
//COMMON LIBRARIES//
# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>
# include <math.h>
# include "../minilibx-linux/mlx.h"

//OTHER LIBRARIES//
# include "../Libft/libft.h"

//STRUCTS//
typedef struct	s_mlx_data
{
char ceiling[3];//saves each 0 to 255 color value as chars to save memory
char floor[3];//might be NULL terminated or undoable because ascii limits
char *north_texture;
char *south_texture;
char *east_texture;
char *west_texture;
}	t_mlx_data;
//PROTOTYPES//

#endif