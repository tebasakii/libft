#include <stdio.h>
#include <stdlib.h>

int ft_atoi(const char *str);

int main(void)
{
    char *tests[] = {
        "42", "   42", "   -42", "+42", "4193 with words",
        "words 4193", "-91283472332", "--42", "\t\n  2147483647", "\t\n -2147483648"
    };

    for (size_t i = 0; i < sizeof(tests) / sizeof(tests[0]); i++)
    {
        printf("ORIGINAL: %d | MY: %d | \"%s\"\n",
            atoi(tests[i]), ft_atoi(tests[i]), tests[i]);
    }
}
