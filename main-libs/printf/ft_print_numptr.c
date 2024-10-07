/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printptr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trsmith <trsmith@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 14:18:31 by trsmith           #+#    #+#             */
/*   Updated: 2024/03/27 10:19:32 by trsmith          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_numptr(unsigned long n, unsigned long base)
{
	int		count;
	char	*symbols;

	symbols = "0123456789abcdef";
	count = 0;
	if (n < 0)
	{
		if (write(1, "-", 1) == -1)
			return (-1);
		return (ft_print_num(-n, base) + 1);
	}
	else if (n < base)
	{
		return (ft_print_char(symbols[n]));
	}
	else
	{
		count = ft_print_num(n / base, base);
		return (count + ft_print_num(n % base, base));
	}
}
