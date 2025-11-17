/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junchoi <junchoi@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 18:03:40 by junchoi           #+#    #+#             */
/*   Updated: 2025/11/17 18:09:41 by junchoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char *ft_strdup(const char *s1)
{
    char    *new;
    size_t  len;
    size_t  i;

    if (!s1)
        return (NULL);
    len = ft_strlen(s1);
    new = (char *)malloc(sizeof(char) * (len + 1));
    if (!new)
        return (NULL);
    i = 0;
    while (i < len)
    {
        new[i] = s1[i];
        i++;
    }
    new[i] = '\0';
    return (new);
}