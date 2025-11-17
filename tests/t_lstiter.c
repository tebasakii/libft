#include <stdio.h>
#include <stdlib.h>
#include "libft.h"

// ✅ content에 적용할 함수
void    print_uppercase(void *content)
{
    char *str = (char *)content;
    int i = 0;

    while (str[i])
    {
        if (str[i] >= 'a' && str[i] <= 'z')
            str[i] -= 32; // 소문자 → 대문자 변환
        i++;
    }
    printf("%s\n", str);
}

int main(void)
{
    // ✅ 노드 생성
    t_list *n1 = ft_lstnew(ft_strdup("hello"));
    t_list *n2 = ft_lstnew(ft_strdup("world"));
    t_list *n3 = ft_lstnew(ft_strdup("libft"));

    // ✅ 연결
    ft_lstadd_back(&n1, n2);
    ft_lstadd_back(&n1, n3);

    // ✅ ft_lstiter 실행
    printf("=== Before ===\n");
    printf("%s\n", (char *)n1->content);
    printf("%s\n", (char *)n2->content);
    printf("%s\n", (char *)n3->content);

    printf("\n=== Applying ft_lstiter ===\n");
    ft_lstiter(n1, print_uppercase);

    printf("\n=== After ===\n");
    printf("%s\n", (char *)n1->content);
    printf("%s\n", (char *)n2->content);
    printf("%s\n", (char *)n3->content);

    // ✅ 메모리 해제
    ft_lstclear(&n1, free);
}
