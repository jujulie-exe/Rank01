/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfranco <jfranco@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 11:46:31 by jfranco           #+#    #+#             */
/*   Updated: 2024/11/06 11:46:45 by jfranco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	len;
	size_t	y;

	len = 0;
	y = 0;
	while (src[len] != '\0')
	{
		len++;
	}
	if (dstsize > 0)
	{
		while (src[y] != '\0' && y < dstsize - 1)
		{
			dst[y] = src[y];
			y++;
		}
		dst[y] = '\0';
	}
	return (len);
}

char	*ft_strdup(const char *s1)
{
	size_t		i;
	size_t		len;
	char		*s2;

	i = 0;
	len = ft_strlen(s1);
	s2 = (char *)malloc((len + 1) *(sizeof(char)));
	if (s2 == NULL)
		return (NULL);
	while (s1[i] != '\0')
	{
		s2[i] = s1[i];
		i++;
	}
	s2[i] = '\0';
	return (s2);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*cat;
	size_t	l1;
	size_t	l2;
	size_t	total;
	size_t	j;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	l1 = ft_strlen(s1);
	l2 = ft_strlen(s2);
	total = l1 + l2 + 1;
	cat = (char *) malloc((total) * sizeof(char));
	if (cat == NULL)
		return (NULL);
	ft_strlcpy(cat, s1, l1 + 1);
	j = -1;
	while (s2[++j] && l1 + j < total)
		cat[l1 + j] = s2[j];
	cat[l1 + j] = '\0';
	return (cat);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	j;
	char	*dst;

	j = 0;
	if (s == NULL)
		return (NULL);
	i = ft_strlen(s);
	if (start >= i)
		return (ft_strdup(""));
	if (start < i)
		j = i - start;
	if (j > len)
		j = len;
	dst = (char *) malloc((j + 1) * sizeof(char));
	if (dst == NULL)
		return (NULL);
	ft_strlcpy(dst, s + start, j + 1);
	return (dst);
}
