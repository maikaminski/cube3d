/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_parser.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaminski <mkaminski@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 00:00:00 by mkaminski         #+#    #+#             */
/*   Updated: 2025/12/09 00:00:00 by mkaminski        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube.h"

static void	free_lines(char **lines)
{
	int	i;

	i = 0;
	if (!lines)
		return ;
	while (lines[i])
	{
		free(lines[i]);
		i++;
	}
	free(lines);
}

static char	**read_lines(int fd)
{
	char	**lines;
	char	*line;
	int		i;

	lines = malloc(sizeof(char *) * 1000);
	if (!lines)
		error_exit(ERR_MALLOC);
	i = 0;
	line = get_next_line(fd);
	while (line != NULL)
	{
		lines[i] = line;
		i++;
		line = get_next_line(fd);
	}
	lines[i] = NULL;
	return (lines);
}

static int	validate_all(char **lines, t_game *game)
{
	if (!parse_textures(lines, game))
		return (0);
	if (!validate_textures(game))
		return (0);
	if (!parse_map(lines, game))
		return (0);
	if (!validate_map(game))
		return (0);
	return (1);
}

int	parse_file(char *filename, t_game *game)
{
	int		fd;
	char	**lines;
	int		result;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
	{
		error_exit(ERR_FILE);
		return (0);
	}
	lines = read_lines(fd);
	close(fd);
	result = validate_all(lines, game);
	free_lines(lines);
	return (result);
}

int	validate_extension(char *filename)
{
	int	len;

	len = ft_strlen(filename);
	if (len < 4)
		return (0);
	return (ft_strcmp(filename + len - 4, ".cub") == 0);
}
