/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvieira- <mvieira-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 03:14:37 by mvieira-          #+#    #+#             */
/*   Updated: 2022/07/25 20:20:12 by mvieira-         ###   ########.fr       */
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
	if (game->map->wall_p != NULL)
		mlx_destroy_image(game->mlx, game->map->wall_p);
	free_not_null((void *)game->map->wall_dir);
	if (game->map->floor_p != NULL)
		mlx_destroy_image(game->mlx, game->map->floor_p);
	free_not_null((void *)game->map->floor_dir);
	if (game->map->exit_p != NULL)
		mlx_destroy_image(game->mlx, game->map->exit_p);
	free_not_null((void *)game->map->exit_dir);
	if (game->map->itens_p != NULL)
		mlx_destroy_image(game->mlx, game->map->itens_p);
	free_not_null((void *)game->map->itens_dir);
	if (game->map->player_p != NULL)
		mlx_destroy_image(game->mlx, game->map->player_p);
	free_not_null((void *)game->map->player_dir);
}

void	finish_game(t_game *game)
{
	ft_printf("You made %i movements \n", game->movements);
	exit_game(NULL, game);
}

void	exit_game(char *error_message, t_game *game)
{
	if (error_message)
		ft_printf("Error\n%s\n", error_message);
	free_window_vars(game);
	if (game->window->win_ptr != NULL)
		mlx_destroy_window(game->mlx, game->window->win_ptr);
	if (game->mlx != NULL)
	{
		mlx_destroy_display(game->mlx);
		free(game->mlx);
	}
	free_game_vars(game);
	exit(0);
}
