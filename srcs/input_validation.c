#include "so_long.h"

void input_validation(int argc, char *map_dir, t_game *game)
{
	if (argc != 2)
	{
		error_close("Invalid number of arguments", game);
	}
}