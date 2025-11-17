#include <stdio.h>
#include "libft.h"

void del_content(void *content)
{
    free(content);
}

int main(void)
{
    // 동적 메모리로 content 생성 (free 테스트용)
    char *str = malloc(6);
    if (!str)
        return (1);
    str[0] = 'H'; str[1] = 'e'; str[2] = 'l'; str[3] = 'l'; str[4] = 'o'; str[5] = '\0';

    t_list *node = ft_lstnew(str);

    printf("Before delete: %s\n", (char *)node->content);

    ft_lstdelone(node, del_content);

    printf("After delete: node deleted\n");
    return (0);
}
