/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfranco <jfranco@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 13:57:40 by jfranco           #+#    #+#             */
/*   Updated: 2024/10/24 19:11:11 by jfranco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include  <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

char *get_next_line(int fd)
{
	char	buffer[1024];
	char	*stash;
	char	*dst;
	char 	*ptr;
	int		newline;
	ssize_t	bytes;
	
	newline = 0;
	bytes = 1;
	while (newline == 0 && bytes > 0)
	{
		bytes = read(fd, buffer, sizeof(buffer));
			if (bytes == -1)
				return (NULL);
			if (bytes == 0)
				return (strdup(stash));
		buffer[bytes] = '\0';
		stash = ft_strjoin(stash, buffer);
		ptr = ft_strchr(stash, '\n');
		if (ptr != NULL)
		{
			dst = (char *)malloc((ptr + 1) * sizeof(char));
			ft_strlcpy(dst, stash, ptr + 1);
			newline = 1
		{
	return (dst);
}

int	main()
{
	int	f;

	f = open("stdio.txt", O_RDONLY);
	if (f < 0)
		return (-1);
	printf("%s", get_next_line(f));
}

