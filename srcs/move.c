/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvieira- <mvieira-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 18:36:07 by mvieira-          #+#    #+#             */
/*   Updated: 2022/07/25 20:21:03 by mvieira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	get_player_p(char *map_string)
{
	int	i;

	i = 0;
	while (map_string[i] != '\0')
	{
		if (map_string[i] == 'P')
			return (i);
		i++;
	}
	return (i);
}

void	move_right(t_game *game)
{
	int	position;

	position = get_player_p(game->map->map_string);
	if (game->map->map_string[position + 1] == '0')
	{
		game->map->map_string[position] = '0';
		game->map->map_string[position + 1] = 'P';
		game->movements = game->movements + 1;
	}
	else if (game->map->map_string[position + 1] == 'C')
	{
		move_item(game, position, 1);
	}
	else if (game->map->map_string[position + 1] == 'E')
	{
		if (is_game_finished(game->itens_picked, game->map->collectables) == 1)
		{
			game->map->map_string[position] = '0';
			game->map->map_string[position + 1] = 'P';
			game->movements = game->movements + 1;
			finish_game(game);
		}
	}
	ft_printf("You made %i movements \n", game->movements);
}

void	move_left(t_game *game)
{
	int	position;

	position = get_player_p(game->map->map_string);
	if (game->map->map_string[position - 1] == '0')
	{
		game->map->map_string[position] = '0';
		game->map->map_string[position - 1] = 'P';
		game->movements = game->movements + 1;
	}
	else if (game->map->map_string[position - 1] == 'C')
	{
		move_item(game, position, -1);
	}
	else if (game->map->map_string[position - 1] == 'E')
	{
		if (is_game_finished(game->itens_picked, game->map->collectables) == 1)
		{
			game->map->map_string[position] = '0';
			game->map->map_string[position - 1] = 'P';
			game->movements = game->movements + 1;
			finish_game(game);
		}
	}
	ft_printf("You made %i movements \n", game->movements);
}

void	move_up(t_game *game)
{
	int	position;

	position = get_player_p(game->map->map_string);
	if (game->map->map_string[position - game->window->width] == '0')
	{
		game->map->map_string[position] = '0';
		game->map->map_string[position - game->window->width] = 'P';
		game->movements = game->movements + 1;
	}
	else if (game->map->map_string[position - game->window->width] == 'C')
	{
		move_item(game, position, -game->window->width);
	}
	else if (game->map->map_string[position - game->window->width] == 'E')
	{
		if (is_game_finished(game->itens_picked, game->map->collectables) == 1)
		{
			game->map->map_string[position] = '0';
			game->map->map_string[position - game->window->width] = 'P';
			game->movements = game->movements + 1;
			finish_game(game);
		}
	}
	ft_printf("You made %i movements \n", game->movements);
}

void	move_down(t_game *game)
{
	int	position;

	position = get_player_p(game->map->map_string);
	if (game->map->map_string[position + game->window->width] == '0')
	{
		game->map->map_string[position] = '0';
		game->map->map_string[position + game->window->width] = 'P';
		game->movements = game->movements + 1;
	}
	else if (game->map->map_string[position + game->window->width] == 'C')
	{
		move_item(game, position, game->window->width);
	}
	else if (game->map->map_string[position - game->window->width] == 'E')
	{
		if (is_game_finished(game->itens_picked, game->map->collectables) == 1)
		{
			game->map->map_string[position] = '0';
			game->map->map_string[position + game->window->width] = 'P';
			game->movements = game->movements + 1;
			finish_game(game);
		}
	}
	ft_printf("You made %i movements \n", game->movements);
}
