/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfranco <jfranco@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 13:57:40 by jfranco           #+#    #+#             */
/*   Updated: 2024/10/23 16:13:16 by jfranco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include  <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

char *get_next_line(int fd)
{
}

int	main()
{
	int	f;

	f = open("stdio.txt", O_RDONLY);
	if (f > 0)
		return (-1);
	printf("%s", get_next_line(f));
}

