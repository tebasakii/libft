#include <stdio.h>
#include <string.h>
#include "libft.h"     // 프로토타입 확인용

int main(void)
{
	char s1[] = "Hello";
	char s2[] = "World";
	printf("std=%d ft=%d\n", memcmp(s1,s2,5), ft_memcmp(s1,s2,5));
	return 0;
}
