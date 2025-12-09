/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaminski <mkaminski@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 00:00:00 by mkaminski         #+#    #+#             */
/*   Updated: 2025/12/09 00:00:00 by mkaminski        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube.h"

static void	draw_minimap_grid(t_game *game)
{
	int		map_y;

	map_y = 0;
	while (map_y < game->map_height
		&& map_y * MINIMAP_TILE_SIZE < MINIMAP_SIZE)
	{
		draw_map_row(game, map_y);
		map_y++;
	}
}

void	draw_minimap_player(t_game *game)
{
	int	player_x;
	int	player_y;
	int	i;
	int	j;

	player_x = MINIMAP_MARGIN + (int)(game->player->x * MINIMAP_TILE_SIZE);
	player_y = MINIMAP_MARGIN + (int)(game->player->y * MINIMAP_TILE_SIZE);
	i = -2;
	while (i <= 2)
	{
		j = -2;
		while (j <= 2)
		{
			if (player_x + j >= MINIMAP_MARGIN
				&& player_x + j < MINIMAP_MARGIN + MINIMAP_SIZE
				&& player_y + i >= MINIMAP_MARGIN
				&& player_y + i < MINIMAP_MARGIN + MINIMAP_SIZE)
				put_pixel(game->img, player_x + j, player_y + i, 0xFF0000);
			j++;
		}
		i++;
	}
}

void	draw_minimap(t_game *game)
{
	draw_minimap_background(game);
	draw_minimap_grid(game);
	draw_minimap_player(game);
}
