/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guviure <guviure@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 17:53:36 by guviure           #+#    #+#             */
/*   Updated: 2026/01/22 17:53:36 by guviure          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE_H
# define CUBE_H

# define MAPWIDTH 24
# define MAPHEIGHT 24
# define SCREENWIDTH 1024
# define SCREENHEIGHT 720

# define KEY_COUNT 256
# define KEY_W 119
# define KEY_A 97
# define KEY_S 115
# define KEY_D 100
# define KEY_LEFT_ARROW 65361
# define KEY_RIGHT_ARROW 65363
# define KEY_ESC 65307

# define MOVE_SPEED 0.05
# define ROT_SPEED 0.04

# include "../minilibx-linux/mlx.h"
# include <fcntl.h>
# include <math.h>
# include <stdio.h>
# include <stdlib.h>

# include "../Libft/libft.h"

typedef struct s_vec2
{
	double	x;
	double	y;
}	t_vec2;

typedef struct s_img
{
	void	*img;
	int		*addr;
	int		bpp;
	int		line_len;
	int		endian;
	int		width;
	int		height;
}	t_img;

typedef struct s_textures
{
	t_img	*no;
	t_img	*so;
	t_img	*we;
	t_img	*ea;
}	t_textures;

typedef struct s_map
{
	char	**map_tab;
	int		f_rgb;
	int		c_rgb;
	int		height;
	int		width;
	char	*no_path;
	char	*so_path;
	char	*we_path;
	char	*ea_path;
}	t_map;

typedef struct s_player
{
	t_vec2	pos;
	t_vec2	dir;
	t_vec2	plane;
}	t_player;

typedef struct s_ray
{
	t_vec2	ray_dir;
	t_vec2	side_dist;
	t_vec2	delta_dist;
	t_vec2	map;
	t_vec2	step;
	double	camera_x;
	double	perp_wall_dist;
	int		side;
	int		line_height;
	int		tex_x;
	int		tex_y;
	double	wall_x;
	double	tex_pos;
	double	stepp;
	t_img	*tex;
}	t_ray;

typedef struct s_draw
{
	int	x;
	int	start;
	int	end;
}	t_draw;

typedef struct s_mlx
{
	void	*ptr;
	void	*win;
	t_img	*img;
}	t_mlx;

typedef struct s_game
{
	t_mlx		*mlx;
	void		*win;
	t_map		*map;
	t_player	player;
	t_textures	*tex;
	int			key_press[KEY_COUNT];
	int			rot_left;
	int			rot_right;
}	t_game;

void	init_player(t_game *g);
void	set_direction(t_game *g, char c);
void	raycast(t_game *g);
int		game_loop(t_game *game);
int		key_release(int keycode, t_game *game);
int		key_press(int keycode, t_game *game);
void	move_forward(t_game *game);
void	move_backward(t_game *game);
void	move_left(t_game *game);
void	move_right(t_game *game);
void	rotate_left(t_game *game);
void	rotate_right(t_game *game);
void	render_frame(t_game *game);
int		close_window(t_game *game);
void	load_texture(t_game *g, t_img *tex, char *path);
void	load_all_textures(t_game *g);
int		parse_rgb(char *line);
t_img	*choose_texture(t_game *g, t_ray *r);
void	get_tex_pos(t_game *g, t_ray *r, t_draw d);
void	draw_floor(t_game *g, t_draw d);
void	draw_ceiling(t_game *g, t_draw d);
void	draw_wall(t_game *g, t_ray *r, t_draw d);
void	free_map_tab(t_map *map);
void	free_map_paths(t_map *map);
void	free_img(t_mlx *mlx, t_img *img);
void	free_textures(t_game *game);
void	free_screen(t_game *game);
void	free_mlx(t_game *game);
void	cleanup(t_game *game);
void	exit_error(char *msg, t_game *game);
int		check_args_n_fd(int argc, char **argv);
int		check_postfix(char *source, char *postfix);
void	load_and_read_map(t_game *game, char *filename);
void	free_map_tab(t_map *map);
void	free_map_paths(t_map *map);
int		fill_fields(t_game *game, int *map_status, char *line);
void	check_south(t_game *game, t_map *map, char *line);
void	check_west(t_game *game, t_map *map, char *line);
void	check_north(t_game *game, t_map *map, char *line);
void	check_east(t_game *game, t_map *map, char *line);
void	verify_exceptions(t_game *game, char **map, int height);
void	check_floor(t_game *game, char *line);
void	check_ceilling(t_game *game, char *line);
char	*skip_char(char *str, char c);
int		is_map(char *line);
int		only_charset(char *str, char *set);
void	free_rgb_split(char **split);
void	free_img(t_mlx *mlx, t_img *img);
int		ft_verif_digit(char	*str);
void	free_textures(t_game *game);
int		check_rgb_limit(int r, int g, int b, char **tab_value);
void	free_mlx(t_game *game);
void	ft_free_split(char **split);
void	cleanup(t_game *game);
void	free_map_tab(t_map *map);
void	free_mlx(t_game *game);
void	free_rgb_split(char **split);
void	free_map_paths(t_map *map);
void	fill_rgb_data(t_game *game, char **split_rgb,
			char direction, char *line);
void	free_img(t_mlx *mlx, t_img *img);
void	parsing_rgb(t_game *game, char *line, char direction);
void	free_textures(t_game *game);
void	cleanup_gnl(int fd);
char	*get_next_line(int fd);
int		checkstrchar(char c, char *str);
int		char_count(char *str, char c);
void	exit_error_free_line(char *msg, t_game *game, char *line);
void	init_hooks(t_game *game);
void	init_mlx(t_mlx *mlx, t_game *game);
int		close_window(t_game *game);
int		get_pixel(t_img *image, int x, int y);
void	put_pixel(t_img *img, int x, int y, int color);
void	fill_screen(t_img *img, int color);
void	print_map(t_map *map);
void	color_format(t_game *game, char *rgb_line, char *line);
int		read_data_file(t_game *game, int fd);
void	fill_map(t_game *game, int fd);
int		check_char_map(t_game *game);
int		check_open_map(t_game *game);
int		close_window(t_game *game);
char	*remove_newline_n_spaces(char *str);

#endif
