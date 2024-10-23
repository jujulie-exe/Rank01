/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfranco <jfranco@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 13:57:40 by jfranco           #+#    #+#             */
/*   Updated: 2024/10/23 15:48:28 by jfranco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char *get_next_line(int fd)
{
	static char		*stash;
	char			buffer[42];
	static size_t	i;
	ssize_t			size;
	int				fd;

	if (fd == -1)
		return;
	size = read(fd, buffer, sizeof(buffer));
	stash = (char *)malloc(size * sizeof(char));
	if (stash == NULL)
		return (NULL);
	strlcpy(stash, buffer, size);
	while (i <= size - 1)
	{
		if (stash[i] == '\n')
		{
			strlcpy(dst, stash, size - i);
			break;
		}
		else if (i == size - 1)
		{

		}
		i++;
	}
	return (stash);
}

int	main()
{
	int	fd;

	fd = open(stdio.txt, 0_RDONLY);
	if (fd == -1)
		return (-1);
	printf("%s", get_next_line(fd));
}

