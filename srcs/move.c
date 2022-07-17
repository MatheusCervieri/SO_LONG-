#include "so_long.h"

int get_player_p(char * map_string)
{
	int i = 0;
	while(map_string[i] != '\0')
	{
		if(map_string[i] == 'P')
			return (i);
		i++;
	}
	return (i);
}


void move_right(t_game *game)
{
	int position;
	position = get_player_p(game->map->map_string);
	if(game->map->map_string[position + 1] == '0')
	{
		game->map->map_string[position] = '0';
		game->map->map_string[position + 1] = 'P';
	}
	else if(game->map->map_string[position + 1] == 'C')
	{
		game->map->map_string[position] = '0';
		game->map->map_string[position + 1] = 'P';
	}
	else if(game->map->map_string[position + 1] == 'E')
	{
		game->map->map_string[position] = '0';
		game->map->map_string[position + 1] = 'P';
	}
}

void move_left(t_game *game)
{
	int position;
	position = get_player_p(game->map->map_string);
	game->map->map_string[position] = '0';
	game->map->map_string[position - 1] = 'P';
}

void move_up(t_game *game)
{
	int position;
	position = get_player_p(game->map->map_string);
	game->map->map_string[position] = '0';
	game->map->map_string[position + 1] = 'P';
}

void move_down(t_game *game)
{
	int position;
	position = get_player_p(game->map->map_string);
	game->map->map_string[position] = '0';
	game->map->map_string[position + 1] = 'P';
}


