/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junchoi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 05:25:22 by junchoi           #+#    #+#             */
/*   Updated: 2025/11/09 05:25:23 by junchoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
#include "libft.h"

char *ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*m;
	size_t	i;
    size_t  s_len;

	if (!s)
		return (NULL);
    s_len = ft_strlen(s);
    if (start >= s_len)
    {
        m = (char *)malloc(1);
        if (!m)
            return (NULL);
        m[0] = '\0';
        return (m);
    }
    if (start + len > s_len)
        len = s_len - start;
	m = (char *)malloc(len + 1);
	if (!m)
		return (NULL);
	i = 0;
	while (i < len)
	{
		m[i] = s[start + i];
		i++;
	}
    m[i] = '\0';
	return (m);
}