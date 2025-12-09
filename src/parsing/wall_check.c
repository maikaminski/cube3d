/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaminski <mkaminski@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 00:00:00 by mkaminski         #+#    #+#             */
/*   Updated: 2025/12/09 00:00:00 by mkaminski        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube.h"

static int	check_top_wall(t_game *game, int i)
{
	if (i < (int)ft_strlen(game->map[0]))
	{
		if (game->map[0][i] != '1' && game->map[0][i] != ' '
			&& game->map[0][i] != '\t' && game->map[0][i] != '\r'
			&& game->map[0][i] != '\n')
		{
			printf("Error\nInvalid map: top row not closed at col ");
			printf("%d (byte 0x%02x)\n", i, (unsigned char)game->map[0][i]);
			return (0);
		}
	}
	return (1);
}

static int	check_bottom_wall(t_game *game, int i)
{
	int	row;

	row = game->map_height - 1;
	if (i < (int)ft_strlen(game->map[row]))
	{
		if (game->map[row][i] != '1' && game->map[row][i] != ' '
			&& game->map[row][i] != '\t' && game->map[row][i] != '\r'
			&& game->map[row][i] != '\n')
		{
			printf("Error\nInvalid map: bottom row not closed at col ");
			printf("%d (byte 0x%02x)\n", i, (unsigned char)game->map[row][i]);
			return (0);
		}
	}
	return (1);
}

int	check_top_bottom_walls(t_game *game)
{
	int	i;

	i = 0;
	while (i < game->map_width)
	{
		if (!check_top_wall(game, i))
			return (0);
		if (!check_bottom_wall(game, i))
			return (0);
		i++;
	}
	return (1);
}

static int	check_right_edge(t_game *game, int i)
{
	int	last_char;

	if ((int)ft_strlen(game->map[i]) > 0)
	{
		last_char = ft_strlen(game->map[i]) - 1;
		if (game->map[i][last_char] != '1'
			&& game->map[i][last_char] != ' '
			&& game->map[i][last_char] != '\n'
			&& game->map[i][last_char] != '\t'
			&& game->map[i][last_char] != '\r')
		{
			printf("Error\nInvalid map: right edge not closed at row ");
			printf("%d (byte 0x%02x)\n", i,
				(unsigned char)game->map[i][last_char]);
			return (0);
		}
	}
	return (1);
}

int	check_side_walls(t_game *game)
{
	int	i;

	i = 0;
	while (i < game->map_height)
	{
		if (game->map[i][0] != '1' && game->map[i][0] != ' '
			&& game->map[i][0] != '\t' && game->map[i][0] != '\r')
		{
			printf("Error\nInvalid map: left edge not closed at row ");
			printf("%d (byte 0x%02x)\n", i, (unsigned char)game->map[i][0]);
			return (0);
		}
		if (!check_right_edge(game, i))
			return (0);
		i++;
	}
	return (1);
}
