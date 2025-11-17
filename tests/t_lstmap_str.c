// tests/t_lstmap_str.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "libft.h"

// f: 문자열을 strdup하여 " (mapped)"를 붙여 새 문자열로 반환
static void *dup_with_suffix(void *p)
{
    const char *s = (const char *)p;
    const char *suffix = " (mapped)";
    size_t len = strlen(s) + strlen(suffix) + 1;
    char *out = (char *)malloc(len);
    if (!out) return NULL;
    strcpy(out, s);
    strcat(out, suffix);
    return out;
}

static void del_str(void *p)
{
    free(p);
}

static t_list *make_str_list(const char **arr, size_t n)
{
    t_list *head = NULL;
    for (size_t i = 0; i < n; i++)
    {
        char *copy = strdup(arr[i]);
        if (!copy) { ft_lstclear(&head, del_str); return NULL; }
        t_list *node = ft_lstnew(copy);
        if (!node) { free(copy); ft_lstclear(&head, del_str); return NULL; }
        ft_lstadd_back(&head, node);
    }
    return head;
}

int main(void)
{
    const char *words[] = {"alpha", "beta", "gamma"};
    t_list *orig = make_str_list(words, 3);
    if (!orig) return 1;

    t_list *mapped = ft_lstmap(orig, dup_with_suffix, del_str);
    if (!mapped) { ft_lstclear(&orig, del_str); return 1; }

    // 출력 예: alpha (mapped) / beta (mapped) / gamma (mapped)
    for (t_list *p = mapped; p; p = p->next)
        printf("%s\n", (char *)p->content);

    ft_lstclear(&orig, del_str);
    ft_lstclear(&mapped, del_str);
    return 0;
}
