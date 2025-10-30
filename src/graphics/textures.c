#include "../../includes/cube.h"

t_img	*load_texture(t_game *game, char *path)
{
	t_img	*texture;

	texture = malloc(sizeof(t_img));
	if (!texture)
		return (NULL);
	texture->img = mlx_xpm_file_to_image(game->mlx, path, &texture->width, &texture->height);
	if (!texture->img)
	{
		free(texture);
		return (NULL);
	}
	texture->addr = mlx_get_data_addr(texture->img, &texture->bits_per_pixel,
			&texture->line_length, &texture->endian);
	return (texture);
}

int	get_texture_color(t_img *texture, int x, int y)
{
	char	*dst;

	if (!texture || x < 0 || x >= texture->width || y < 0 || y >= texture->height)
		return (0);
	dst = texture->addr + (y * texture->line_length + x * (texture->bits_per_pixel / 8));
	return (*(unsigned int *)dst);
}