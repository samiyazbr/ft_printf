/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printint.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samiyazubair <samiyazubair@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 11:26:04 by samiyazubai       #+#    #+#             */
/*   Updated: 2022/06/11 20:27:01 by samiyazubai      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ft_printf.h"

int	ft_printint(int d)
{
    int i;

    i = 0;
    while(d)
    {
        if (d == -2147483648)
        {
            write(1, "-2147483648", 11);
            return (0);
        }
        if (d < 0)
        {
            ft_putchar('-');
            d = -d;
        }
        if (d >= 0 && d <= 9)
            ft_printint(d + '0');
        if (d > 9)
        {
            ft_printint(d % 10);
            ft_printint(d / 10);
            i++;
        }
    }
    return (i);
}