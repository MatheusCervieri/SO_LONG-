#include "so_long.h"

void error_close(char *error_message, t_game *game)
{
	ft_printf("Error\n%s\n", error_message);
	game->used = 2; 
}