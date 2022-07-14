#include "so_long.h"

void open_map_validation(t_game *game)
{
	int fd;
	char *map_line;
	unsigned int height;
	unsigned int width; 

	height = 0;
	fd = open(game->map->map_dir, O_RDONLY); 
	if(fd < 0)
		error_close("Cannot Read File!", game);
	map_line = get_next_line(fd);
	width = ft_strlen(map_line);
	if(map_line == NULL)
		error_close("Empty file", game); //PENSAR MELHOR AQUI. 
	height++;
	while(map_line)
	{
		map_line = get_next_line(fd);
		if(is_there_nl(map_line) != -1)
		{
			if(ft_strlen(map_line) != width)
				error_close("It is not rectangular!", game);
		}
		if(is_there_nl(map_line) == -1)
		{
		}
		if(map_line != NULL)
			ft_printf("%i \n", ft_strlen(map_line));
		height++;
		free(map_line);
	}
	ft_printf("%i",height);
	close(fd);
}