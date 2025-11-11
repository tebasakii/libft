#include <string.h>
#include <stdio.h>
void *memchr(const void *s, int c, size_t n)
{
    size_t                 i;
    const unsigned char *src;

    i = 0;
    src = (const unsigned char *)s;

    while (n--)
    {
        if (src[i] == (unsigned char)c)
            return (void *)&src[i];
        i++;
    }
    return (NULL);
}

int main(void)
{
	char arr[] = { 'a', 'b', 'c', 'd', 'e' };
	char *res = memchr(arr, 'c', 5);
	printf("%s\n", res);
}
