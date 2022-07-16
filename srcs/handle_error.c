#include "so_long.h"

void handle_error(char *error_log, t_game *game)
{
	game->error_log = error_log;
	game->is_there_error = 1;
}