#include "so_long.h"

void free_game_vars(t_game *game)
{
	free(game->map->map_dir);
	free(game->map);
}

void error_close(char *error_message, t_game *game)
{
	ft_printf("Error\n%s\n", error_message); 
	free_game_vars(game);
	exit(0);
}