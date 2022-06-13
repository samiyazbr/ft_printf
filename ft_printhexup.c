/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printhexup.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szubair <szubair@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 13:46:39 by szubair           #+#    #+#             */
/*   Updated: 2022/06/12 12:05:22 by szubair          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printhexup(unsigned int n)
{
	int	mod;
	int	len;

	mod = 0;
	len = 0;
	if (n >= 16)
	{
		len += ft_printhexup(n / 16);
	}
	mod = n % 16;
	if (mod >= 10)
	{
		len += ft_putchar(mod - 10 + 'A');
	}
	else if (mod < 10)
	{
		len += ft_putchar(mod + '0');
	}
	return (len);
}
