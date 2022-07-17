#include "so_long.h"

void initialization_structs(t_game *game)
{
	game->map = ft_calloc(1, sizeof(t_map));
	game->window = ft_calloc(1, sizeof(t_window));
	game->map->wall_img = ft_calloc(1, sizeof(t_img)); 
	game->map->floor_img = ft_calloc(1, sizeof(t_img)); 
	game->map->exit_img = ft_calloc(1, sizeof(t_img)); 
	game->map->itens_img = ft_calloc(1, sizeof(t_img)); 
	game->map->player_img = ft_calloc(1, sizeof(t_img)); 
	game->map->map_string = ft_strdup("");
}
//game->map->wall_img 

void init_structs_values(t_game *game)
{	
	game->map->collectables = 0;
	game->map->exits = 0;
	game->map->players = 0;
	game->is_there_error = 0;

	game->map->wall_img->dir = ft_strdup( "./resources/images/wall.xpm"); 
	game->map->floor_img->dir = ft_strdup( "./resources/images/floor.xpm");
	game->map->itens_img->dir = ft_strdup( "./resources/images/coin.xpm"); 
	game->map->exit_img->dir = ft_strdup( "./resources/images/exit_64.xpm"); 
	game->map->player_img->dir = ft_strdup( "./resources/images/player.xpm"); 


}