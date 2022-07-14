#include "so_long.h"

void input_validation(int argc, char *map_dir, t_game *game)
{
	if (argc != 2)
	{
		error_close("Invalid number of arguments", game);
	}
	else if (ft_strncmp(map_dir + ft_strlen(map_dir) - 4, ".ber", 4) != 0)
	{
		error_close("Map format invalid. It is not .ber", game);
	}
	else
	{
	game->map->map_dir = ft_strdup(map_dir);
	}
}