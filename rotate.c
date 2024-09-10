/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trsmith <trsmith@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 12:50:34 by trsmith           #+#    #+#             */
/*   Updated: 2024/09/10 14:45:49 by trsmith          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_a(t_stack *stack, char *printer)
{
	int	tmp;
	int	i;

	if (stack->len_a < 2)
	{
		return ;
	}
	tmp = stack->stack_a[0];
	i = 0;
	while (i < stack->len_a - 1)
	{
		stack->stack_a[i] = stack->stack_a[i + 1];
		i++;
	}
	stack->stack_a[i] = tmp;
	ft_printer(printer);
}

void	rotate_b(t_stack *stack, char *printer)
{
	int	tmp;
	int	i;

	if (stack->len_b < 2)
	{
		return ;
	}
	tmp = stack->stack_b[0];
	i = 0;
	while (i < stack->len_b - 1)
	{
		stack->stack_b[i] = stack->stack_b[i + 1];
		i++;
	}
	stack->stack_b[i] = tmp;
	ft_printer(printer);
}

void	rotate_both(t_stack *stack, char *printer)
{
	int	tmp1;
	int	tmp2;
	int	i;

	if (stack->len_b < 2 || stack->len_a < 2)
	{
		return ;
	}
	tmp1 = stack->stack_a[0];
	tmp2 = stack->stack_b[0];
	i = 0;
	while (i < stack->len_b - 1)
	{
		stack->stack_b[i] = stack->stack_b[i + 1];
		i++;
	}
	stack->stack_b[i] = tmp2;
	i = 0;
	while (i < stack->len_a - 1)
	{
		stack->stack_a[i] = stack->stack_a[i + 1];
		i++;
	}
	stack->stack_a[i] = tmp1;
	ft_printer(printer);
}
