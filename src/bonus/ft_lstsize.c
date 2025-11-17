/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junchoi <junchoi@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 06:12:37 by junchoi           #+#    #+#             */
/*   Updated: 2025/11/16 15:12:21 by junchoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int ft_lstsize(t_list *lst)
{
    int count;
    
    if (!lst)
        return (0);
    count = 0;
    while (lst)
    {
        lst = lst->next;
        count++;
    }
    return (count);
}