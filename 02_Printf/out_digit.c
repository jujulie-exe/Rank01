/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   out_digit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfranco <jfranco@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 12:23:05 by jfranco           #+#    #+#             */
/*   Updated: 2024/11/08 18:09:13 by jfranco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	out_digit(int n)
{
	int		count;

	count = 0;
	if (n == INT_MIN)
		return (write(1, "-2147483648", 11));
	if (n == INT_MAX)
		return (write(1, "2147483647", 10));
	if (n < 0)
	{
		count += out_char('-');
		n = -n;
	}
	if (n < 10)
	{
		count += out_char(n + '0');
	}
	else
	{
		count += out_digit(n / 10);
		count += out_char(n % 10 + '0');
	}
	return (count);
}

int	out_hex(unsigned long long n)
{
	int long	count;
	char		*symb;

	symb = "0123456789abcdef";
	count = 0;
	if (n >= 16)
		count += out_hex(n / 16);
	if (write(1, &symb[n % 16], 1) == -1)
		return (-1);
	return (count + 1);
}

int	out_hexdigit_upper_case(unsigned int n)
{
	int long		count;
	char			*symb;

	symb = "0123456789ABCDEF";
	count = 0;
	if (n >= 16)
		count += out_hexdigit_upper_case(n / 16);
	if (write(1, &symb[n % 16], 1) == -1)
		return (-1);
	return (count + 1);
}

int	out_digit_unsigned(unsigned int n)
{
	int		count;
	int		res;

	count = 0;
	res = 0;
	if (n < 10)
	{
		count = out_char(n + '0');
		if (count == -1)
			return (-1);
	}
	else
	{
		count = out_digit_unsigned(n / 10);
		if (count == -1)
			return (-1);
		res = out_char(n % 10 + '0');
		if (count == -1)
			return (-1);
		count += res;
	}
	return (count);
}
