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

int	checkprint(va_list lst, char format, int num_chars)
{
	if (format == 'c')
		num_chars += ft_putchar((char)va_arg(lst, int));
	if (format == 's')
		num_chars += ft_putstr(va_arg(lst, char *));
	if (format == 'd' || format == 'i')
		num_chars += ft_printdec(va_arg(lst, int));
	if (format == 'x')
		num_chars += ft_printhexlow(va_arg(lst, unsigned int));
	if (format == 'X')
		num_chars += ft_printhexup(va_arg(lst, unsigned int));
	if (format == '%')
		num_chars += ft_putchar('%');
	if (format == 'p')
	{
		ft_putstr("0x");
		num_chars += ft_printpointer(va_arg(lst, void *)) + 2;
	}
	if (format == 'u')
		num_chars += ft_printunint(va_arg(lst, unsigned int));
	return (num_chars);
}

int	ft_printf(const char *format, ...)
{
	va_list	lst;
	int		i;
	int		num_chars;

	va_start(lst, format);
	num_chars = 0;
	i = 0;
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			num_chars = checkprint(lst, format[i + 1], num_chars);
			i++;
		}
		else
			num_chars += ft_putchar(format[i]);
		i++;
	}
	va_end(lst);
	return (num_chars);
}
// int main()
//{
//     int n;
//     //n = ft_printf(" %c ",'0');
//     printf("%s", NULL);
// }