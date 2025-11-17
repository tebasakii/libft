#include <stdio.h>
#include <stdlib.h>
#include "libft.h"

int	main(void)
{
	t_list *head = ft_lstnew("world");
	t_list *new = ft_lstnew("hello");

	ft_lstadd_front(&head, new);

	printf("%s -> %s\n", (char *)head->content, (char *)head->next->content);
	return (0);
}
