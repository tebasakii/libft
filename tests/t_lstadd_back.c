#include <stdio.h>
#include "libft.h"

int main(void)
{
    // 노드 3개 생성
    t_list *n1 = ft_lstnew("A");
    t_list *n2 = ft_lstnew("B");
    t_list *n3 = ft_lstnew("C");

    // 리스트 연결
    n1->next = n2;
    n2->next = n3;

    // 새 노드 생성
    t_list *new = ft_lstnew("D");

    // 리스트 맨 뒤에 추가
    ft_lstadd_back(&n1, new);

    // 결과 확인
    t_list *tmp = n1;
    while (tmp)
    {
        printf("%s -> ", (char *)tmp->content);
        tmp = tmp->next;
    }
    printf("NULL\n");

    return (0);
}
