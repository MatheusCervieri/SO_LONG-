/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_loop.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvieira- <mvieira-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 21:23:05 by mvieira-          #+#    #+#             */
/*   Updated: 2022/07/25 19:54:27 by mvieira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	draw_char(char c, t_game *game, int width, int height)
{
	if (c == 'P')
	{
		mlx_put_image_to_window(game->mlx, game->window->win_ptr,
			game->map->player_p, width * SPRITE_SIZE, height * SPRITE_SIZE);
	}	
	if (c == '1')
	{
		mlx_put_image_to_window(game->mlx, game->window->win_ptr,
			game->map->wall_p, width * SPRITE_SIZE, height * SPRITE_SIZE);
	}
	if (c == '0')
	{
		mlx_put_image_to_window(game->mlx, game->window->win_ptr,
			game->map->floor_p, width * SPRITE_SIZE, height * SPRITE_SIZE);
	}
	if (c == 'C')
	{
		mlx_put_image_to_window(game->mlx, game->window->win_ptr,
			game->map->itens_p, width * SPRITE_SIZE, height * SPRITE_SIZE);
	}
	if (c == 'E')
	{
		mlx_put_image_to_window(game->mlx, game->window->win_ptr,
			game->map->exit_p, width * SPRITE_SIZE, height * SPRITE_SIZE);
	}

}

void	draw_map(t_game *game)
{
	int	i;
	int	height;
	int	width;

	height = 0;
	width = 0;
	i = 0;
	while (game->map->map_string[i] != '\0')
	{
		draw_char(game->map->map_string[i], game, width, height);
		width++;
		if (game->map->map_string[i] == '\n')
		{
			width = 0;
			height++;
		}
		i++;
	}
}

int	render_loop(t_game *game)
{
	draw_map(game);
	return (0);
}
