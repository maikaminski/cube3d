#include "../../includes/cube.h"

int	validate_map(t_game *game)
{
	int	player_count;
	int	i;
	int	j;

	player_count = 0;
	i = 0;
	while (i < game->map_height)
	{
		j = 0;
		while (game->map[i][j])
		{
			if (game->map[i][j] == 'N' || game->map[i][j] == 'S' ||
				game->map[i][j] == 'E' || game->map[i][j] == 'W')
			{
				player_count++;
				init_player(game, i, j, game->map[i][j]);
			}
			else if (game->map[i][j] != '0' && game->map[i][j] != '1' && 
					 game->map[i][j] != ' ' && game->map[i][j] != '\n')
				return (0);
			j++;
		}
		i++;
	}
	if (player_count != 1)
		return (0);
	return (check_walls(game));
}

int	check_walls(t_game *game)
{
	int	i;

	// Check first and last rows
	i = 0;
	while (i < game->map_width)
	{
		if (i < (int)ft_strlen(game->map[0]))
			if (game->map[0][i] != '1' && game->map[0][i] != ' ')
				return (0);
		if (i < (int)ft_strlen(game->map[game->map_height - 1]))
			if (game->map[game->map_height - 1][i] != '1' && 
				game->map[game->map_height - 1][i] != ' ')
				return (0);
		i++;
	}
	// Check first and last columns of each row
	i = 0;
	while (i < game->map_height)
	{
		if (game->map[i][0] != '1' && game->map[i][0] != ' ')
			return (0);
		if ((int)ft_strlen(game->map[i]) > 0)
		{
			int last_char = ft_strlen(game->map[i]) - 1;
			if (game->map[i][last_char] != '1' && 
				game->map[i][last_char] != ' ' && 
				game->map[i][last_char] != '\n')
				return (0);
		}
		i++;
	}
	return (1);
}

void	init_player(t_game *game, int y, int x, char direction)
{
	game->player->x = x + 0.5;
	game->player->y = y + 0.5;
	if (direction == 'N')
	{
		game->player->dir_x = 0;
		game->player->dir_y = -1;
		game->player->plane_x = 0.66;
		game->player->plane_y = 0;
	}
	else if (direction == 'S')
	{
		game->player->dir_x = 0;
		game->player->dir_y = 1;
		game->player->plane_x = -0.66;
		game->player->plane_y = 0;
	}
	else if (direction == 'E')
	{
		game->player->dir_x = 1;
		game->player->dir_y = 0;
		game->player->plane_x = 0;
		game->player->plane_y = 0.66;
	}
	else if (direction == 'W')
	{
		game->player->dir_x = -1;
		game->player->dir_y = 0;
		game->player->plane_x = 0;
		game->player->plane_y = -0.66;
	}
}