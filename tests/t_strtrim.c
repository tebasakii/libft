#include <stdio.h>
#include <stdlib.h>
#include "libft.h"

int main(void)
{
	char *r;

	r = ft_strtrim("   Hello World!   ", " ");
	printf("'%s'\n", r);
	free(r);

	r = ft_strtrim("\n\t42 London\t\n", "\n\t");
	printf("'%s'\n", r);
	free(r);

	r = ft_strtrim("xxxxx", "x");
	printf("'%s'\n", r);
	free(r);

	r = ft_strtrim("", " x\t\n");
	printf("'%s'\n", r);
	free(r);

	r = ft_strtrim("no-trim", "xyz");
	printf("'%s'\n", r);
	free(r);

	return 0;
}
