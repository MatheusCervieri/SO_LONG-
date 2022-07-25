/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvieira- <mvieira-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 21:30:01 by mvieira-          #+#    #+#             */
/*   Updated: 2022/07/26 00:30:47 by mvieira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdarg.h> 
# include <unistd.h>
# include <stdlib.h>
# include "libft.h"
# include <fcntl.h> 
# include <mlx.h>
# include <X11/keysym.h> 
# include  <X11/X.h> 

# define SPRITE_SIZE 64
# define MAP_CHARS "EP01C"

typedef struct s_window
{
	void	*win_ptr;
	int		width;
	int		height;
}				t_window;


typedef struct s_map
{
	char		*map_dir;
	char		*map_string;
	int			collectables;
	int			exits;
	int			players;
	void		*wall_p;
	void		*exit_p;
	void		*itens_p;
	void		*player_p;
	void		*floor_p;
	char		*wall_dir;
	char		*exit_dir;
	char		*itens_dir;
	char		*player_dir;
	char		*floor_dir; 
}				t_map;

typedef struct s_game
{
	t_map			*map;
	void			*mlx;
	t_window		*window;
	int				movements;
	int				itens_picked;
	int				used;
	char			*error_log;
	int				is_there_error;
}				t_game;

void			input_validation(int argc, char *map_dir, t_game *game);
void			error_close(char *error_message, t_game *game);
void			open_map_validation(t_game *game);
void			new_window(t_game *game);
void			init_structs_values(t_game *game);
void			initialization_structs(t_game *game);
void			free_game_vars(t_game *game);
void			handle_hooks(t_game *game);
void			load_wall_image(t_game *game);
void			exit_game(char *error_message, t_game *game);
void			handle_error(char *error_log, t_game *game);
int				render_loop(t_game *game);
void			move_right(t_game *game);
void			move_down(t_game *game);
void			move_left(t_game *game);
void			move_up(t_game *game);
void			move_item(t_game *game, int position, int movement);
void			finish_game(t_game *game);
int				is_game_finished(int itens_picked, int collectables);

#endif