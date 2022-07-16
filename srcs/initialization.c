#include "so_long.h"

void initialization_structs(t_game *game)
{
	game->map = ft_calloc(1, sizeof(t_map));
	game->window = ft_calloc(1, sizeof(t_window));
	//game->map->wall_img = ft_calloc(1, sizeof(t_img));
	game->map->map_string = ft_strdup("");
}

void init_structs_values(t_game *game)
{	
	game->map->collectables = 0;
	game->map->exits = 0;
	game->map->players = 0;
	game->is_there_error = 0;
}