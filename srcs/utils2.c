#include "so_long.h"

void	*ft_memset(void *s, int c, size_t n)
{
	char	*a;
	size_t	i;

	a = (char *) s;
	i = 0;
	while (i < n)
	{
		a[i] = (char) c;
		i++;
	}	
	return (s);
}