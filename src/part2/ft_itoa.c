/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junchoi <junchoi@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/16 15:13:36 by junchoi           #+#    #+#             */
/*   Updated: 2025/11/17 17:40:02 by junchoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static size_t  get_digit_len(long n)
{
    size_t  i;

    i = 0;
    while (n >= 10)
    {
        n /= 10;
        i++;
    }
    return (i + 1);
}

char	*ft_itoa(int n)
{
    long    num;
    char    *result;
    size_t  len;

    num = (long)n;
    if (num < 0)
        num = -num;
    len = get_digit_len(num);
    if (n < 0)
        len += 1;
    result = (char *)malloc(sizeof(char) * (len + 1));
    if (!result)
        return (NULL);
    result[len] = '\0';
    if (num == 0)
    {
        result[0] = '0';
        return (result);
    }
    while (num > 0)
    {
        result[--len] = (num % 10 + '0');
        num /= 10;
    }
    if (n < 0)
        result[0] = '-';
    return (result);
}