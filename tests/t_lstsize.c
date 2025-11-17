#include <stdio.h>
#include "libft.h"

int main(void)
{
    t_list *n1 = ft_lstnew("hello");
    t_list *n2 = ft_lstnew("world");
    t_list *n3 = ft_lstnew("42");

    n1->next = n2;
    n2->next = n3;

    printf("List size: %d\n", ft_lstsize(n1)); // 결과: 3
    printf("Empty list: %d\n", ft_lstsize(NULL)); // 결과: 0
}
