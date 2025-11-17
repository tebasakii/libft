/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junchoi <junchoi@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 08:50:42 by junchoi           #+#    #+#             */
/*   Updated: 2025/11/14 10:36:57 by junchoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void    ft_lstclear(t_list **lst, void (*del)(void *))
{
    t_list  *next;

    if (!lst || !*lst || !del)
        return ;
    while (*lst)
    {
        next = (*lst)->next;
        del((*lst)->content);
        free(*lst);
        *lst = next;
    }
}