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

void free_game_vars(t_game *game)
{

	free_not_null((void *)game->map->map_dir);
	free_not_null((void *)game->map->map_string);
	free_not_null((void *)game->map);
	free_not_null((void *)game->window);
	
	
}

void free_window_vars(t_game *game)
{
	if(game->map->wall_img != NULL)
		mlx_destroy_image(game->mlx, game->map->wall_img->img);
	free_not_null((void *)game->map->wall_img->dir);
	free_not_null((void *)game->map->wall_img);
	if(game->map->floor_img != NULL)
		mlx_destroy_image(game->mlx, game->map->floor_img->img);
	free_not_null((void *)game->map->floor_img->dir);
	free_not_null((void *)game->map->floor_img);
	if(game->map->exit_img != NULL)
		mlx_destroy_image(game->mlx, game->map->exit_img->img);
	free_not_null((void *)game->map->exit_img->dir);
	free_not_null((void *)game->map->exit_img);

	if(game->map->itens_img != NULL)
		mlx_destroy_image(game->mlx, game->map->itens_img->img);
	free_not_null((void *)game->map->itens_img->dir);
	free_not_null((void *)game->map->itens_img);

	if(game->map->player_img != NULL)
		mlx_destroy_image(game->mlx, game->map->player_img->img);
	free_not_null((void *)game->map->player_img->dir);
	free_not_null((void *)game->map->player_img);

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
	free_window_vars(game);
	//free window start
	mlx_destroy_window(game->mlx, game->window->win_ptr);
	//free mlx start
	mlx_destroy_display(game->mlx);
	free(game->mlx);
	//
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