/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfranco <jfranco@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 14:15:43 by jfranco           #+#    #+#             */
/*   Updated: 2024/11/08 18:14:06 by jfranco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <unistd.h>
# include <limits.h>
# include <stdint.h>

int	ft_printf(const char *frmt, ...);
int	out_digit(int n);
int	out_char(int c);
int	out_hex(unsigned long long n);
int	out_digit_unsigned(unsigned int n);
int	out_hexdigit_upper_case(unsigned int n);
int	print_ad(void *ptr);

#endif
