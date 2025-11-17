#include <stdio.h>
#include "libft.h"

int	main(void)
{
	int		arr[] = {0, 1, -1, 42, -42, 2147483647, -2147483648};
	size_t	i;
	char	*res;

	i = 0;
	while (i < sizeof(arr) / sizeof(arr[0]))
	{
		res = ft_itoa(arr[i]);
		printf("%d -> \"%s\"\n", arr[i], res);
		free(res);
		i++;
	}
	return (0);
}
