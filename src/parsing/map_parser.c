#include "../../includes/cube.h"

int	parse_map(char **lines, t_game *game)
{
	int	i;
	int	map_start;

	// Find where map starts (after texture definitions)
	map_start = 0;
	while (lines[map_start] && (ft_strncmp(lines[map_start], "NO ", 3) == 0 ||
		ft_strncmp(lines[map_start], "SO ", 3) == 0 ||
		ft_strncmp(lines[map_start], "WE ", 3) == 0 ||
		ft_strncmp(lines[map_start], "EA ", 3) == 0 ||
		ft_strncmp(lines[map_start], "F ", 2) == 0 ||
		ft_strncmp(lines[map_start], "C ", 2) == 0 ||
		ft_strlen(lines[map_start]) == 0))
		map_start++;
	
	// Count map lines
	i = map_start;
	while (lines[i])
		i++;
	game->map_height = i - map_start;
	
	// Find map width
	game->map_width = 0;
	i = map_start;
	while (lines[i])
	{
		if ((int)ft_strlen(lines[i]) > game->map_width)
			game->map_width = ft_strlen(lines[i]);
		i++;
	}
	
	// Allocate and copy map
	game->map = malloc(sizeof(char *) * (game->map_height + 1));
	if (!game->map)
		error_exit(ERR_MALLOC);
	i = 0;
	while (i < game->map_height)
	{
		game->map[i] = ft_strdup(lines[map_start + i]);
		i++;
	}
	game->map[i] = NULL;
	
	return (1);
}