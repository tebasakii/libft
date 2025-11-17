/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junchoi <junchoi@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 20:57:59 by junchoi           #+#    #+#             */
/*   Updated: 2025/11/17 20:58:20 by junchoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void *calloc(size_t count, size_t size)
{
    void *ptr = malloc(count * size);
    unsigned char *p;

    p = (unsigned char *)ptr;
    size_t i;
    i = 0;
    while(i < count * size)
    {
        p[i++] = 0;
    }

    free(ptr);
    return (ptr);
}