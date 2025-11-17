#include <stdio.h>
#include "libft.h"

int main(void)
{
    t_list *n1 = ft_lstnew("hello");
    t_list *n2 = ft_lstnew((int[]){42});
    t_list *n3 = ft_lstnew(NULL);

    printf("[n1] content=%s, next=%p\n", (char *)n1->content, (void *)n1->next);
    printf("[n2] content=%d, next=%p\n", *(int *)n2->content, (void *)n2->next);
    printf("[n3] content=%p, next=%p\n", n3->content, (void *)n3->next);

    return 0;
}
