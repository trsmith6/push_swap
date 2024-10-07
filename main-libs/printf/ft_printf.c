/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trsmith <trsmith@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 15:08:14 by trsmith           #+#    #+#             */
/*   Updated: 2024/03/27 14:56:08 by trsmith          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_print_ptr(void *ptr)
{
	unsigned long	ptr_value;
	int				count;

	ptr_value = (unsigned long)ptr;
	count = 0;
	if (ptr_value == 0)
	{
		if (write(1, "0x0", 3) == -1)
			return (-1);
		return (3);
	}
	if (write(1, "0x", 2) == -1)
		return (-1);
	count += 2;
	count += ft_print_numptr(ptr_value, 16);
	return (count);
}

static int	ft_print_format(char specifier, va_list args)
{
	if (specifier == 'c')
		return (ft_print_char(va_arg(args, int)));
	else if (specifier == 's')
		return (ft_print_str(va_arg(args, char *)));
	else if (specifier == 'd' || specifier == 'i')
		return (ft_print_num((long)va_arg(args, int), 10));
	else if (specifier == 'x')
		return (ft_print_num((long)va_arg(args, unsigned int), 16));
	else if (specifier == 'X')
		return (ft_print_numup((long)va_arg(args, unsigned int), 16));
	else if (specifier == 'u')
		return (ft_print_num((long)va_arg(args, unsigned int), 10));
	else if (specifier == 'p')
		return (ft_print_ptr(va_arg(args, void *)));
	else
		return (write(1, &specifier, 1));
}

int	ft_printf(const char *format, ...)
{
	va_list		ap;
	int			count ;
	int			temp;

	count = 0;
	va_start(ap, format);
	while (*format)
	{
		if (*format == '%')
		{
			temp = ft_print_format(*(++format), ap);
			if (temp == -1)
				return (-1);
			count += temp;
		}
		else
		{
			if (write(1, format, 1) == -1)
				return (-1);
			count += 1;
		}
		++format;
	}
	va_end(ap);
	return (count);
}

	// int main()
	// {
	// 	char *str = "This project was hard!";
	// 	int number = 12345;
	// 	unsigned int hex_number = 0xABCD;
	// 	void *ptr = (void *)0x12345678;

	//     // Testing all print specifiers
	// 	ft_printf("Testing print specifiers:\n");
	// 	ft_printf("%%c: %c\n", 'A');
	// 	ft_printf("%%s: %s\n", str);
	// 	ft_printf("%%d: %d\n", number);
	// 	ft_printf("%%i: %i\n", number);
	// 	ft_printf("%%x: %x\n", hex_number);
	// 	ft_printf("%%X: %X\n", hex_number);
	// 	ft_printf("%%u: %u\n", hex_number);
	// 	ft_printf("%%p: %p\n", ptr);

	// 	return (0);
	// }