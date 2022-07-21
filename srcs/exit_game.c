/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvieira- <mvieira-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 03:14:37 by mvieira-          #+#    #+#             */
/*   Updated: 2022/07/21 03:17:58 by mvieira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_not_null(void *ptr)
{
	if (ptr != NULL)
	{
		free(ptr);
		ptr = NULL;
	}
}

void	free_game_vars(t_game *game)
{
	free_not_null((void *)game->map->map_dir);
	free_not_null((void *)game->map->map_string);
	free_not_null((void *)game->map);
	free_not_null((void *)game->window);
}

void	free_window_vars(t_game *game)
{
	if (game->map->wall_img != NULL)
		mlx_destroy_image(game->mlx, game->map->wall_img->img);
	free_not_null((void *)game->map->wall_img->dir);
	free_not_null((void *)game->map->wall_img);
	if (game->map->floor_img != NULL)
		mlx_destroy_image(game->mlx, game->map->floor_img->img);
	free_not_null((void *)game->map->floor_img->dir);
	free_not_null((void *)game->map->floor_img);
	if (game->map->exit_img != NULL)
		mlx_destroy_image(game->mlx, game->map->exit_img->img);
	free_not_null((void *)game->map->exit_img->dir);
	free_not_null((void *)game->map->exit_img);
	if (game->map->itens_img != NULL)
		mlx_destroy_image(game->mlx, game->map->itens_img->img);
	free_not_null((void *)game->map->itens_img->dir);
	free_not_null((void *)game->map->itens_img);
	if (game->map->player_img != NULL)
		mlx_destroy_image(game->mlx, game->map->player_img->img);
	free_not_null((void *)game->map->player_img->dir);
	free_not_null((void *)game->map->player_img);
}

void	exit_game(t_game *game)
{
	free_window_vars(game);
	mlx_destroy_window(game->mlx, game->window->win_ptr);
	mlx_destroy_display(game->mlx);
	free(game->mlx);
	free_game_vars(game);
	exit(0);
}

void	error_close(char *error_message, t_game *game)
{
	ft_printf("Error\n%s\n", error_message);
	free_game_vars(game);
	exit(0);
}
