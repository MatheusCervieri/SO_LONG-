#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdarg.h> 
# include <unistd.h>
# include <stdlib.h>
# include "ft_printf.h"


typedef struct s_map
{
	char		*map_dir;
}				t_map;

typedef struct s_game
{
	t_map			*map;
}				t_game;

void input_validation(int argc, char *map_dir, t_game *game);
void error_close(char *error_message, t_game *game); 

//utils. 
int	ft_strncmp(const char *s1, const char *s2, size_t n); 
unsigned int	ft_strlen(const char *s); 

#endif