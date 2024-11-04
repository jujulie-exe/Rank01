/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfranco <jfranco@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 13:18:12 by jfranco           #+#    #+#             */
/*   Updated: 2024/11/04 20:07:49 by jfranco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"
#include <stddef.h>
#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>
int	numlen(int n)
{
	int	len;

	len = 0;
	if (n <= 0)
		len++;
	while (n / 10)
	{
		len++;
	}
	return (len);
}

int out_str(char *s)
{
	int len;

	len = 0;
	if (s == NULL)
	{
		return write(1, "(null)", 6);
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
	else if (s == 'd')
		len += out_digit(va_arg(ap, long long));
	else if (s == 'x')
		len += out_digit(va_arg(ap, unsigned int));
	/*else if (s == 'p')
		len += out_ptr(va_arg(ap, void *));
	else if (s == 'i')
		len += out*/
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

/*int main()
{
	ft_printf("12345 %d\n",(-1234567) + (890));
	printf("12345  %d\n",(-1234567) + (890));
}*/
