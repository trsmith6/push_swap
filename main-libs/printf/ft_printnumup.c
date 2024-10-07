/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printnumup.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trsmith <trsmith@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 09:34:30 by trsmith           #+#    #+#             */
/*   Updated: 2024/03/27 10:09:49 by trsmith          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_numup(long n, int base)
{
	int		count;
	char	*symbols;
	int		temp;

	symbols = "0123456789ABCDEF";
	count = 0;
	if (n < 0)
	{
		if (write(1, "-", 1) == -1)
			return (-1);
		return (ft_print_numup(-n, base) + 1);
	}
	else if (n < base)
		return (ft_print_char(symbols[n]));
	else
	{
		count = ft_print_numup(n / base, base);
		if (count == -1)
			return (-1);
		temp = ft_print_numup(n % base, base);
		if (temp == -1)
			return (-1);
		return (count + temp);
	}
}
