/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_window.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvieira- <mvieira-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 19:27:38 by mvieira-          #+#    #+#             */
/*   Updated: 2022/07/28 03:14:52 by mvieira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	make_imgs(t_game *game, int width, int height)
{
	if (game->window->win_ptr == NULL)
		exit_game("Can't open the window", game);
	game->map->wall_p = mlx_xpm_file_to_image(game->mlx,
			game->map->wall_dir, &width, &height);
	if (game->map->wall_p == NULL)
		exit_game("Can't load wall img", game);
	game->map->floor_p = mlx_xpm_file_to_image(game->mlx,
			game->map->floor_dir, &width, &height);
	if (game->map->floor_p == NULL)
		exit_game("Can't load floor img", game);
	game->map->itens_p = mlx_xpm_file_to_image(game->mlx,
			game->map->itens_dir, &width, &height);
	if (game->map->itens_p == NULL)
		exit_game("Can't load collectables img", game);
	game->map->exit_p = mlx_xpm_file_to_image(game->mlx,
			game->map->exit_dir, &width, &height);
	if (game->map->exit_p == NULL)
		exit_game("Can't load exit img", game);
	game->map->player_p = mlx_xpm_file_to_image(game->mlx,
			game->map->player_dir, &width, &height);
	if (game->map->player_p == NULL)
		exit_game("Can't load player img", game);
}

void	new_window(t_game *game)
{
	int	width;
	int	height;

	game->mlx = mlx_init();
	if (game->mlx == NULL)
		exit_game("MLX Error - Can't initialise mlx", game);
	width = 64;
	height = 64;
	game->window->win_ptr = mlx_new_window(game->mlx, (game->window->width - 1)
			* SPRITE_SIZE, game->window->height * SPRITE_SIZE, "SO_LONG");
	make_imgs(game, width, height);
}
