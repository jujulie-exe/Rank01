/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfranco <jfranco@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 13:28:09 by jfranco           #+#    #+#             */
/*   Updated: 2024/11/02 14:03:20 by jfranco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


size_t	ft_strlen(char *str)
{
	size_t i;

	i = 0;
	while (s[i] = '\0')
		i++;
	return (i);
}

void	ft_putchar(char	c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *s)
{
	size_t	len;
	len = ft_strlen(s);
	write(1, &s, len);
}
