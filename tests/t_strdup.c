#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char	*ft_strdup(const char *s1);

int main(void)
{
	char *s = "Hello 42!";
	char *mine = ft_strdup(s);
	char *real = strdup(s);

	printf("original: %s\n", s);
	printf("ft      : %s\n", mine);
	printf("real    : %s\n", real);

	free(mine);
	free(real);
	return 0;
}
