/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szubair <szubair@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 13:42:20 by szubair           #+#    #+#             */
/*   Updated: 2022/06/12 12:04:05 by szubair          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int checkprint(va_list lst, char format, int num_chars)
{
    if (format == 'c')
        num_chars += ft_putchar((char)va_arg(lst, int));
    // The 'c' format specifier: Print a character.

    if (format == 's')
        num_chars += ft_putstr(va_arg(lst, char *));
    // The 's' format specifier: Print a string.

    if (format == 'd' || format == 'i')
        num_chars += ft_printdec(va_arg(lst, int));
    // The 'd' or 'i' format specifier: Print a decimal (integer) number.

    if (format == 'x')
        num_chars += ft_printhexlow(va_arg(lst, unsigned int));
    // The 'x' format specifier: Print a hexadecimal number in lowercase.

    if (format == 'X')
        num_chars += ft_printhexup(va_arg(lst, unsigned int));
    // The 'X' format specifier: Print a hexadecimal number in uppercase.

    if (format == '%')
        num_chars += ft_putchar('%');
    // The '%' format specifier: Print a percent sign.

    if (format == 'p')
    {
        ft_putstr("0x");
        num_chars += ft_printpointer(va_arg(lst, void *)) + 2;
    }
    // The 'p' format specifier: Print a pointer in hexadecimal form.

    if (format == 'u')
        num_chars += ft_printunint(va_arg(lst, unsigned int));
    // The 'u' format specifier: Print an unsigned decimal (integer) number.

    return (num_chars);
}

int ft_printf(const char *format, ...)
{
    va_list lst;      // Declare a va_list variable to hold the arguments.
    int i;            // Declare an integer variable for iteration.
    int num_chars;    // Declare an integer variable to count the characters printed.

    va_start(lst, format);  // Initialize the va_list with the variable arguments.
    num_chars = 0;          // Initialize the character count to zero.
    i = 0;                  // Initialize the iterator to zero.

    while (format[i] != '\0')
    {
        if (format[i] == '%')
        {
            num_chars = checkprint(lst, format[i + 1], num_chars);  // Call checkprint to handle format specifiers.
            i++;  // Increment i to skip the format specifier character.
        }
        else
            num_chars += ft_putchar(format[i]);  // Print regular characters using ft_putchar.
        
        i++;  // Move to the next character in the format string.
    }

    va_end(lst);  // Clean up the va_list.

    return (num_chars);  // Return the total number of characters printed.
}

// int main()
//{
//     int n;
//     //n = ft_printf(" %c ",'0');
//     printf("%s", NULL);
// }