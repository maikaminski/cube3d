#include "../../includes/cube.h"

int	check_collision(t_game *game, double new_x, double new_y)
{
	int	map_x;
	int	map_y;

	/* Check collision with a small radius around (new_x, new_y). We test the
	   four corners (offset by PLAYER_RADIUS) to avoid the player getting too
	   close to walls or slipping through at tile boundaries. Returns 1 if a
	   collision would occur, 0 otherwise. */
	double offs[2] = {-PLAYER_RADIUS, PLAYER_RADIUS};
	int i, j;

	for (i = 0; i < 2; ++i)
	{
		for (j = 0; j < 2; ++j)
		{
			map_x = (int)(new_x + offs[i]);
			map_y = (int)(new_y + offs[j]);

			if (map_x < 0 || map_x >= game->map_width || map_y < 0 || map_y >= game->map_height)
				return (1);

			if (map_y < game->map_height && map_x < (int)ft_strlen(game->map[map_y]))
			{
				if (game->map[map_y][map_x] == '1')
					return (1);
			}
			else
				return (1);
		}
	}
	return (0);
}