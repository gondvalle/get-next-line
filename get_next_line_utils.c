/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdel-val <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 00:28:26 by gdel-val          #+#    #+#             */
/*   Updated: 2023/10/31 15:01:39 by gdel-val         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strchr(const char *s, int c)
{
	size_t	i;

	i = 0;
	if (!s)
		return (NULL);
	while (s[i])
	{
		if (s[i] == (char)c)
			return ((char *)&s[i]);
		i++;
	}
	if ((char)c == s[i])
		return ((char *)&s[i]);
	return (NULL);
}

char	*ft_strdup(const char *s)
{
	size_t	i;
	char	*src;

	i = 0;
	if (!s)
		return (ft_strdup(""));
	while (s[i] != '\0')
		i++;
	src = malloc(i + 1);
	if (src == NULL)
		return (NULL);
	i = 0;
	while (s[i] != '\0')
	{
		src[i] = s[i];
		i++;
	}
	src[i] = '\0';
	return (src);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	char	*scr;
	int		j;

	if (!s1)
		s1 = ft_strdup(s1);
	if (!s1)
		return (NULL);
	if (!s2)
		return (free((void *)s1), NULL);
	i = ft_strlen(s1) + ft_strlen(s2);
	scr = malloc(i + 1);
	if (scr == NULL)
		return (NULL);
	i = -1;
	j = 0;
	while (s1[++i] != '\0')
		scr[i] = s1[i];
	while (s2[j] != '\0')
		scr[i++] = s2[j++];
	scr[i] = '\0';
	return (scr);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*src;
	size_t	i;

	if (!s)
		return (NULL);
	if (start >= ft_strlen(s))
		return (ft_strdup(""));
	if (len > ft_strlen(s) - start)
		len = ft_strlen(s) - start;
	src = malloc(len + 1);
	if (src == NULL)
		return (NULL);
	i = 0;
	while (i < len)
	{
		src[i] = s[start + i];
		i++;
	}
	src[i] = '\0';
	return (src);
}
