/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trsmith <trsmith@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 15:27:11 by trsmith           #+#    #+#             */
/*   Updated: 2024/03/27 10:19:07 by trsmith          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

int		ft_print_char(int c);
int		ft_print_str(char *str);
int		ft_print_num(long n, int base);
int		ft_print_numup(long n, int base);
int		ft_print_numptr(unsigned long n, unsigned long base);
int		ft_printf(const char *format, ...);

#endif
