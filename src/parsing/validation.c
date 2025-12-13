/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaminski <mkaminski@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 00:00:00 by mkaminski         #+#    #+#             */
/*   Updated: 2025/12/09 00:00:00 by mkaminski        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube.h"

static int	check_char_valid(t_game *game, int i, int j, int *player_count)
{
	if (game->map[i][j] == 'N' || game->map[i][j] == 'S'
		|| game->map[i][j] == 'E' || game->map[i][j] == 'W')
	{
		(*player_count)++;
		init_player(game, i, j, game->map[i][j]);
		return (1);
	}
	else if (game->map[i][j] != '0' && game->map[i][j] != '1'
		&& game->map[i][j] != ' ' && game->map[i][j] != '\n'
		&& game->map[i][j] != '\t' && game->map[i][j] != '\r')
	{
		printf("Error\nInvalid map: unexpected character ");
		printf("0x%02x at row %d col %d\n",
			(unsigned char)game->map[i][j], i, j);
		return (0);
	}
	return (1);
}

int	validate_map(t_game *game)
{
	int	player_count;
	int	i;
	int	j;

	player_count = 0;
	i = 0;
	while (i < game->map_height)
	{
		j = 0;
		while (game->map[i][j])
		{
			if (!check_char_valid(game, i, j, &player_count))
				return (0);
			j++;
		}
		i++;
	}
	if (player_count != 1)
	{
		printf("Error\nInvalid map: expected exactly 1 player, ");
		printf("found %d\n", player_count);
		return (0);
	}
	return (check_walls(game));
}

int	check_walls(t_game *game)
{
	if (!check_map_closed(game))
		return (0);
	return (1);
}
