/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_iten.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvieira- <mvieira-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 19:17:23 by mvieira-          #+#    #+#             */
/*   Updated: 2022/07/23 19:26:55 by mvieira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_item(t_game *game, int position, int movement)
{
	game->map->map_string[position] = '0';
	game->map->map_string[position + movement] = 'P';
	game->movements = game->movements + 1;
	game->itens_picked = game->itens_picked + 1;
}

int	is_game_finished(int itens_picked, int collectables)
{
	if (itens_picked == collectables)
		return (1);
	return (0);
}
