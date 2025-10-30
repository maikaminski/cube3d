#ifndef CUBE_H
# define CUBE_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <math.h>
# include <fcntl.h>
# include <string.h>
# include "../libft/libft.h"
# include "../minilibx-linux/mlx.h"

# define WINDOW_WIDTH 1024
# define WINDOW_HEIGHT 768
# define MAP_SIZE 64
# define TEXTURE_SIZE 64
# define FOV 60
# define MOVE_SPEED 0.05
# define ROT_SPEED 0.03

/* Key codes for Linux */
# define KEY_ESC 65307
# define KEY_W 119
# define KEY_A 97
# define KEY_S 115
# define KEY_D 100
# define KEY_LEFT 65361
# define KEY_RIGHT 65363

/* Error messages */
# define ERR_ARGS "Error\nUsage: ./cub3D <map.cub>\n"
# define ERR_FILE "Error\nCannot open file\n"
# define ERR_EXT "Error\nFile must have .cub extension\n"
# define ERR_MAP "Error\nInvalid map\n"
# define ERR_TEXTURE "Error\nInvalid texture\n"
# define ERR_COLOR "Error\nInvalid color\n"
# define ERR_MALLOC "Error\nMemory allocation failed\n"

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		width;
	int		height;
}	t_img;

typedef struct s_texture
{
	t_img	*north;
	t_img	*south;
	t_img	*west;
	t_img	*east;
}	t_texture;

typedef struct s_color
{
	int	r;
	int	g;
	int	b;
	int	hex;
}	t_color;

typedef struct s_player
{
	double	x;
	double	y;
	double	dir_x;
	double	dir_y;
	double	plane_x;
	double	plane_y;
}	t_player;

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
	int		hit;
	int		side;
	int		line_height;
	int		draw_start;
	int		draw_end;
}	t_ray;

typedef struct s_game
{
	void		*mlx;
	void		*win;
	t_img		*img;
	char		**map;
	int			map_width;
	int			map_height;
	t_texture	*textures;
	t_color		floor_color;
	t_color		ceiling_color;
	t_player	*player;
	int			keys[256];
}	t_game;

/* Main functions */
int		main(int argc, char **argv);
void	init_game(t_game *game);
void	game_loop(t_game *game);

/* Parsing functions */
int		parse_file(char *filename, t_game *game);
int		parse_map(char **lines, t_game *game);
int		parse_textures(char **lines, t_game *game);
int		parse_color(char *color_str, t_color *color);
int		validate_map(t_game *game);
int		validate_extension(char *filename);
int		check_walls(t_game *game);
void	init_player(t_game *game, int y, int x, char direction);

/* Raycasting functions */
void	raycasting(t_game *game);
void	init_ray(t_ray *ray, t_player *player, int x);
void	perform_dda(t_ray *ray, t_player *player, char **map);
void	calculate_wall_distance(t_ray *ray);
void	calculate_step_and_side_dist(t_ray *ray, t_player *player);

/* Graphics functions */
int		render_frame(t_game *game);
void	draw_wall(t_game *game, t_ray *ray, int x);
void	draw_background(t_game *game);
void	put_pixel(t_img *img, int x, int y, int color);
t_img	*load_texture(t_game *game, char *path);
int		get_texture_color(t_img *texture, int x, int y);

/* Player functions */
void	move_player(t_game *game);
void	rotate_player(t_game *game, double angle);
int		check_collision(t_game *game, double new_x, double new_y);

/* Event functions */
int		key_press(int keycode, t_game *game);
int		key_release(int keycode, t_game *game);
int		close_window(t_game *game);

/* Utils functions */
void	cleanup_game(t_game *game);
void	cleanup_texture(t_game *game, t_img *texture);
void	error_exit(char *message);
double	deg_to_rad(double degrees);
int		create_rgb(int r, int g, int b);

#endif