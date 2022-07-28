/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvieira- <mvieira-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 18:34:33 by mvieira-          #+#    #+#             */
/*   Updated: 2022/07/28 03:01:47 by mvieira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char *argv[])
{
	t_game		game;

	initialization_structs(&game);
	init_structs_values(&game);
	input_validation(argc, argv[1], &game);
	open_map_validation(&game);
	new_window(&game);
	handle_hooks(&game);
	mlx_loop(game.mlx);
	return (0);
}
