#include "../includes/cube.h"

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc != 2)
	{
		printf(ERR_ARGS);
		return (1);
	}
	if (!validate_extension(argv[1]))
	{
		error_exit(ERR_EXT);
		return (1);
	}
	init_game(&game);
	if (!parse_file(argv[1], &game))
	{
		/* Provide a clear message when parsing/validation fails so the
		   user understands why the window closes immediately. */
		printf(ERR_MAP);
		cleanup_game(&game);
		return (1);
	}
	game_loop(&game);
	cleanup_game(&game);
	return (0);
}

void	init_game(t_game *game)
{
	int	i;

	game->mlx = mlx_init();
	if (!game->mlx)
		error_exit(ERR_MALLOC);
	game->win = mlx_new_window(game->mlx, WINDOW_WIDTH, WINDOW_HEIGHT, "Cub3D");
	if (!game->win)
		error_exit(ERR_MALLOC);
	game->img = malloc(sizeof(t_img));
	if (!game->img)
		error_exit(ERR_MALLOC);
	game->img->img = mlx_new_image(game->mlx, WINDOW_WIDTH, WINDOW_HEIGHT);
	game->img->addr = mlx_get_data_addr(game->img->img, &game->img->bits_per_pixel,
			&game->img->line_length, &game->img->endian);
	game->textures = malloc(sizeof(t_texture));
	game->player = malloc(sizeof(t_player));
	i = 0;
	while (i < 256)
		game->keys[i++] = 0;
}

void	game_loop(t_game *game)
{
	mlx_hook(game->win, 2, 1L << 0, key_press, game);
	mlx_hook(game->win, 3, 1L << 1, key_release, game);
	mlx_hook(game->win, 17, 0, close_window, game);
	mlx_loop_hook(game->mlx, (int (*)(void *))render_frame, game);
	mlx_loop(game->mlx);
}