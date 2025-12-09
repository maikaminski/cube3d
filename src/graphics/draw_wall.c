/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_wall.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaminski <mkaminski@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 00:00:00 by mkaminski         #+#    #+#             */
/*   Updated: 2025/12/09 00:00:00 by mkaminski        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube.h"

static t_img	*select_texture(t_game *game, t_ray *ray)
{
	t_img	*texture;

	if (ray->side == 0)
	{
		if (ray->ray_dir_x > 0)
			texture = game->textures->east;
		else
			texture = game->textures->west;
	}
	else
	{
		if (ray->ray_dir_y > 0)
			texture = game->textures->south;
		else
			texture = game->textures->north;
	}
	return (texture);
}

static void	draw_no_texture(t_game *game, t_ray *ray, int x)
{
	int	y;

	y = ray->draw_start;
	while (y <= ray->draw_end)
	{
		put_pixel(game->img, x, y, 0xFFFFFF);
		y++;
	}
}

static void	calculate_texture_params(t_ray *ray, t_img *texture,
		t_player *player, int *tex_x)
{
	double	wall_x;

	if (ray->side == 0)
		wall_x = player->y + ray->perp_wall_dist * ray->ray_dir_y;
	else
		wall_x = player->x + ray->perp_wall_dist * ray->ray_dir_x;
	wall_x -= floor(wall_x);
	*tex_x = (int)(wall_x * (double)texture->width);
	if ((ray->side == 0 && ray->ray_dir_x > 0)
		|| (ray->side == 1 && ray->ray_dir_y < 0))
		*tex_x = texture->width - *tex_x - 1;
}

static void	draw_textured_line(t_game *game, t_ray *ray, t_img *texture,
		int x)
{
	int		y;
	int		color;
	int		tex_x;
	int		tex_y;
	double	tex_step_pos[2];

	calculate_texture_params(ray, texture, game->player, &tex_x);
	tex_step_pos[0] = (double)texture->height / (double)ray->line_height;
	tex_step_pos[1] = (ray->draw_start - WINDOW_HEIGHT / 2
			+ ray->line_height / 2) * tex_step_pos[0];
	y = ray->draw_start;
	while (y <= ray->draw_end)
	{
		tex_y = (int)tex_step_pos[1] & (texture->height - 1);
		tex_step_pos[1] += tex_step_pos[0];
		color = get_texture_color(texture, tex_x, tex_y);
		put_pixel(game->img, x, y, color);
		y++;
	}
}

void	draw_wall(t_game *game, t_ray *ray, int x)
{
	t_img	*texture;

	texture = select_texture(game, ray);
	if (!texture)
	{
		draw_no_texture(game, ray, x);
		return ;
	}
	draw_textured_line(game, ray, texture, x);
}
