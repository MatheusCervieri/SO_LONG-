#include "so_long.h"

void draw_map(t_game *game)
{
	int i;
	int height;
	int width;

	height = 0;
	width = 0; 
	i = 0;
	while(game->map->map_string[i] != '\0')
	{
		if(game->map->map_string[i] == '1')
		{
			mlx_put_image_to_window(game->mlx, game->window->win_ptr, game->map->wall_img->img, width * SPRITE_SIZE, height * SPRITE_SIZE);	
		}
		width++;
		if(game->map->map_string[i] == '\n')
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
	return(0);
}
