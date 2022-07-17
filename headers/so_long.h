#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdarg.h> 
# include <unistd.h>
# include <stdlib.h>
# include "ft_printf.h"
# include <fcntl.h> //open, close 
# include <mlx.h>
# include <X11/keysym.h> //hooks.
#include  <X11/X.h> //Keypress, release macros. 

# define BUFFER_SIZE 42
# define MAP_CHARS "01CEP"
# define SPRITE_SIZE 64

typedef struct s_window
{
	void	*win_ptr;
	int		width;
	int		height;
}				t_window;

typedef struct s_img
{
	void	*img;
	char	*dir;
	int		width;
	int		height;
}				t_img;


typedef struct s_map
{
	char		*map_dir;
	char		*map_string; 
	int			collectables;
	int			exits;
	int			players;
	t_img		*wall_img; //1
	t_img		*floor_img; //0
	t_img		*exit_img;
	t_img		*itens_img; 
	t_img		*player_img; 	
}				t_map;

typedef struct s_game
{
	t_map			*map;
	void			*mlx; 
	t_window		*window; 
	int				used;
	char			*error_log; 
	int				is_there_error;
}				t_game;

void input_validation(int argc, char *map_dir, t_game *game);
void error_close(char *error_message, t_game *game); 
void open_map_validation(t_game *game);
void new_window(t_game *game);
void init_structs_values(t_game *game);
void initialization_structs(t_game *game);
void free_game_vars(t_game *game);
void handle_hooks(t_game *game);
void load_wall_image(t_game *game);
void exit_game(t_game *game);
void handle_error(char *error_log, t_game *game);
int	render_loop(t_game *game);
void move_right(t_game *game);
//utils. 
int	ft_strncmp(const char *s1, const char *s2, size_t n); 
unsigned int	ft_strlen(const char *s); 
char	*ft_strrchr(const char *s, int c);
void	*ft_calloc(size_t nelem, size_t elsize);
void	*ft_memset(void *s, int c, size_t n); 

//gnl
char			*get_next_line(int fd);
int				is_there_nl(char *str);
char			*ft_strjoin_free(char const *s1, char const *s2);

#endif