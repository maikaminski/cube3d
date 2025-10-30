#include "../../includes/cube.h"

t_img	*create_image(t_game *game, int width, int height)
{
	t_img	*img;

	img = malloc(sizeof(t_img));
	if (!img)
		return (NULL);
	img->img = mlx_new_image(game->mlx, width, height);
	if (!img->img)
	{
		free(img);
		return (NULL);
	}
	img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel,
			&img->line_length, &img->endian);
	img->width = width;
	img->height = height;
	return (img);
}

void	destroy_image(t_game *game, t_img *img)
{
	if (img)
	{
		if (img->img)
			mlx_destroy_image(game->mlx, img->img);
		free(img);
	}
}