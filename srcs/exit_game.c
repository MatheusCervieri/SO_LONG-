#include "so_long.h"


void free_not_null(void *ptr)
{
	if(ptr != NULL)
	{
		free(ptr);
		ptr = NULL; 
	}
}


void exit_game(t_game *game)
{
	free_game_vars(game);
	mlx_destroy_window(game->mlx, game->window->win_ptr);
	free(game->mlx);
}



void free_game_vars(t_game *game)
{

	free_not_null((void *)game->map->map_dir);
	free_not_null((void *)game->map->map_string);
	free_not_null((void *)game->map);
	free_not_null((void *)game->window);
	//free_not_null((void *)game->map->wall_img);
}
/*
void close_mlx(t_game *game)
{

}

void close_imgs()
{

}
*/

void error_close(char *error_message, t_game *game)
{
	ft_printf("Error\n%s\n", error_message); 
	free_game_vars(game);
	exit(0);
}