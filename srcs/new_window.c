#include "so_long.h"

/*
void initialize_imgs(t_game *game)
{
	game->map->wall_img = ft_calloc(1, sizeof(t_img));
}
*/
void new_window(t_game *game)
{
	game->mlx = mlx_init();
	if (game->mlx == NULL)
		error_close("MLX Error - Can't initialise mlx \n", game);	
	
	game->window->win_ptr = mlx_new_window(game->mlx, 400, 400, "Hello World");
	if(game->window->win_ptr == NULL)
	{
		free(game->window->win_ptr);
		error_close("Error \n", game);	
	}
	//initialize_imgs(game);

}


