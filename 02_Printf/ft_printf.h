/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfranco <jfranco@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 14:15:43 by jfranco           #+#    #+#             */
/*   Updated: 2024/11/07 17:07:44 by jfranco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef FT_PRINTF_H
#define FT_PRINTF_H

#include <stdio.h>
#include <unistd.h>
#include <limits.h>

int ft_printf(const char *frmt, ...);
int out_digit(int n);
int	out_char(int c);
int out_hex(unsigned int n);
int out_digit_unsigned(unsigned int n);


#endif
