/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfranco <jfranco@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 13:57:40 by jfranco           #+#    #+#             */
/*   Updated: 2024/10/25 14:44:47 by jfranco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*fill_join(char *b,char *s, int fd, int bytes)
{
	char		*temp;
	static char	*stash;

	if (b == NULL || s == NULL)
	{
		return (NULL);
	}
	bytes = read(fd, b, BUFFER_SIZE);
	if (bytes <= 0)
	{
		free(b);
		free(s);
		return (NULL);
	}
	b[bytes] = '\0';
	temp = s;
	stash = ft_strjoin(s, b);
	if (stash == NULL)
	return (NULL);
	free(temp);
	return (stash);
}

char *get_next_line(int fd)
{
	char		*buffer;
	static	char	*stash;
	char		*dst;
	char 		*ptr;
	size_t		len;
	
	ptr = NULL;
	len = 0;
	stash = NULL;
	
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
	{
		return (NULL);
	}
	if (stash == NULL)
	{
	stash = (char *)malloc(BUFFER_SIZE * sizeof(char));
	 if (stash == NULL)
		return(NULL);
	stash[0] = '\0';
	}

	while (1)
	{
		buffer = (char *)malloc(BUFFER_SIZE * sizeof(char));
		if (buffer == NULL)
		{
			free(stash);
			return (NULL);
		}
		stash = fill_join(buffer, stash, fd, 1);
		if (stash == NULL)
			return (NULL);
		ptr = ft_strchr(stash, '\n');
		if (ptr != NULL)
		{
			len = ft_strlen(stash) - ft_strlen(ptr) + 1;
			dst = (char *)malloc((len + 1) * sizeof(char));
			if (dst == NULL)
			{
				free(buffer);
				free(stash);
				return (NULL);
			}
			ft_strlcpy(dst, stash, len + 1);
			char *temp = stash;
			stash = strdup(ptr + 1);
			if (stash == NULL)
			{
				free(dst);
				free(buffer);
				free(temp);
				return (NULL);
			}
			free(buffer);
			free(temp);
			return (dst);
		}
	}
	free(buffer);
	free(stash);
	return (NULL);
}

/*int	main()
{
	int	f;

	f = open("stdio.txt", O_RDONLY);
	if (f < 0)
		return (-1);
	printf("%s", get_next_line(f));
}*/

