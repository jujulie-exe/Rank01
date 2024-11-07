/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfranco <jfranco@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 13:18:12 by jfranco           #+#    #+#             */
/*   Updated: 2024/11/07 20:04:41 by jfranco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"
#include <stddef.h>
#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>

int out_str(char *s)
{
	int len;

	len = 0;
	if (s == NULL)
	{
		return write(1, "(nil)", 6);
	}
	while (s[len] != '\0')
	{
		out_char((int)s[len]);
		len++;
	}
	return (len);
}

int	check_format(char s, va_list ap)
{
	int	len;

	len = 0;
	if (s == 'c')
		len += out_char(va_arg(ap, int));
	else if (s == 's')
		len += out_str(va_arg(ap, char *));
	else if (s == 'd'|| s == 'i')
		len += out_digit(va_arg(ap, int));
	else if (s == 'x')
		len += out_hex(va_arg(ap, unsigned int));
	else if (s == 'X')
		len += 	out_hexdigit_upper_case(va_arg(ap, unsigned int));
	else if (s == 'u')
		len += out_digit_unsigned(va_arg(ap,unsigned int));
	else if (s == 'p')
		len += out_hex(va_arg(ap, unsigned int));
	else
		len += write(1, &s, 1);
	return (len);
}

int ft_printf(const char *frmt, ...)
{
	va_list ap;
	int		len;
	va_start(ap, frmt);

	len = 0;
	while (*frmt != '\0')
	{
		if (*frmt == '%')
			len += check_format(*(++frmt), ap);
		else
			len += write(1, frmt, 1);
		frmt++;
	}
	return (len);
}

