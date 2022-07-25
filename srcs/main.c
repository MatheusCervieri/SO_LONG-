/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvieira- <mvieira-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 18:34:33 by mvieira-          #+#    #+#             */
/*   Updated: 2022/07/25 19:24:02 by mvieira-         ###   ########.fr       */
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

/*
2- Open_map - falta arrumar.
3- draw_static_map. 
4- Norm
5- Makefile.
*/