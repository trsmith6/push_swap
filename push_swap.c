/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trsmith <trsmith@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 09:36:56 by trsmith           #+#    #+#             */
/*   Updated: 2024/09/23 12:10:14 by trsmith          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	t_stack	stack;
	int		errnum;

	if (argc == 1)
	{
		return (1);
	}
	errnum = full_check(argc, argv, &stack);
	if (errnum == 1)
	{
		ft_printf("error\n");
		return (1);
	}
	if (ft_is_sorted(&stack))
	{
		return (free(stack.stack_a), free(stack.stack_input), 0);
	}
	stack.stack_b = malloc(sizeof(int) * stack.len_a);
	stack.len_b = 0;
	bubble_sort(stack.stack_a, stack.len_a);
	plot_indacies(&stack);
	ft_memcpy(stack.stack_a, stack.stack_input, sizeof(int) * stack.len_start);
	sort_index(&stack);
	freeall(&stack);
	return (0);
}

int	sort_index(t_stack *stack)
{
	if (stack->len_a == 2)
	{
		swap_a(stack, "sa");
	}
	else if (stack->len_a == 3)
	{
		sort_three(stack);
	}
	else if (stack->len_a == 5)
	{
		sort_five(stack);
	}
	else
	{
		sort(stack);
	}
	return (0);
}

int	ft_lower_sort(int nb)
{
	if (nb <= 0)
	{
		return (0);
	}
	return (ft_lower_sort_search(nb, 0, nb));
}

int	ft_lower_sort_search(int b, int low, int high)
{
	int	mid;

	if (low == high)
	{
		return (low);
	}
	mid = (low + high) / 2;
	if (mid * mid >= b)
	{
		return (ft_lower_sort_search(b, low, mid));
	}
	return (ft_lower_sort_search(b, mid +1, high));
}

void	free_string_splitter(char **string_splitter)
{
	int	i;

	i = 0;
	while (string_splitter[i])
	{
		free(string_splitter[i]);
		i++;
	}
}
