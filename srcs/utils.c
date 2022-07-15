#include "so_long.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned int	i;

	if (n == 0)
		return (0);
	i = 0;
	while ((s1[i] != '\0' || s2[i] != '\0') && i < n)
	{
		if (s1[i] != s2[i])
			return ((unsigned char)(s1[i]) - (unsigned char)(s2[i]));
		i++;
	}
	return (0);
}

char	*ft_strjoin_free(char const *s1, char const *s2)
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
	free(s1p);
	return (newstrfirstposition);
}

int	is_there_nl(char *str)
{
	int	i;

	if (!str)
		return (-1);
	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

char	*ft_strrchr(const char *s, int c)
{
	const char	*initial_value;
	int			i;

	initial_value = s;
	i = ft_strlen(s);
	s = (s + i);
	while (s != initial_value && (unsigned char)c != *s)
	{
		s--;
	}
	if ((unsigned char)c == *s)
	{
		return ((char *) s);
	}
	return (0);
}

void	*ft_calloc(size_t nelem, size_t elsize)
{
	void	*allocated_memory;
	int		over_handling;

	over_handling = nelem * elsize;
	if (nelem != 0 && over_handling / nelem != elsize)
		return (NULL);
	allocated_memory = (void *) malloc (nelem * elsize);
	if (allocated_memory == NULL)
		return (NULL);
	ft_memset(allocated_memory, 0, nelem * elsize);
	return (allocated_memory);
}