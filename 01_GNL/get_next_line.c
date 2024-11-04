/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfranco <jfranco@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 13:57:40 by jfranco           #+#    #+#             */
/*   Updated: 2024/11/04 19:25:54 by jfranco          ###   ########.fr       */
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

static char	*read_new_line(int fd, char **stash)
{
	char		*temp;
	ssize_t		bytes;
	char		buffer[BUFFER_SIZE + 1];

	bytes = 1;
	while (bytes > 0)
	{
		bytes = read(fd, buffer, BUFFER_SIZE);
		if (bytes < 0)
			return (NULL);
		if (bytes == 0)
			break ;
		buffer[bytes] = '\0';
		if (*stash == NULL)
			*stash = ft_strdup("");
		temp = *stash;
		*stash = ft_strjoin(temp, buffer);
		free(temp);
		temp = NULL;
		if (*stash == NULL)
			return (NULL);
		if (ft_strchr(*stash, '\n') != NULL)
			break ;
	}
	return (*stash);
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

static char	*clear_stash(char **stash)
{
	char			*update_stash;
	size_t			len;
	unsigned int	j;

	len = ft_strlen(*stash);
	j = 0;
	while ((*stash)[j] != '\n' && (*stash)[j] != '\0')
		j++;
	if ((*stash)[j] == '\0')
	{
		free(*stash);
		*stash = NULL;
		return (NULL);
	}
	update_stash = ft_substr(*stash, j + 1, (len - j) + 1);
	free(*stash);
	*stash = NULL;
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
	stash = read_new_line(fd, &stash);
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
	stash = clear_stash(&stash);
	return (line);
}
