/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancarol9 <ancarol9@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/13 01:07:15 by ancarol9          #+#    #+#             */
/*   Updated: 2025/12/13 02:27:58 by ancarol9         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube.h"

static void	free_visited(char **v, int h)
{
	int	i;

	i = 0;
	if (!v)
		return ;
	while (i < h)
	{
		free(v[i]);
		i = i + 1;
	}
	free(v);
}

static int	flood(t_game *m, int y, int x, char **v)
{
	if (y < 0 || x < 0 || y >= m->map_height || x >= m->map_width)
	{
		printf("map not closed\n");
		return (-1);
	}
	if (m->map[y][x] == ' ')
	{
		printf("map not closed\n");
		return (-1);
	}
	if (m->map[y][x] == '1' || v[y][x])
		return (0);
	v[y][x] = 1;
	if (flood(m, y + 1, x, v) < 0 || flood(m, y - 1, x, v) < 0
		|| flood(m, y, x + 1, v) < 0 || flood(m, y, x - 1, v) < 0)
		return (-1);
	return (0);
}

static char	**alloc_visited(t_game *m)
{
	char	**v;
	int		y;

	v = (char **)ft_calloc(m->map_height, sizeof(char *));
	if (!v)
		return (NULL);
	y = 0;
	while (y < m->map_height)
	{
		v[y] = (char *)ft_calloc(m->map_width, sizeof(char));
		if (!v[y])
		{
			free_visited(v, y);
			return (NULL);
		}
		y = y + 1;
	}
	return (v);
}

static int	process_cells(t_game *game, char **vis)
{
	int	y;
	int	x;

	y = 0;
	while (y < game->map_height)
	{
		x = 0;
		while (x < game->map_width)
		{
			if (game->map[y][x] == '0' && !vis[y][x])
			{
				if (flood(game, y, x, vis) < 0)
					return (-1);
			}
			x = x + 1;
		}
		y = y + 1;
	}
	return (0);
}

int	check_map_closed(t_game *game)
{
	char	**visited;

	if (!game || !game->map)
	{
		printf("empty map");
		return (0);
	}
	visited = alloc_visited(game);
	if (!visited)
	{
		printf("malloc failure");
		return (0);
	}
	if (process_cells(game, visited) < 0)
	{
		free_visited(visited, game->map_height);
		return (0);
	}
	free_visited(visited, game->map_height);
	return (1);
}
