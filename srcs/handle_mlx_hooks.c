#include "so_long.h"

typedef struct s_data
{
	void	*mlx_ptr;
	void	*win_ptr;
	int		unused;
}	t_data;

int	handle_no_event(void *data)
{
	/* This function needs to exist, but it is useless for the moment */
	if(data)
		return(0);
	return (0);
}


int	handle_keypress(int keysym, t_game *game)
{
	if (keysym == XK_Escape)
		exit_game(game);
	ft_printf("Keypress: %d\n", keysym);
	return (0);
}

int	handle_keyrelease(int keysym, void *data)
{
	ft_printf("Keyrelease: %d\n", keysym);
	if(data)
		return(0);
	return (0);
}

void handle_mlx_key_hooks(t_game *game)
{
	t_data data;

	data.mlx_ptr = game->mlx;
	data.win_ptr = game->window->win_ptr;
	mlx_loop_hook(data.mlx_ptr, &handle_no_event, &data);
	mlx_hook(data.win_ptr, KeyPress, KeyPressMask, &handle_keypress, &game); /* ADDED */
	mlx_hook(data.win_ptr, KeyRelease, KeyReleaseMask, &handle_keyrelease, &data); /* CHANGED */
}