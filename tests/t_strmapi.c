#include <stdio.h>
#include <ctype.h>
#include "libft.h"

static char to_upper_odd(unsigned int i, char c)
{
    if (i % 2 == 1 && c >= 'a' && c <= 'z')
        return (char)(c - 'a' + 'A');
    return c;
}

int main(void)
{
    const char *s = "abcdef";
    char *r = ft_strmapi(s, to_upper_odd);
    if (!r) return 1;
    printf("in : %s\nout: %s\n", s, r); // in: abcdef / out: aBcDeF
    free(r);
    return 0;
}
