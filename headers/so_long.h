#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdarg.h> 
# include <unistd.h>
# include <stdlib.h>
# include "ft_printf.h"
#include <fcntl.h> //open, close 

# define BUFFER_SIZE 42

typedef struct s_map
{
	char		*map_dir;
}				t_map;

typedef struct s_game
{
	t_map			*map;
	int				used;
}				t_game;

void input_validation(int argc, char *map_dir, t_game *game);
void error_close(char *error_message, t_game *game); 
void open_map_validation(t_game *game);
void new_window(t_game *game);

//utils. 
int	ft_strncmp(const char *s1, const char *s2, size_t n); 
unsigned int	ft_strlen(const char *s); 

//gnl
char			*get_next_line(int fd);
int				is_there_nl(char *str);
char			*ft_strjoin_free(char const *s1, char const *s2);

#endif