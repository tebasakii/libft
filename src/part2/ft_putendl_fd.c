/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junchoi <junchoi@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 04:21:56 by junchoi           #+#    #+#             */
/*   Updated: 2025/11/12 04:42:09 by junchoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void    ft_putendl_fd(char *s, int fd)
{
    size_t  i;
    if (!s)
        return ;
    i = 0;
    while (s[i])
    {
        write(fd, &s[i++],1);
    }
    write(fd, "\n", 1);
}