/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samiyazubair <samiyazubair@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 11:26:21 by samiyazubai       #+#    #+#             */
/*   Updated: 2022/06/11 19:08:39 by samiyazubai      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_putstr(char *s)
{
    int i;
    
    i = 0;
    while (s[i] != '\0')
    {
        write(1,&s[i],1);
        i++;
    }
    return (i);
}
