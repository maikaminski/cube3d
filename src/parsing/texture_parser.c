#include "../../includes/cube.h"

int	parse_textures(char **lines, t_game *game)
{
	int	i;
	char *path;

	i = 0;
	while (lines[i])
	{
		if (ft_strncmp(lines[i], "NO ", 3) == 0)
		{
			path = ft_strtrim(lines[i] + 3, " \n");
			game->textures->north = load_texture(game, path);
			free(path);
		}
		else if (ft_strncmp(lines[i], "SO ", 3) == 0)
		{
			path = ft_strtrim(lines[i] + 3, " \n");
			game->textures->south = load_texture(game, path);
			free(path);
		}
		else if (ft_strncmp(lines[i], "WE ", 3) == 0)
		{
			path = ft_strtrim(lines[i] + 3, " \n");
			game->textures->west = load_texture(game, path);
			free(path);
		}
		else if (ft_strncmp(lines[i], "EA ", 3) == 0)
		{
			path = ft_strtrim(lines[i] + 3, " \n");
			game->textures->east = load_texture(game, path);
			free(path);
		}
		else if (ft_strncmp(lines[i], "F ", 2) == 0)
			parse_color(lines[i] + 2, &game->floor_color);
		else if (ft_strncmp(lines[i], "C ", 2) == 0)
			parse_color(lines[i] + 2, &game->ceiling_color);
		i++;
	}
	return (1);
}

int	parse_color(char *color_str, t_color *color)
{
	char	**rgb;
	int		i;

	rgb = ft_split(color_str, ',');
	if (!rgb || !rgb[0] || !rgb[1] || !rgb[2])
		return (0);
	color->r = ft_atoi(rgb[0]);
	color->g = ft_atoi(rgb[1]);
	color->b = ft_atoi(rgb[2]);
	
	// Validate RGB values
	if (color->r < 0 || color->r > 255 || 
		color->g < 0 || color->g > 255 || 
		color->b < 0 || color->b > 255)
		return (0);
		
	color->hex = create_rgb(color->r, color->g, color->b);
	
	// Free rgb array
	i = 0;
	while (rgb[i])
	{
		free(rgb[i]);
		i++;
	}
	free(rgb);
	return (1);
}