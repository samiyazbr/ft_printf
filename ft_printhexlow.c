/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printhexlow.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szubair <szubair@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 18:14:32 by szubair           #+#    #+#             */
/*   Updated: 2022/06/12 12:05:12 by szubair          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printhexlow(unsigned int n)
{
	int	mod;
	int	len;

	mod = 0;
	len = 0;
	if (n >= 16)
	{
		len += ft_printhexlow(n / 16);
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
