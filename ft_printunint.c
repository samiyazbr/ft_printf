/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printunint.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szubair <szubair@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 18:17:28 by szubair           #+#    #+#             */
/*   Updated: 2022/06/12 12:06:24 by szubair          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printunint(unsigned int nb)
{
	int	len;

	len = 0;
	if (nb > 9)
	{
		len += ft_printunint(nb / 10);
		len += ft_printunint(nb % 10);
	}
	else
		len = ft_putchar(nb + '0');
	return (len);
}
