#include <stdio.h>
#include <stdlib.h>
#include "libft.h"

int	main(void)
{
	char	*s1 = "Hello, ";
	char	*s2 = "World!";
	char	*joined;

	joined = ft_strjoin(s1, s2);
	if (!joined)
	{
		printf("malloc failed\n");
		return (1);
	}
	printf("Result: %s\n", joined);
	free(joined);
	return (0);
}
