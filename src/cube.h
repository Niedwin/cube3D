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

# define mapWidth 24
# define mapHeight 24
# define screenWidth 640
# define screenHeight 480

# define KEY_COUNT 256
# define KEY_W 119
# define KEY_A 97
# define KEY_S 115
# define KEY_D 100
# define KEY_Q 113
# define KEY_E 101
# define KEY_ESC 65307

# define MOVE_SPEED 0.05
# define ROT_SPEED 0.04

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

typedef struct s_ray
{
	double	camera_x;
	double	ray_dir_x;
	double	ray_dir_y;
	int		map_x;
	int		map_y;
	double	side_dist_x;
	double	side_dist_y;
	double	delta_dist_x;
	double	delta_dist_y;
	double	perp_wall_dist;
	int		step_x;
	int		step_y;
	int		side;
}	t_ray;

typedef struct s_player
{
	double	x;
	double	y;
	double	dir_x;
	double	dir_y;
	double	plane_x;
	double	plane_y;
}	t_player;

typedef struct s_game
{
	void		*mlx;
	void		*win;
	t_img		img;
	t_map		map;
	t_player	player;
	int			key_press[KEY_COUNT];
}	t_game;

void	init_player(t_game *g);
void	set_direction(t_game *g, char c);

void	raycast(t_game *g);
int	game_loop(t_game *game);
int	key_release(int keycode, t_game *game);
int	key_press(int keycode, t_game *game);

void move_forward(t_game *game);
void move_backward(t_game *game);
void move_left(t_game *game);
void move_right(t_game *game);
void rotate_left(t_game *game);
void rotate_right(t_game *game);
void render_frame(t_game *game);
int close_window(t_game *game);
void exit_error(char *msg);
void put_pixel(t_img *img, int x, int y, int color);
void exit_error(char *msg);
void fill_screen(t_img *img, int color);


//PROTOTYPES//

#endif 