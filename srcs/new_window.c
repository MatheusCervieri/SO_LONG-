/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_window.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvieira- <mvieira-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 19:27:38 by mvieira-          #+#    #+#             */
/*   Updated: 2022/07/25 20:13:41 by mvieira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	make_imgs(t_game *game, int width, int height)
{
	if (game->window->win_ptr == NULL)
		exit_game("Can't open the window \n", game);
	game->map->wall_p = mlx_xpm_file_to_image(game->mlx,
			game->map->wall_dir, &width, &height);
	if (game->map->wall_p == NULL)
		exit_game("Can't load wall img \n", game);
	game->map->floor_p = mlx_xpm_file_to_image(game->mlx,
			game->map->floor_dir, &width, &height);
	if (game->map->floor_p == NULL)
		exit_game("Can't load floor img \n", game);
	game->map->itens_p = mlx_xpm_file_to_image(game->mlx,
			game->map->itens_dir, &width, &height);
	if (game->map->itens_p == NULL)
		exit_game("Can't load collectables img \n", game);
	game->map->exit_p = mlx_xpm_file_to_image(game->mlx,
			game->map->exit_dir, &width, &height);
	if (game->map->exit_p == NULL)
		exit_game("Can't load exit img \n", game);
	game->map->player_p = mlx_xpm_file_to_image(game->mlx,
			game->map->player_dir, &width, &height);
	if (game->map->player_p == NULL)
		exit_game("Can't load player img \n", game);
}

void	new_window(t_game *game)
{
	int	width;
	int	height;

	game->mlx = mlx_init();
	if (game->mlx == NULL)
		exit_game("MLX Error - Can't initialise mlx \n", game);
	width = 64;
	height = 64;
	game->window->win_ptr = mlx_new_window(game->mlx, (game->window->width - 1)
			* SPRITE_SIZE, game->window->height * SPRITE_SIZE, "SO_LONG");
	make_imgs(game, width, height);
}
