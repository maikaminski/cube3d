/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collision.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaminski <mkaminski@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 00:00:00 by mkaminski         #+#    #+#             */
/*   Updated: 2025/12/09 00:00:00 by mkaminski        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube.h"

static int	check_position(t_game *game, int map_x, int map_y)
{
	if (map_x < 0 || map_x >= game->map_width
		|| map_y < 0 || map_y >= game->map_height)
		return (1);
	if (map_y < game->map_height && map_x < (int)ft_strlen(game->map[map_y]))
	{
		if (game->map[map_y][map_x] == '1')
			return (1);
		return (0);
	}
	return (1);
}

int	check_collision(t_game *game, double new_x, double new_y)
{
	double	offs[2];
	int		map_x;
	int		map_y;
	int		i;
	int		j;

	offs[0] = -PLAYER_RADIUS;
	offs[1] = PLAYER_RADIUS;
	i = 0;
	while (i < 2)
	{
		j = 0;
		while (j < 2)
		{
			map_x = (int)(new_x + offs[i]);
			map_y = (int)(new_y + offs[j]);
			if (check_position(game, map_x, map_y))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}
