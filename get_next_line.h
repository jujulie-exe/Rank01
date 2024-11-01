/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfranco <jfranco@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 09:00:02 by jfranco           #+#    #+#             */
/*   Updated: 2024/11/01 17:14:23 by jfranco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# ifndef BUFFER_SIZE
# define BUFFER_SIZE 42
# endif
# include <stdio.h>
# include <string.h>
# include  <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <stddef.h>

char    *ft_strdup(const char *s1);
size_t  ft_strlen(const char *s);
char    *ft_strjoin(char const *s1, char const *s2);
char	*get_next_line(int fd);
size_t  ft_strlcpy(char *dst, const char *src, size_t dstsize);
char	*ft_substr(char const *s, unsigned int start, size_t len);

#endif
