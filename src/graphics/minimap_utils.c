/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaminski <mkaminski@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 00:00:00 by mkaminski         #+#    #+#             */
/*   Updated: 2025/12/09 00:00:00 by mkaminski        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube.h"

void	draw_minimap_tile(t_game *game, int x, int y, int color)
{
	int	i;
	int	j;

	i = 0;
	while (i < MINIMAP_TILE_SIZE)
	{
		j = 0;
		while (j < MINIMAP_TILE_SIZE)
		{
			put_pixel(game->img, x + j, y + i, color);
			j++;
		}
		i++;
	}
}

void	draw_minimap_background(t_game *game)
{
	int	x;
	int	y;

	y = MINIMAP_MARGIN;
	while (y < MINIMAP_MARGIN + MINIMAP_SIZE)
	{
		x = MINIMAP_MARGIN;
		while (x < MINIMAP_MARGIN + MINIMAP_SIZE)
		{
			put_pixel(game->img, x, y, 0x000000);
			x++;
		}
		y++;
	}
}

int	get_tile_color(t_game *game, int map_y, int map_x)
{
	if (game->map[map_y][map_x] == '1')
		return (0xFFFFFF);
	else if (game->map[map_y][map_x] == '0'
		|| ft_strchr("NSEW", game->map[map_y][map_x]))
		return (0x808080);
	else
		return (0x000000);
}

void	draw_map_row(t_game *game, int map_y)
{
	int		map_x;
	int		color;

	map_x = 0;
	while (map_x < game->map_width
		&& map_x * MINIMAP_TILE_SIZE < MINIMAP_SIZE)
	{
		color = get_tile_color(game, map_y, map_x);
		draw_minimap_tile(game, MINIMAP_MARGIN + map_x
			* MINIMAP_TILE_SIZE, MINIMAP_MARGIN + map_y
			* MINIMAP_TILE_SIZE, color);
		map_x++;
	}
}
