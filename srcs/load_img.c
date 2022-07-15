#include "so_long.h"

void load_image(t_game *game , t_img *imagem)
{
	imagem->img = mlx_xpm_file_to_image(game->mlx, imagem->dir, &imagem->width, &imagem->height);
	mlx_put_image_to_window(game->mlx, game->window->win_ptr, imagem->img , 50, 50);
}

void load_wall_image(t_game *game)
{
	game->map->wall_img->dir = ft_strdup("./resources/images/floor_64.xpm");
	game->map->wall_img->width = 0;
	game->map->wall_img->height = 0;
	load_image(game, game->map->wall_img);
}


