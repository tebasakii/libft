#include <stdio.h>
#include <stddef.h>
#include <string.h>

int ft_memcmp(const void *s1, const void *s2, size_t n)
{
    const unsigned char *ss1;
    const unsigned char *ss2;
    
    ss1 = (const unsigned char *)s1;
    ss2 = (const unsigned char *)s2;
    while(n--)
    {
        if (*ss1++ != *ss2++)
            return (*(ss1 - 1) - *(ss2 - 1));
    }
    return (0);
}