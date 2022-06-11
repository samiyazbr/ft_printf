/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samiyazubair <samiyazubair@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 11:22:38 by samiyazubai       #+#    #+#             */
/*   Updated: 2022/06/11 20:15:05 by samiyazubai      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_printf(const char *format, ...)
{
    va_list lst;
    int i;
    int num_chars;

    va_start(lst, format);
    num_chars = 0;
    i = 0;
    while(format[i] != '\0')
    {
        if(format[i] == '%' && format[i + 1] == 'c')
        {
         num_chars += ft_putchar((char)va_arg(lst, int));
         i++;
        }
        else if(format[i] == '%' && format[i + 1] == 's')
        {
            num_chars += ft_putstr(va_arg(lst, char *));
            i++;
        }
        else if(format[i] == '%' && format[i + 1] == 'd')
            num_chars += ft_printint(va_arg(lst, int));
        else
           ft_putchar(format[i]);
        i++;
    }
    va_end(lst);
    return (num_chars);
}
int main()
{
    ft_printf("%c %s %d ",'0',"sakjiubdfie",1080);
    
}