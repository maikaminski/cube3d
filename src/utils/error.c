#include "../../includes/cube.h"

void	error_exit(char *message)
{
	printf("%s", message);
	exit(1);
}

int	key_press(int keycode, t_game *game)
{
	if (keycode == KEY_ESC)
		close_window(game);
	if (keycode >= 0 && keycode < 256)
		game->keys[keycode % 256] = 1;
	return (0);
}

int	key_release(int keycode, t_game *game)
{
	if (keycode >= 0 && keycode < 256)
		game->keys[keycode % 256] = 0;
	return (0);
}

int	close_window(t_game *game)
{
	cleanup_game(game);
	exit(0);
	return (0);
}