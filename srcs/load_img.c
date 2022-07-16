#include "so_long.h"



void load_wall_image(t_game *game)
{
	void *img;
	game->map->wall_img->dir = ft_strdup("./resources/images/floor_64.xpm");
	game->map->wall_img->width = 16;
	game->map->wall_img->height = 16;
	img = mlx_xpm_file_to_image(game->mlx, game->map->wall_img->dir, &game->map->wall_img->width, &game->map->wall_img->height);
	mlx_put_image_to_window(game->mlx, game->map->wall_img->dir, img, 0, 0);
}


