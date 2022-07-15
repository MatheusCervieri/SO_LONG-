#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdarg.h> 
# include <unistd.h>
# include <stdlib.h>
# include "ft_printf.h"
# include <fcntl.h> //open, close 

# define BUFFER_SIZE 42
# define MAP_CHARS "01CEP"

typedef struct s_map
{
	char		*map_dir;
	int			collectables;
	int			exits;
	int			players;
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
void init_structs_values(t_game *game);
void initialization_structs(t_game *game);

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