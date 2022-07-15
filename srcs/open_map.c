#include "so_long.h"

void validation_first_and_last_line(char *line, t_game *game)
{
	unsigned int i;
	i = 0;
	while(line[i] != '\0')
	{
		if(line[i] != '1' && line[i] != '\n')
			error_close("The map must be surrounded by walls", game);
		i++;
	}
}

void validation_mid_lines(char *line, t_game *game, int width)
{
	unsigned int i;
	unsigned int collectibles;
	unsigned int exits; 
	unsigned int players; 

	collectibles = 0;
	exits = 0;
	players = 0;
	i = 0;
	if(line[0] != '1')
		error_close("The map must be surrounded by walls", game);
	if(line[width - 1] != '1')
		error_close("The map must be surrounded by walls", game);
	while(line[i] != '\0')
	{
		if(line[i] == 'C') 
			collectibles++;
		if(line[i] == 'E')
			exits++;
		if(line[i] == 'P')
			players++;
		//verify if the carachters are valid; 
		i++;
	}
}


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
	if(map_line == NULL)
		error_close("Empty file", game); 
	ft_printf("%s", map_line);
	width = ft_strlen(map_line);
	validation_first_and_last_line(map_line, game); 
	height++;
	while(map_line)
	{
		map_line = get_next_line(fd);
		if(map_line != NULL)
		{
		if(is_there_nl(map_line) != -1)
		{
			if(ft_strlen(map_line) != width)
				error_close("The map is not rectangular!", game);
		}
		if(is_there_nl(map_line) == -1) //é a última linha.
		{
			validation_first_and_last_line(map_line, game); 
			if(ft_strlen(map_line) != width - 1)
				error_close("The map is not rectangular!", game);
		}
			ft_printf("%s", map_line);
			height++;
		}
		free(map_line);
	}
	close(fd);
}

//map with walls
//map composition  - 0,1,C,E,P