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
typedef struct	s_img
{
void    *img;
char    *addr;
int     bpp;
int     line_len;
int     endian;
}	t_img;

typedef struct s_map
{
	char		**map_tab;
	int			F_rgb;
	int			C_rgb;
	int			Heightmap;
	int			Widthmap;
}   t_map;
//PROTOTYPES//

#endif