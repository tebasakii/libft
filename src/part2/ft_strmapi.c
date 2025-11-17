/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junchoi <junchoi@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/15 10:20:18 by junchoi           #+#    #+#             */
/*   Updated: 2025/11/16 12:09:02 by junchoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char    *ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
    char    *copy;
    size_t  len;
    size_t  i;

    if (!s || !f)
        return (NULL);
    len = ft_strlen(s);
    copy = (char *)malloc(sizeof(char) * (len + 1));
    if (!copy)
        return (NULL);
    i = 0;
    while (s[i])
    {
        copy[i] = f(i, s[i]);
        i++;
    }
    copy[i] = '\0';
    return (copy);
}