#include "../../includes/cube.h"

int	parse_map(char **lines, t_game *game)
{
	int	i;
	int	map_start;

	// Find where map starts (after texture definitions)
	map_start = 0;
	/* Skip header lines (texture/color definitions) and any blank lines
	   (lines that contain only whitespace/newline). This avoids treating
	   an empty line as the start of the map when get_next_line returns
	   a string containing only '\n'. */
	while (lines[map_start] && (
		ft_strncmp(lines[map_start], "NO ", 3) == 0 ||
		ft_strncmp(lines[map_start], "SO ", 3) == 0 ||
		ft_strncmp(lines[map_start], "WE ", 3) == 0 ||
		ft_strncmp(lines[map_start], "EA ", 3) == 0 ||
		ft_strncmp(lines[map_start], "F ", 2) == 0 ||
		ft_strncmp(lines[map_start], "C ", 2) == 0 ||
		/* treat lines with only spaces/tabs/CR/LF as blank */
		({
			int _k = 0; char *_s = lines[map_start];
			while (_s[_k] && (_s[_k] == ' ' || _s[_k] == '\t' || _s[_k] == '\n' || _s[_k] == '\r'))
				_k++;
			_s[_k] == '\0';
		})))
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
