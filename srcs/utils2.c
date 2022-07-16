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

char	*ft_strjoin_free_s2(char const *s1, char const *s2)
{
	char	*newstr;
	char	*newstrfirstposition;
	char	*s1p;

	s1p = (char *)s1;
	newstr = malloc((ft_strlen(s1) + ft_strlen(s2)) * sizeof(char) + 1);
	if (!newstr)
		return (NULL);
	newstrfirstposition = newstr;
	while (*s1 != '\0')
	{
		*newstr = *s1;
		newstr++;
		s1++;
	}
	while (*s2 != '\0')
	{
		*newstr = *s2;
		newstr++;
		s2++;
	}
	*newstr = '\0';
	return (newstrfirstposition);
}