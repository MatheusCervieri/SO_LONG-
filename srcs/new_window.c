#include "so_long.h"

void new_window(t_game *game)
{
	game->mlx = mlx_init();
	if (game->mlx == NULL)
		error_close("MLX Error - Can't initialise mlx \n", game);	
	
	game->window->win_ptr = mlx_new_window(game->mlx, 1920, 1080, "Hello World");
	if(game->window->win_ptr == NULL)
	{
		error_close("Error \n", game);	
	}

}
