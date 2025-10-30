#include "../../includes/cube.h"

int	parse_file(char *filename, t_game *game)
{
	int		fd;
	char	*line;
	char	**lines;
	int		i;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
	{
		error_exit(ERR_FILE);
		return (0);
	}
	lines = malloc(sizeof(char *) * 1000); // Temporary size
	if (!lines)
		error_exit(ERR_MALLOC);
	i = 0;
	while ((line = get_next_line(fd)) != NULL)
	{
		lines[i] = line;
		i++;
	}
	lines[i] = NULL;
	close(fd);
	if (!parse_textures(lines, game) || !parse_map(lines, game))
	{
		// Free lines
		free(lines);
		return (0);
	}
	free(lines);
	return (validate_map(game));
}

int	validate_extension(char *filename)
{
	int	len;

	len = ft_strlen(filename);
	if (len < 4)
		return (0);
	return (ft_strcmp(filename + len - 4, ".cub") == 0);
}