/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_index.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trsmith <trsmith@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 11:13:29 by trsmith           #+#    #+#             */
/*   Updated: 2024/09/17 10:45:19 by trsmith          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_stack *stack)
{
	int	*arr;

	arr = stack->stack_a;
	if (ft_is_sorted(stack))
	{
		return ;
	}
	if (arr[0] < arr[1] && arr[2] > arr[0])
	{
		swap_a(stack, "sa");
		rotate_a(stack, "ra");
	}
	else if (arr[0] > arr[1] && arr[2] > arr[0])
		swap_a(stack, "sa");
	else if (arr[0] < arr[1] && arr[2] < arr[0])
		revrot_a(stack, "rra");
	else if (arr[0] > arr[1] && arr[2] < arr[1])
		rotate_a(stack, "ra");
	else if (arr[0] > arr[1] && arr[2] < arr[1])
	{
		swap_a(stack, "sa");
		revrot_a(stack, "rra");
	}
}

void	sort_five(t_stack *stack)
{
	int	pushed;

	pushed = 0;
	while (stack->len_start == 5 && pushed < 2)
	{
		if (stack->stack_a[0] == 0 || stack->stack_a[0] == 1)
		{
			push_b(stack, "pb");
			pushed++;
		}
		else
		{
			rotate_a(stack, "ra");
		}
	}
	sort_three(stack);
	if (stack->len_start == 5 && stack->stack_b[0] < stack->stack_b[1])
	{
		swap_b(stack, "sb");
	}
	push_a(stack, "pa");
	push_a(stack, "pa");
}

void	sort(t_stack *stack)
{
	int	count;
	int	cmax;
	int	val;

	count = 0;
	cmax = ft_lower_sort(stack->len_start) * 1.3;
	while (stack->len_a > 0)
	{
		val = stack->stack_a[0];
		if (val < count)
		{
			push_b(stack, "pb");
			rotate_b(stack, "rb");
			count++;
		}
		else if (val <= cmax + count)
		{
			push_b(stack, "pb");
			count++;
		}
		else
			rotate_a(stack, "ra");
	}
	ft_sort_back(stack);
}

void	ft_sort_back(t_stack *stack)
{
	while (stack->len_b > 0)
	{
		ft_highest_to_top(stack);
		push_a(stack, "pa");
	}
}

void	ft_highest_to_top(t_stack *stack)
{
	int	i;
	int	max;
	int	max_i;

	i = 0;
	max = stack->stack_b[0];
	max_i = 0;
	while (i < stack->len_b)
	{
		if (stack->stack_b[i] > max)
		{
			max = stack->stack_b[i];
			max_i = i;
		}
		i++;
	}
	if (max_i < stack->len_b / 2)
	{
		while (stack->stack_b[0] != max)
			rotate_b(stack, "rb");
	}
	else
		while (stack->stack_b[0] != max)
			revrot_b(stack, "rrb");
}
