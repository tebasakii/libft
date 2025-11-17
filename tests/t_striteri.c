#include <stdio.h>
#include "libft.h"

void    to_upper_even(unsigned int i, char *c)
{
    if (i % 2 == 0 && *c >= 'a' && *c <= 'z')
        *c = *c - 'a' + 'A';
}

int main(void)
{
    char    str[] = "libft is fun";

    printf("before: %s\n", str);
    ft_striteri(str, to_upper_even);
    printf("after : %s\n", str);
    return (0);
}
