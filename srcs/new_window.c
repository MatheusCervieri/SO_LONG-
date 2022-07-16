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
	
	void *img;
	int	width = 64; 
	int height = 64;
	img = mlx_xpm_file_to_image(game->mlx, "./exit_64.xpm", &width, &height);

	//new window. 
	game->window->win_ptr = mlx_new_window(game->mlx, 400, 400, "Hello World");
	if(game->window->win_ptr == NULL)
	{
		free(game->window->win_ptr);
		error_close("Error \n", game);	
	}
	mlx_put_image_to_window(game->mlx, game->window->win_ptr, img, 0, 0);
	//initialize_imgs(game);

}


