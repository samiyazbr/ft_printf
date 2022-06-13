/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szubair <szubair@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/12 11:58:37 by szubair           #+#    #+#             */
/*   Updated: 2022/06/12 12:04:46 by szubair          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdio.h>

int	ft_putchar(char c);
int	ft_putstr(char *s);
int	ft_printdec(int n);
int	ft_printpointer(void *p);
int	ft_printhexlow(unsigned int n);
int	ft_printhexup(unsigned int n);
int	ft_printunint(unsigned int nb);
int	ft_printf(const char *format, ...);
int	checkprint(va_list lst, char format, int num_chars);
#endif