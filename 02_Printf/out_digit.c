/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   out_digit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfranco <jfranco@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 12:23:05 by jfranco           #+#    #+#             */
/*   Updated: 2024/11/04 21:12:47 by jfranco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int out_digit(int n)
{
	int long	nbr;
	char		c;

	nbr = n;
	c = 'a';
	if (nbr < 0)
	{
		write(1, "-", 1);
		nbr = -nbr;
	}
	if (nbr < 10)
	{
		c = nbr + '0';
		write(1, &c, 1);
	}
	if (nbr >= 10)
	{
		out_digit(nbr / 10);
		c = ((nbr % 10) + '0');
		write(1, &c, 1);
	}
	return(1);
}
