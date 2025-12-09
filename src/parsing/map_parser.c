/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaminski <mkaminski@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 00:00:00 by mkaminski         #+#    #+#             */
/*   Updated: 2025/12/09 00:00:00 by mkaminski        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube.h"

static int	is_blank_line(char *line)
{
	int	k;

	k = 0;
	while (line[k] && (line[k] == ' ' || line[k] == '\t'
			|| line[k] == '\n' || line[k] == '\r'))
		k++;
	return (line[k] == '\0');
}

static int	is_config_line(char *line)
{
	if (ft_strncmp(line, "NO ", 3) == 0
		|| ft_strncmp(line, "SO ", 3) == 0
		|| ft_strncmp(line, "WE ", 3) == 0
		|| ft_strncmp(line, "EA ", 3) == 0
		|| ft_strncmp(line, "F ", 2) == 0
		|| ft_strncmp(line, "C ", 2) == 0)
		return (1);
	return (0);
}

static int	find_map_start(char **lines)
{
	int	map_start;

	map_start = 0;
	while (lines[map_start] && (is_config_line(lines[map_start])
			|| is_blank_line(lines[map_start])))
		map_start++;
	return (map_start);
}

static void	copy_map_lines(char **lines, t_game *game, int map_start)
{
	int	i;

	i = 0;
	while (i < game->map_height)
	{
		game->map[i] = ft_strdup(lines[map_start + i]);
		i++;
	}
	game->map[i] = NULL;
}

int	parse_map(char **lines, t_game *game)
{
	int	i;
	int	map_start;

	map_start = find_map_start(lines);
	i = map_start;
	while (lines[i])
		i++;
	game->map_height = i - map_start;
	game->map_width = 0;
	i = map_start;
	while (lines[i])
	{
		if ((int)ft_strlen(lines[i]) > game->map_width)
			game->map_width = ft_strlen(lines[i]);
		i++;
	}
	game->map = malloc(sizeof(char *) * (game->map_height + 1));
	if (!game->map)
		error_exit(ERR_MALLOC);
	copy_map_lines(lines, game, map_start);
	return (1);
}
