#include "../../includes/cube.h"

void	raycasting(t_game *game)
{
	t_ray	ray;
	int		x;

	x = 0;
	while (x < WINDOW_WIDTH)
	{
		init_ray(&ray, game->player, x);
		perform_dda(&ray, game->player, game->map);
	calculate_wall_distance(&ray, game->player);
		draw_wall(game, &ray, x);
		x++;
	}
}

void	init_ray(t_ray *ray, t_player *player, int x)
{
	ray->camera_x = 2 * x / (double)WINDOW_WIDTH - 1;
	ray->ray_dir_x = player->dir_x + player->plane_x * ray->camera_x;
	ray->ray_dir_y = player->dir_y + player->plane_y * ray->camera_x;
	ray->map_x = (int)player->x;
	ray->map_y = (int)player->y;
	
	if (ray->ray_dir_x == 0)
		ray->delta_dist_x = 1e30;
	else
		ray->delta_dist_x = fabs(1 / ray->ray_dir_x);
	
	if (ray->ray_dir_y == 0)
		ray->delta_dist_y = 1e30;
	else
		ray->delta_dist_y = fabs(1 / ray->ray_dir_y);
	
	ray->hit = 0;
}

void	calculate_wall_distance(t_ray *ray, t_player *player)
{
	/* Use player's position to compute perpendicular wall distance. Previously
	   the code mistakenly used ray_dir values where player position was needed,
	   producing incorrect distances and very small/incorrect wall heights. */
	if (ray->side == 0)
		ray->perp_wall_dist = (ray->map_x - player->x + (1 - ray->step_x) / 2.0) / ray->ray_dir_x;
	else
		ray->perp_wall_dist = (ray->map_y - player->y + (1 - ray->step_y) / 2.0) / ray->ray_dir_y;

	if (ray->perp_wall_dist <= 0)
		ray->perp_wall_dist = 1e-6; /* guard against division by zero / negative */

	ray->line_height = (int)(WINDOW_HEIGHT / ray->perp_wall_dist);
	ray->draw_start = -ray->line_height / 2 + WINDOW_HEIGHT / 2;
	if (ray->draw_start < 0)
		ray->draw_start = 0;
	ray->draw_end = ray->line_height / 2 + WINDOW_HEIGHT / 2;
	if (ray->draw_end >= WINDOW_HEIGHT)
		ray->draw_end = WINDOW_HEIGHT - 1;
}