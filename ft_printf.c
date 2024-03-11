/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chayashi <caarlostol@student.42.rio>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 19:33:10 by chayashi          #+#    #+#             */
/*   Updated: 2024/03/11 17:03:51 by chayashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	type_letters(const char c, va_list args)
{
	int	len;

	len = 0;
	if (c == '%')
		len += ft_putchar('%');
	else if (c == 'c')
		len += ft_putchar(va_arg(args, int));
	else if (c == 's')
		len += ft_putstr(va_arg(args, char *));
	else if (c == 'p')
		len += ft_putptr(va_arg(args, unsigned long int));
	else if (c == 'd' || c == 'i')
		len += ft_putnbr(va_arg(args, int));
	else if (c == 'u')
		len += ft_putnbr_hexa(va_arg(args, unsigned int), 10, 0);
	else if (c == 'x')
		len += ft_putnbr_hexa(va_arg(args, unsigned int), 16, 0);
	else if (c == 'X')
		len += ft_putnbr_hexa(va_arg(args, unsigned int), 16, 1);
	return (len);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		len;

	va_start(args, format);
	len = 0;
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			len += type_letters(*format, args);
		}
		else
		{
			ft_putchar(*format);
			len++;
		}
		format++;
	}
	va_end (args);
	return (len);
}
