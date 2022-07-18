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

//game -> movements; 
void move_right(t_game *game)
{
	int position;
	position = get_player_p(game->map->map_string);
	if(game->map->map_string[position + 1] == '0')
	{
		game->map->map_string[position] = '0';
		game->map->map_string[position + 1] = 'P';
		game->movements = game->movements + 1; 
	}
	else if(game->map->map_string[position + 1] == 'C')
	{
		game->map->map_string[position] = '0';
		game->map->map_string[position + 1] = 'P';
		game->movements = game->movements + 1; 
		game->itens_picked = game->itens_picked + 1;
	}
	else if(game->map->map_string[position + 1] == 'E')
	{
		game->map->map_string[position] = '0';
		game->map->map_string[position + 1] = 'P';
		game->movements = game->movements + 1; 
	}
	ft_printf("You made %i movements \n", game->movements);
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


