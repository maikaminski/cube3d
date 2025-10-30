#include "../../includes/cube.h"

void	move_player(t_game *game)
{
	double	new_x;
	double	new_y;

	new_x = game->player->x;
	new_y = game->player->y;
	
	if (game->keys[KEY_W])
	{
		new_x += game->player->dir_x * MOVE_SPEED;
		new_y += game->player->dir_y * MOVE_SPEED;
	}
	if (game->keys[KEY_S])
	{
		new_x -= game->player->dir_x * MOVE_SPEED;
		new_y -= game->player->dir_y * MOVE_SPEED;
	}
	if (game->keys[KEY_A])
	{
		new_x += game->player->dir_y * MOVE_SPEED;
		new_y -= game->player->dir_x * MOVE_SPEED;
	}
	if (game->keys[KEY_D])
	{
		new_x -= game->player->dir_y * MOVE_SPEED;
		new_y += game->player->dir_x * MOVE_SPEED;
	}
	
	if (!check_collision(game, new_x, game->player->y))
		game->player->x = new_x;
	if (!check_collision(game, game->player->x, new_y))
		game->player->y = new_y;
	
	if (game->keys[KEY_LEFT])
		rotate_player(game, ROT_SPEED);
	if (game->keys[KEY_RIGHT])
		rotate_player(game, -ROT_SPEED);
}

void	rotate_player(t_game *game, double angle)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = game->player->dir_x;
	game->player->dir_x = game->player->dir_x * cos(angle) - game->player->dir_y * sin(angle);
	game->player->dir_y = old_dir_x * sin(angle) + game->player->dir_y * cos(angle);
	old_plane_x = game->player->plane_x;
	game->player->plane_x = game->player->plane_x * cos(angle) - game->player->plane_y * sin(angle);
	game->player->plane_y = old_plane_x * sin(angle) + game->player->plane_y * cos(angle);
}