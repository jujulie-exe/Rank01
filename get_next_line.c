/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfranco <jfranco@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 13:57:40 by jfranco           #+#    #+#             */
/*   Updated: 2024/10/29 12:04:40 by jfranco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*read_new_line(char *buffer, int fd, char **stash)
{
	char		*temp;
	ssize_t		bytes;

	bytes = 1;
	while (bytes > 0)
	{
		bytes = read(fd, buffer, BUFFER_SIZE);
		if (bytes < 0)
			return (NULL);
		if (bytes == 0)
			break;
		buffer[bytes] = '\0';
		if(*stash == NULL)
			*stash = ft_strdup("");
		temp = *stash;
		*stash = ft_strjoin(temp, buffer);
		free(temp);
		temp = NULL;
		if (*stash == NULL)
			return (NULL);
		if (ft_strchr(*stash, '\n') != NULL)
			break;
	}
	return (*stash);
}

static char	*fill_new_line(char *stash)
{
	size_t	i;
	char	*line;

	i = 0;
	while(stash[i] != '\n' && stash[i] != '\0')
	{
		i++;
	}
	line =(char *)malloc((i + 2) * sizeof(char));
	if (line == NULL)
		return (NULL);
	ft_strlcpy(line, stash, i + 2);
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
	if (stash[j] == '\0' && j > 0)
	{
		free(stash);
		return (NULL);
	}
	update_stash = ft_substr(stash, j + 1, (len - j) + 1);
	free(stash);
	if (update_stash == NULL)
		return (NULL);
	return (update_stash);
}

static char	*free_and_null(char **stash)
{
	free(*stash);
	*stash = NULL;
	return (NULL);
}

char *get_next_line(int fd)
{
	char		*buffer;
	char 		*line;
	static char	*stash;

	buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (BUFFER_SIZE <= 0 || fd < 0 || read(fd, 0, 0) < 0 )
	{
		free_and_null(&buffer);
		return (free_and_null(&stash));
	}
	if (buffer == NULL)
		return (NULL);
	stash = read_new_line(buffer, fd, &stash);
	free(buffer);
	if (stash == NULL || ft_strlen(stash) == 0)
		return (free_and_null(&stash));
	line = fill_new_line(stash);
	if (line == NULL)
	{
		return (free_and_null(&stash));
	}
	stash = clear_stash(stash);
	return (line);
}
