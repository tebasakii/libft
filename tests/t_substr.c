#include <stdio.h>
#include <stdlib.h>
#include "libft.h"

static void	show(char *label, char *p)
{
	if (!p)
		printf("%s -> (null)\n", label);
	else
	{
		printf("%s -> \"%s\"\n", label, p);
		free(p);
	}
}

int	main(void)
{
	const char *s = "Hello, 42London!";

	show("case1 start=7,len=8",  ft_substr(s, 7, 8));     // "42London"
	show("case2 start=0,len=5",  ft_substr(s, 0, 5));     // "Hello"
	show("case3 start=20,len=5", ft_substr(s, 20, 5));    // ""
	show("case4 start=3,len=50", ft_substr(s, 3, 50));    // "lo, 42London!"
	show("case5 start=0,len=0",  ft_substr(s, 0, 0));     // ""

	// NULL 입력 방어
	show("case6 s=NULL",         ft_substr(NULL, 0, 5));  // (null)

	return 0;
}
