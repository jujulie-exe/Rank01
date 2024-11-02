/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfranco <jfranco@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 13:18:12 by jfranco           #+#    #+#             */
/*   Updated: 2024/11/02 14:02:05 by jfranco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int ft_printf(const char *is, ...)
{
	va_list ap;
	size_t	i;
	size_t	len;
	va_start(ap, is);

	i = 0;
	len = ft_strlen(is);
	while (i < len)
	{
		if (is[i] == '%')
			i++;
		if (is[i] == 'c')
			ft_putchar(va_arg(ap, const char));
		if
	}
}
