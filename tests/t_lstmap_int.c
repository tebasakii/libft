// tests/t_lstmap_int.c
#include <stdio.h>
#include <stdlib.h>
#include "libft.h"

// f: int 값을 2배로 복제해 새 메모리에 담아 반환
static void *dup_int_times2(void *p)
{
    int *n = (int *)p;
    int *q = (int *)malloc(sizeof(int));
    if (!q) return NULL;
    *q = (*n) * 2;
    return q;
}

// del: 일반 free
static void del_int(void *p)
{
    free(p);
}

// 편의: int 배열로 리스트 만들기
static t_list *make_int_list(const int *arr, size_t n)
{
    t_list *head = NULL;
    for (size_t i = 0; i < n; i++)
    {
        int *box = (int *)malloc(sizeof(int));
        if (!box) { ft_lstclear(&head, del_int); return NULL; }
        *box = arr[i];
        t_list *node = ft_lstnew(box);
        if (!node) { free(box); ft_lstclear(&head, del_int); return NULL; }
        ft_lstadd_back(&head, node);
    }
    return head;
}

int main(void)
{
    int vals[] = {1, 3, 5};
    t_list *orig = make_int_list(vals, 3);
    if (!orig) return 1;

    t_list *mapped = ft_lstmap(orig, dup_int_times2, del_int);
    if (!mapped) { ft_lstclear(&orig, del_int); return 1; }

    // 출력 확인: 2 6 10
    for (t_list *p = mapped; p; p = p->next)
        printf("%d ", *(int *)p->content);
    printf("\n");

    ft_lstclear(&orig, del_int);
    ft_lstclear(&mapped, del_int);
    return 0;
}
