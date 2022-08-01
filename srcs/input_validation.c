/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_validation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvieira- <mvieira-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 18:30:29 by mvieira-          #+#    #+#             */
/*   Updated: 2022/07/25 17:38:27 by mvieira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	input_validation(int argc, char *map_dir, t_game *game)
{
	if (argc != 2)
	{
		exit_game("Invalid number of arguments", game);
	}
	else if (ft_strncmp(map_dir + ft_strlen(map_dir) - 4, ".ber", 4) != 0)
	{
		exit_game("Map format invalid. It is not .ber", game);
	}
	else
	{
		game->map->map_dir = ft_strdup(map_dir);
	}
}
