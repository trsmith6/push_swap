/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trsmith <trsmith@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 11:00:10 by trsmith           #+#    #+#             */
/*   Updated: 2024/09/13 11:26:58 by trsmith          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_a(t_stack *stack, char *printer)
{
	int	tmp;

	if (stack->len_a < 2)
	{
		return ;
	}
	tmp = stack->stack_a[0];
	stack->stack_a[0] = stack->stack_a[1];
	stack->stack_a[1] = tmp;
	ft_printer(printer);
}

void	swap_b(t_stack *stack, char *printer)
{
	int	tmp;

	if (stack->len_a < 2)
	{
		return ;
	}
	tmp = stack->stack_b[0];
	stack->stack_b[0] = stack->stack_a[1];
	stack->stack_a[1] = tmp;
	ft_printer(printer);
}

void	swap_both(t_stack *stack, char *printer)
{
	int	tmp1;
	int	tmp2;

	if (stack->len_a < 2 || stack->len_b < 2)
	{
		return ;
	}
	tmp1 = stack->stack_a[0];
	tmp2 = stack->stack_b[0];
	stack->stack_a[0] = stack->stack_a[1];
	stack->stack_b[0] = stack->stack_b[1];
	stack->stack_a[1] = tmp1;
	stack->stack_b[1] = tmp2;
	ft_printer(printer);
}
