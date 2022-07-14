#include "so_long.h"

void open_map_validation(t_game *game)
{
	int fd;
	fd = open(game->map->map_dir, O_RDONLY); 
	char *gnl = (char *) "a";
	if(fd < 0)
	{
		error_close("Cannot Read File!", game);
	}
	while(gnl)
	{
		gnl = get_next_line(fd);
		ft_printf("%s", gnl);
		free(gnl);
	}
	close(fd);
}