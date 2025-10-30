#include "../../includes/cube.h"

int	check_collision(t_game *game, double new_x, double new_y)
{
	int	map_x;
	int	map_y;

	map_x = (int)new_x;
	map_y = (int)new_y;
	
	if (map_x < 0 || map_x >= game->map_width || map_y < 0 || map_y >= game->map_height)
		return (1);
	
	if (map_y < game->map_height && map_x < (int)ft_strlen(game->map[map_y]))
		return (game->map[map_y][map_x] == '1');
	
	return (1); // Treat out of bounds as collision
}