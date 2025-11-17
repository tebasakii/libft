#include <stdio.h>
#include "libft.h"

int main(void)
{
    t_list *n1 = ft_lstnew("hello");
    t_list *n2 = ft_lstnew("world");
    t_list *n3 = ft_lstnew("42");

    n1->next = n2;
    n2->next = n3;

    t_list *last = ft_lstlast(n1);
    printf("Last node content: %s\n", (char *)last->content); // 출력: 42
}
