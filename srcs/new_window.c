#include "so_long.h"

void new_window(t_game *game)
{
	void *mlx;
	void *mlx_win;
	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1920, 1080, "Hello World");
	mlx_loop(mlx);
	game->used = 5;
}