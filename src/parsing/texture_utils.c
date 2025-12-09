/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaminski <mkaminski@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 00:00:00 by mkaminski         #+#    #+#             */
/*   Updated: 2025/12/09 00:00:00 by mkaminski        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube.h"

static void	parse_texture_line(char **lines, int i, t_game *game, int *found)
{
	char	*path;

	if (ft_strncmp(lines[i], "NO ", 3) == 0)
	{
		path = ft_strtrim(lines[i] + 3, " \n\r\t");
		game->textures->north = load_texture(game, path);
		free(path);
		(*found)++;
	}
	else if (ft_strncmp(lines[i], "SO ", 3) == 0)
	{
		path = ft_strtrim(lines[i] + 3, " \n\r\t");
		game->textures->south = load_texture(game, path);
		free(path);
		(*found)++;
	}
}

static void	parse_texture_line2(char **lines, int i, t_game *game, int *found)
{
	char	*path;

	if (ft_strncmp(lines[i], "WE ", 3) == 0)
	{
		path = ft_strtrim(lines[i] + 3, " \n\r\t");
		game->textures->west = load_texture(game, path);
		free(path);
		(*found)++;
	}
	else if (ft_strncmp(lines[i], "EA ", 3) == 0)
	{
		path = ft_strtrim(lines[i] + 3, " \n\r\t");
		game->textures->east = load_texture(game, path);
		free(path);
		(*found)++;
	}
}

void	parse_config_line(char **lines, int i, t_game *game, int *found)
{
	parse_texture_line(lines, i, game, found);
	parse_texture_line2(lines, i, game, found);
	if (ft_strncmp(lines[i], "F ", 2) == 0)
	{
		parse_color(lines[i] + 2, &game->floor_color);
		(*found)++;
	}
	else if (ft_strncmp(lines[i], "C ", 2) == 0)
	{
		parse_color(lines[i] + 2, &game->ceiling_color);
		(*found)++;
	}
}
