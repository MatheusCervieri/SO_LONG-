#include "so_long.h"

int	main(int argc, char *argv[])
{
	t_game		game; 
	initialization_structs(&game);
	init_structs_values(&game);
	input_validation(argc, argv[1], &game);
	open_map_validation(&game);
	//new_window(&game);
	return (0);
}
