/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junchoi <junchoi@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 20:56:50 by junchoi           #+#    #+#             */
/*   Updated: 2025/11/17 20:57:05 by junchoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int  count_words(const char *s, char c)
{
    int i = 0;
    int count = 0;

    while (s[i])
    {
        while (s[i] && s[i] == c)
            i++;
        if (s[i])
        {
            count++;
            while (s[i] && s[i] != c)
                i++;
        }
    }
    return (count);
}

static char *malloc_word(const char *s, int start, int end)
{
    char *word;
    int   i = 0;

    word = malloc((end - start + 1) * sizeof(char));
    if (!word)
        return (NULL);
    while (start < end)
        word[i++] = s[start++];
    word[i] = '\0';
    return (word);
}

static void free_split(char **split, int filled)
{
    while (filled--)
        free(split[filled]);
    free(split);
}

char **ft_split(char const *s, char c)
{
    char    **split;
    int     words;
    int     i = 0;
    int     w = 0;
    int     start;

    if (!s)
        return (NULL);

    words = count_words(s, c);
    split = malloc((words + 1) * sizeof(char *));
    if (!split)
        return (NULL);

    while (s[i])
    {
        while (s[i] && s[i] == c)
            i++;
        if (!s[i])
            break;

        start = i;
        while (s[i] && s[i] != c)
            i++;

        split[w] = malloc_word(s, start, i);
        if (!split[w])
            return (free_split(split, w), NULL);
        w++;
    }
    split[w] = NULL;
    return (split);
}
