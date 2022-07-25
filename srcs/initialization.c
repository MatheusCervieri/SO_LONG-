/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialization.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvieira- <mvieira-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 18:26:57 by mvieira-          #+#    #+#             */
/*   Updated: 2022/07/26 00:34:01 by mvieira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	initialization_structs(t_game *game)
{
	game->map = ft_calloc(1, sizeof(t_map));
	game->window = ft_calloc(1, sizeof(t_window));
	game->map->map_string = ft_strdup("");
}

void	init_structs_values(t_game *game)
{
	game->map->collectables = 0;
	game->map->exits = 0;
	game->map->players = 0;
	game->is_there_error = 0;
	game->movements = 0;
	game->itens_picked = 0;
	game->window->win_ptr = NULL;
	game->mlx = NULL;
	game->map->wall_dir = ft_strdup("./resources/images/wall.xpm");
	game->map->floor_dir = ft_strdup("./resources/images/floor.xpm");
	game->map->itens_dir = ft_strdup("./resources/images/coin.xpm");
	game->map->exit_dir = ft_strdup("./resources/images/exit_64.xpm");
	game->map->player_dir = ft_strdup("./resources/images/player.xpm");
}
