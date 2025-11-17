/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junchoi <junchoi@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 08:37:57 by junchoi           #+#    #+#             */
/*   Updated: 2025/11/14 08:49:27 by junchoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void    ft_lstdelone(t_list *lst, void(*del)(void *))
{
    if (!lst || !del)
        return ;
    del(lst->content);
    free(lst);
}