#include "so_long.h"

// descobrir se foi pelo menor caminho.
// colocar os sprites corretos. 
// norminette
// makefile - ler o negócio.  

int	main(int argc, char *argv[])
{
	t_game		game; 
	initialization_structs(&game);
	init_structs_values(&game);
	input_validation(argc, argv[1], &game);
	open_map_validation(&game);
	new_window(&game);
	handle_hooks(&game);
	mlx_loop(game.mlx);
	
	//free_game_vars(&game);
	/* we will exit the loop if there's no window left, and execute this code */
	//mlx_destroy_display(game.mlx);
	//free(game.mlx);
	return (0);
}
