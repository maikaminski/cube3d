#include "../../includes/cube.h"

void	cleanup_game(t_game *game)
{
	int	i;

	if (game->map)
	{
		i = 0;
		while (game->map[i])
		{
			free(game->map[i]);
			i++;
		}
		free(game->map);
	}
	if (game->textures)
	{
		if (game->textures->north)
			cleanup_texture(game, game->textures->north);
		if (game->textures->south)
			cleanup_texture(game, game->textures->south);
		if (game->textures->west)
			cleanup_texture(game, game->textures->west);
		if (game->textures->east)
			cleanup_texture(game, game->textures->east);
		free(game->textures);
	}
	if (game->img)
	{
		if (game->img->img)
			mlx_destroy_image(game->mlx, game->img->img);
		free(game->img);
	}
	if (game->player)
		free(game->player);
	if (game->win)
		mlx_destroy_window(game->mlx, game->win);
	if (game->mlx)
	{
		mlx_destroy_display(game->mlx);
		free(game->mlx);
	}
}

void	cleanup_texture(t_game *game, t_img *texture)
{
	if (texture)
	{
		if (texture->img)
			mlx_destroy_image(game->mlx, texture->img);
		free(texture);
	}
}