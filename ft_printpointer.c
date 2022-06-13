/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printpointer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szubair <szubair@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 18:17:33 by szubair           #+#    #+#             */
/*   Updated: 2022/06/12 12:05:38 by szubair          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printpointer(void *p)
{
	int				mod;
	int				len;
	unsigned long	n;

	mod = 0;
	len = 0;
	n = (unsigned long)p;
	if (n >= 16)
	{
		len += ft_printpointer((void *)(n / 16));
	}
	mod = n % 16;
	if (mod >= 10)
	{
		len += ft_putchar(mod - 10 + 'a');
	}
	else if (mod < 10)
	{
		len += ft_putchar(mod + '0');
	}
	return (len);
}
