/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   out_char.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfranco <jfranco@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 13:22:44 by jfranco           #+#    #+#             */
/*   Updated: 2024/11/08 17:23:22 by jfranco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int out_char(int c)
{
	return (write(1, &c, 1));
}

int print_ad(void *ptr)
{
    int count;
    uintptr_t adress;
   
   count = 0;
  if (ptr == NULL)
  {
	  return (write(1, "0x0", 3));
  } 
   adress = (uintptr_t)ptr;
   count += write(1, "0x", 2);
   count += out_hex(adress);
   return (count);
}


