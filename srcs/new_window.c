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
	
	int	width = 64; 
	int height = 64;
	//Initialization wall_img
	game->map->wall_img->img = mlx_xpm_file_to_image(game->mlx, game->map->wall_img->dir , &width, &height);
	if(game->map->wall_img->img == NULL)
		ft_printf("Lidar com esse erro");
	game->map->floor_img->img = mlx_xpm_file_to_image(game->mlx, game->map->floor_img->dir , &width, &height);
	game->map->itens_img->img = mlx_xpm_file_to_image(game->mlx, game->map->itens_img->dir , &width, &height);
	game->map->exit_img->img = mlx_xpm_file_to_image(game->mlx, game->map->exit_img->dir , &width, &height);
	//error - lidar
	//new window. 
	game->window->win_ptr = mlx_new_window(game->mlx, (game->window->width - 1) * SPRITE_SIZE , game->window->height * SPRITE_SIZE , "Hello World");
	if(game->window->win_ptr == NULL)
	{
		free(game->window->win_ptr);
		error_close("Error \n", game);	
	}
	mlx_put_image_to_window(game->mlx, game->window->win_ptr, game->map->wall_img->img, 0, 0);
	//mlx_put_image_to_window(game->mlx, game->window->win_ptr, game->map->floor_img->img, 128, 128);
	//mlx_put_image_to_window(game->mlx, game->window->win_ptr, game->map->itens_img->img, 64, 64);
	//mlx_put_image_to_window(game->mlx, game->window->win_ptr, game->map->exit_img->img, 200, 200);
	//initialize_imgs(game);

}


