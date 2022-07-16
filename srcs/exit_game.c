#include "so_long.h"


void free_not_null(void *ptr)
{
	//BLABLABLA GITHUB
	if(ptr != NULL)
	{
		free(ptr);
		ptr = NULL; 
	}
}
void free_window_vars(t_game *game)
{

	free_not_null((void *)game->map->wall_img);	
	free_not_null((void *)game->mlx);	
}
void destroy_images(t_game *game)
{
	if(game->map->wall_img != NULL)
		mlx_destroy_image(game->mlx, game->map->wall_img->img);
}
void free_game_vars(t_game *game)
{

	free_not_null((void *)game->map->map_dir);
	free_not_null((void *)game->map->map_string);
	free_not_null((void *)game->map);
	free_not_null((void *)game->window);
}

/*
void exit_game(t_game *game)
{
	destroy_images(game);
	free_game_vars(game);
	mlx_destroy_window(game->mlx, game->window->win_ptr);
	game->window->win_ptr = NULL;
	mlx_destroy_display(game->mlx);
	free_window_vars(game);
	free(game->mlx);
}
*/

void exit_game(t_game *game)
{
	free_game_vars(game);
	exit(0);
}


//error close:

void error_close(char *error_message, t_game *game)
{
	ft_printf("Error\n%s\n", error_message); 
	free_game_vars(game);
	exit(0);
}