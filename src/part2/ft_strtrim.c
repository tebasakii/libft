/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junchoi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 04:07:49 by junchoi           #+#    #+#             */
/*   Updated: 2025/11/11 04:07:51 by junchoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
#include "libft.h"

char *ft_strtrim(char const *s1, char const *set)
{
	char * mal;
	size_t					start;
	size_t					end;
	size_t					i;
	if (!s1 || !set)
		return (NULL);
	start = 0;
	while (s1[start] && ft_strchr(set, s1[start]))
		start++;
	end = ft_strlen(s1);
	while (end > start && s1[end -1] && ft_strchr(set, s1[end - 1]))
		end--;
    
    mal = (char *)malloc(end - start + 1);
	if (!mal)
		return (NULL);
	i = 0;
	while (s1[start + i] && i < end - start)
	{
		mal[i] = s1[start + i];
		i++;
	}
    mal[i] = '\0';
	return (mal);
}