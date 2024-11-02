/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfranco <jfranco@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 13:18:12 by jfranco           #+#    #+#             */
/*   Updated: 2024/11/02 17:25:12 by jfranco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
int out_char(int c)
{
	int	len;

	len = 0;
	len = write(1, &c, 1);
	return (len);
}

int out_str(char *s)
{
	int len;

	len = 0;
	while (s[len] != '\0')
	{
		write(1, &s[len], 1);
		len++;
	}
	return (len);
}

int out_digit(int n)
{
	int long	num;
	char		c;

	num = n;
	c = 'a';
	if (num < 0)
	{
		write(1, "-", 1);
		num = -num;
	}
	 if (num < 9)
	{
		c = num + '0';
		write(1, &c, 1);
	}
	else
	{
		out_digit(num / 10);
		c = (num % 10) + '0';
		write(1, &c, 1);
	}
	return (numlen(n));
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
		out_digit(va_arg(ap, int));
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

int main()
{
	/*ft_printf("12345 %d\n",(-1234567) + (890));*/
	printf("12345  %d\n",(-1234567) + (890));
}
