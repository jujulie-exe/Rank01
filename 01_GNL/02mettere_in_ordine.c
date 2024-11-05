/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl-old.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llebugle <lucas.lebugle@student.s19.be>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 13:57:40 by jfranco           #+#    #+#             */
/*   Updated: 2024/11/05 19:53:28 by jfranco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char static	*ft_strchr(const char *s, int c)
{
	size_t	i;

	i = 0;
	if ((char)c == '\0')
	{
		while (s[i] != '\0')
		{
			i++;
		}
		return ((char *)&s[i]);
	}
	while (s[i] != '\0')
	{
		if (s[i] == (char)c)
		{
			return ((char *)&s[i]);
		}
		i++;
	}
	return (NULL);
}

static char	*read_new_line(int fd, char *stash)
{
	char		*temp;
	ssize_t		bytes;
	char		buffer[BUFFER_SIZE + 1];

	bytes = 1;
	while (bytes > 0 && (!stash || !ft_strchr(stash, '\n')))
	{
		//if (ft_strlen(stash) < bytes)
		bytes = read(fd, buffer, BUFFER_SIZE);
		if (bytes < 0)
			return (NULL);
		if (bytes == 0)
			break ;
		buffer[bytes] = '\0';
		if (stash == NULL)
			stash = ft_strdup("");
		temp = stash;
		stash = ft_strjoin(temp, buffer);
		free(temp);
		temp = NULL;
		if (stash == NULL)
			return (NULL);
		// if (ft_strchr(stash, '\n') != NULL)
		// 	break ;
	}
	return (stash);
}

static char	*fill_new_line(char *stash)
{
	size_t	i;
	char	*line;

	i = 0;
	while (stash[i] != '\n' && stash[i] != '\0')
	{
		i++;
	}
	if (stash[i] == '\0')
	{
		line = (char *)malloc((i + 1) * sizeof(char));
		if (line == NULL)
			return (NULL);
		ft_strlcpy(line, stash, i + 1);
	}
	else
	{
		line = malloc((i + 2) * sizeof(char));
		if (line == NULL)
			return (NULL);
		ft_strlcpy(line, stash, i + 2);
	}
	return (line);
}

static char	*clear_stash(char *stash)
{
	char			*update_stash;
	size_t			len;
	unsigned int	j;

	len = ft_strlen(stash);
	j = 0;
	while (stash[j] != '\n' && stash[j] != '\0')
		j++;
	if (stash[j] == '\0')
	{
		free(stash);
		stash = NULL;
		return (NULL);
	}
	update_stash = ft_substr(stash, j + 1, (len - j) + 1);
	free(stash);
	stash = NULL;
	if (update_stash == NULL || ft_strlen(update_stash) == 0)
	{
		free(update_stash);
		update_stash = NULL;
		return (NULL);
	}
	return (update_stash);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*stash;

	if (BUFFER_SIZE <= 0 || fd < 0 || read(fd, 0, 0) < 0)
	{
		if (!stash)
			return(NULL);
		free(stash);
		stash = NULL;
		return (NULL);
	}
	stash = read_new_line(fd, stash);
	if (stash == NULL || ft_strlen(stash) == 0)
	{
		free(stash);
		stash = NULL;
		return (NULL);
	}
	line = fill_new_line(stash);
	if (line == NULL)
	{
		free(stash);
		stash = NULL;
		return (NULL);
	}
	stash = clear_stash(stash);
	return (line);
}






/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llebugle <lucas.lebugle@student.s19.be>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 15:08:38 by jfranco           #+#    #+#             */
/*   Updated: 2024/11/05 19:38:10 by llebugle         ###   ########.fr       */
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

// char	*ft_strjoin(char const *s1, char const *s2)
// {
// 	char	*new;
// 	size_t	len;
// 	size_t	i;
// 	size_t	j;

// 	if (!s1 && !s2)
// 		return (NULL);
// 	if (!s1 && s2)
// 		len = ft_strlen(s2);
// 	else
// 		len = ft_strlen(s1) + ft_strlen(s2);
// 	new = malloc(sizeof(char) * len + 1);
// 	if (!new)
// 		return (NULL);
// 	i = -1;
// 	while (s1[++i] && i < len)
// 		new[i] = s1[i];
// 	j = -1;
// 	while (s2[++j] && i + j < len)
// 		new[i + j] = s2[j];
// 	new[i + j] = '\0';
// 	return (new);
// }

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
	//ft_strlcat(cat, s2, total);
	return (cat);
}

// char	*ft_substr(char const *s, unsigned int start, size_t len)
// {
// 	char	*str;
// 	size_t	i;

// 	if (start >= ft_strlen(s))
// 		return (ft_calloc(1, sizeof(char)));
// 	if (ft_strlen(s + start) < len)
// 		len = ft_strlen(s + start);
// 	str = malloc(sizeof(char) * (len + 1));
// 	if (!str)
// 		return (NULL);
// 	i = 0;
// 	while (i < len)
// 		str[i++] = s[start++];
// 	str[len] = '\0';
// 	return (str);
// }

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

