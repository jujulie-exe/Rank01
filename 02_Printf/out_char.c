/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   out_char.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfranco <jfranco@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 13:22:44 by jfranco           #+#    #+#             */
/*   Updated: 2024/11/08 17:51:39 by jfranco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	out_char(int c)
{
	return (write(1, &c, 1));
}

int	print_ad(void *ptr)
{
	int long	count;
	int long	res;
	uintptr_t	adress;

	count = 0;
	res = 0;
	if (ptr == NULL)
	{
		return (write(1, "(nil)", 5));
	}
	adress = (uintptr_t)ptr;
	count += write(1, "0x", 2);
	res += out_hex(adress);
	if (res == -1)
		return (-1);
	count += res;
	return (count);
}

int	error_write(va_list *ap)
{
	va_end(*ap);
	return (-1);
}
