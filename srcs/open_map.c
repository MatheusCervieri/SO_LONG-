#include "so_long.h"

void validation_first_and_last_line(char *line, t_game *game)
{
	unsigned int i;
	i = 0;
	while(line[i] != '\0')
	{
		if(line[i] != '1' && line[i] != '\n')
			handle_error("The map must be surrounded by walls", game);
		i++;
	}
}

void validation_map_objects(t_game *game)
{
	if (game->map->players < 1)
		error_close("Map has no player", game);
	if (game->map->players > 1)
		error_close("Map should have only one player", game);
	if (game->map->collectables < 1)
		error_close("There is no collectables", game);
	if (game->map->exits < 1) 
		error_close("The map must have a exit", game);
	if (game->map->exits > 1)
		error_close("There is more then one exit", game);
}

void validation_mid_lines(char *line, t_game *game)
{
	unsigned int i;

	i = 0;
	if(line[0] != '1')
		handle_error("The map must be surrounded by walls", game);
	if(line[ft_strlen(line) - 2] != '1')
		handle_error("The map must be surrounded by walls", game);
	while(line[i] != '\0')
	{
		if(line[i] == 'C') 
			game->map->collectables++;
		if(line[i] == 'E')
			game->map->exits++;
		if(line[i] == 'P')
			game->map->players++;
		if(line[i] != '\n' && !ft_strrchr(MAP_CHARS, line[i]))
			handle_error("Invalid char found in the map!", game);
		i++;
	}
}

void gnl_loop(int fd, unsigned int height, unsigned int width, t_game *game, char *map_line)
{
	while(map_line)
	{
		free(map_line);	
		map_line = get_next_line(fd);
		if(map_line != NULL)
		{
			if(is_there_nl(map_line) != -1)
			{
				validation_mid_lines(map_line, game);
				if(ft_strlen(map_line) != width)
				{
					//aqui precisaria ter um free. Na verdade em todo o error close precisa de um free.
					handle_error("The map is not rectangular!", game);
				}	
			}
			if(is_there_nl(map_line) == -1) 
			{
				validation_first_and_last_line(map_line, game); 
				if(ft_strlen(map_line) != width - 1)
					handle_error("The map is not rectangular!", game);
			}
			game->map->map_string = ft_strjoin_free(game->map->map_string, map_line);
			height++;
		}
	}
	ft_printf("%s", game->map->map_string);
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
	width = ft_strlen(map_line);
	validation_first_and_last_line(map_line, game); 
	game->map->map_string = ft_strjoin_free(game->map->map_string, map_line);
	height++;
	gnl_loop(fd,height,width,game,map_line);
	if(game->is_there_error == 1)
		error_close(game->error_log , game);
	validation_map_objects(game);
	close(fd);
}
