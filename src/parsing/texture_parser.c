/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_parser.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaminski <mkaminski@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 00:00:00 by mkaminski         #+#    #+#             */
/*   Updated: 2025/12/09 00:00:00 by mkaminski        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube.h"

int	validate_textures(t_game *game)
{
	if (!game->textures->north || !game->textures->south
		|| !game->textures->west || !game->textures->east)
	{
		error_exit("Failed to load textures");
		return (0);
	}
	return (1);
}

int	parse_textures(char **lines, t_game *game)
{
	int		i;
	int		found;

	i = 0;
	found = 0;
	while (lines[i] && found < 6)
	{
		parse_config_line(lines, i, game, &found);
		i++;
	}
	return (found == 6);
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
	if (color->r < 0 || color->r > 255
		|| color->g < 0 || color->g > 255
		|| color->b < 0 || color->b > 255)
		return (0);
	color->hex = create_rgb(color->r, color->g, color->b);
	i = 0;
	while (rgb[i])
	{
		free(rgb[i]);
		i++;
	}
	free(rgb);
	return (1);
}
