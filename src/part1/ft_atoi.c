/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junchoi <junchoi@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 17:51:56 by junchoi           #+#    #+#             */
/*   Updated: 2025/11/17 17:59:06 by junchoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int ft_atoi(const char *str)
{
    int     sign;
    long    result;

    sign = 1;
    result = 0;

    while (*str == ' ' || *str == '\t' || *str == '\n'
        || *str == '\v' || *str == '\f' || *str == '\r')
        str++;

    if (*str == '-' || *str == '+')
    {
        if (*str == '-')
            sign = -1;
        str++;
    }

    while (*str >= '0' && *str <= '9')
    {
        result = result * 10 + (*str - '0');
        str++;
    }

    return (sign * result);
}
