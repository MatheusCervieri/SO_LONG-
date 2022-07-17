#include "so_long.h"

int	close_game(t_game *game)
{
	exit_game(game);
	return(0);
}

int	keypress(int keycode, t_game *game)
{
	if (keycode == XK_Escape || keycode == XK_q)
		close_game(game);
	if (keycode == XK_Right || keycode == XK_d)
		move_right(game);
	if (keycode == XK_Left || keycode == XK_a)
		move_left(game);
	if (keycode == XK_Up || keycode == XK_w)
		move_up(game);
	if (keycode == XK_Down || keycode == XK_s)
		move_down(game);	
	return (0);
}

void	handle_hooks(t_game *game)
{
	mlx_hook(game->window->win_ptr, DestroyNotify, NoEventMask, &close_game, game); 
	mlx_hook(game->window->win_ptr,	KeyPress, KeyPressMask, &keypress, game);
	mlx_loop_hook(game->mlx, &render_loop, game);
}
