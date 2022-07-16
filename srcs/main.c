#include "so_long.h"

int	main(int argc, char *argv[])
{
	t_game		game; 
	initialization_structs(&game);
	init_structs_values(&game);
	input_validation(argc, argv[1], &game);
	open_map_validation(&game);
	exit_game(&game);
	
	//free_game_vars(&game);
	/* we will exit the loop if there's no window left, and execute this code */
	//mlx_destroy_display(game.mlx);
	//free(game.mlx);
	return (0);
}
