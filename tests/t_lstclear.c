#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "libft.h"

// del 함수: content가 동적 메모리이므로 free
static void del_str(void *p)
{
    free(p);
}

int main(void)
{
    // 동적 content로 노드 3개 생성
    t_list *head = NULL;
    t_list *n1 = ft_lstnew(strdup("A"));
    t_list *n2 = ft_lstnew(strdup("B"));
    t_list *n3 = ft_lstnew(strdup("C"));

    // 연결
    n1->next = n2;
    n2->next = n3;
    head = n1;

    // clear 전 출력
    printf("before clear: %s -> %s -> %s\n",
        (char*)n1->content, (char*)n2->content, (char*)n3->content);

    // 전체 삭제
    ft_lstclear(&head, del_str);

    // 결과 확인: head는 NULL이어야 함
    if (head == NULL)
        printf("after clear: head is NULL (ok)\n");
    else
        printf("after clear: head is NOT NULL (bug)\n");

    return 0;
}
