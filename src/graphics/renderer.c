#include "../../includes/cube.h"

int	render_frame(t_game *game)
{
	move_player(game);
	draw_background(game);
	raycasting(game);
	mlx_put_image_to_window(game->mlx, game->win, game->img->img, 0, 0);
	return (0);
}

void	draw_background(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < WINDOW_HEIGHT / 2)
	{
		x = 0;
		while (x < WINDOW_WIDTH)
		{
			put_pixel(game->img, x, y, game->ceiling_color.hex);
			x++;
		}
		y++;
	}
	while (y < WINDOW_HEIGHT)
	{
		x = 0;
		while (x < WINDOW_WIDTH)
		{
			put_pixel(game->img, x, y, game->floor_color.hex);
			x++;
		}
		y++;
	}
}

void	put_pixel(t_img *img, int x, int y, int color)
{
	char	*dst;

	if (x >= 0 && x < WINDOW_WIDTH && y >= 0 && y < WINDOW_HEIGHT)
	{
		dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
		*(unsigned int *)dst = color;
	}
}

void	draw_wall(t_game *game, t_ray *ray, int x)
{
	int		y;
	int		color;
	t_img	*texture;

	// Select texture based on wall side
	if (ray->side == 0)
	{
		if (ray->ray_dir_x > 0)
			texture = game->textures->east;
		else
			texture = game->textures->west;
	}
	else
	{
		if (ray->ray_dir_y > 0)
			texture = game->textures->south;
		else
			texture = game->textures->north;
	}

	// Simple wall rendering without texture mapping for now
	y = ray->draw_start;
	while (y <= ray->draw_end)
	{
		if (texture)
			color = 0xFF0000; // Red placeholder
		else
			color = 0xFFFFFF; // White if no texture
		put_pixel(game->img, x, y, color);
		y++;
	}
}