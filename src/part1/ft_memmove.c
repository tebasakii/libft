#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void *ft_memmove(void *dst, const void *src, size_t n)
{
    unsigned char *d;
    const unsigned char *s;
    size_t         i;

    d = (unsigned char *)dst;
    s = (const unsigned char *)src;
    i = 0;

    if (!d && !s)
        return (NULL);
    if (n == 0 || d == s)
        return (dst);
    if (d < s || d >= s + n)
    {
        while (i < n)
        {
            d[i] = s[i];
            i++;
        }
        return (dst);
    }
    while (n--)
        d[n] = s[n];
    return (dst);
}

// int main(void)
// {
// 	char str1[20] = "abcdef";
// 	char str2[20] = "abcdef";

// 	// 테스트: 겹침 발생 (dest > src)
// 	printf("Before: %s\n", str1);
// 	memmove(str1 + 2, str1, 4);
// 	ft_memmove(str2 + 2, str2, 4);
// 	printf("After memmove : %s\n", str1);
// 	printf("After ft_memmove: %s\n\n", str2);

// 	// 테스트: 겹침 없음 (dest < src)
// 	char str3[20] = "abcdef";
// 	char str4[20] = "abcdef";
// 	memmove(str3, str3 + 2, 4);
// 	ft_memmove(str4, str4 + 2, 4);
// 	printf("memmove result   : %s\n", str3);
// 	printf("ft_memmove result: %s\n\n", str4);

// 	// 테스트: n == 0
// 	char str5[20] = "abcdef";
// 	char str6[20] = "abcdef";
// 	memmove(str5 + 2, str5, 0);
// 	ft_memmove(str6 + 2, str6, 0);
// 	printf("memmove (n==0)   : %s\n", str5);
// 	printf("ft_memmove (n==0): %s\n\n", str6);

// 	// 테스트: 같은 주소
// 	char str7[20] = "abcdef";
// 	char str8[20] = "abcdef";
// 	memmove(str7, str7, 6);
// 	ft_memmove(str8, str8, 6);
// 	printf("memmove same ptr : %s\n", str7);
// 	printf("ft_memmove same ptr: %s\n", str8);

// 	return 0;
// }