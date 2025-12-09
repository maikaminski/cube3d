/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaminski <mkaminski@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 00:00:00 by mkaminski         #+#    #+#             */
/*   Updated: 2025/12/09 00:00:00 by mkaminski        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube.h"

static void	cleanup_map(t_game *game)
{
	int	i;

	if (game->map)
	{
		i = 0;
		while (game->map[i])
		{
			free(game->map[i]);
			i++;
		}
		free(game->map);
	}
}

static void	cleanup_textures_helper(t_game *game)
{
	if (game->textures->north)
		cleanup_texture(game, game->textures->north);
	if (game->textures->south)
		cleanup_texture(game, game->textures->south);
	if (game->textures->west)
		cleanup_texture(game, game->textures->west);
	if (game->textures->east)
		cleanup_texture(game, game->textures->east);
	free(game->textures);
}

void	cleanup_game(t_game *game)
{
	cleanup_map(game);
	if (game->textures)
		cleanup_textures_helper(game);
	if (game->img)
	{
		if (game->img->img)
			mlx_destroy_image(game->mlx, game->img->img);
		free(game->img);
	}
	if (game->player)
		free(game->player);
	if (game->win)
		mlx_destroy_window(game->mlx, game->win);
	if (game->mlx)
	{
		mlx_destroy_display(game->mlx);
		free(game->mlx);
	}
}

void	cleanup_texture(t_game *game, t_img *texture)
{
	if (texture)
	{
		if (texture->img)
			mlx_destroy_image(game->mlx, texture->img);
		free(texture);
	}
}
