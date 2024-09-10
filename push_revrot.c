/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_revrot.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trsmith <trsmith@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 09:24:28 by trsmith           #+#    #+#             */
/*   Updated: 2024/09/10 10:51:01 by trsmith          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_a(t_stack *stack, char *printer)
{
	int	tmp1;
	int	tmp2;

	if (stack->len_b < 1)
	{
		return ;
	}
	tmp1 = stack->stack_b[0];
	rotate_b(stack, "x");
	stack->len_b--;
	if (stack->len_a > 0)
	{
		tmp2 = stack->stack_a[stack->len_a - 1];
	}
	revrot_a(stack, "x");
	stack->stack_a[0] = tmp1;
	if (stack->len_a > 0)
	{
		stack->stack_a[stack->len_a] = tmp2;
	}
	stack->len_a++;
	ft_printer(printer);
}

void	push_b(t_stack *stack, char *printer)
{
	int	tmp1;
	int	tmp2;

	if (stack->len_a < 1)
	{
		return ;
	}
	tmp1 = stack->stack_a[0];
	rotate_a(stack, "x");
	stack->len_a--;
	if (stack->len_b > 0)
	{
		tmp2 = stack->stack_b[stack->len_b - 1];
	}
	revrot_b(stack, "x");
	stack->stack_b[0] = tmp1;
	if (stack->len_b > 0)
	{
		stack->stack_b[stack->len_b] = tmp2;
	}
	stack->len_b++;
	ft_printer(printer);
}

void	revrot_a(t_stack *stack, char *printer)
{
	int	tmp;
	int	i;
	
	if (stack->len_a < 2)
	{
		return ;
	}
	
}