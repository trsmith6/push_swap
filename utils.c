/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trsmith <trsmith@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 09:27:52 by trsmith           #+#    #+#             */
/*   Updated: 2024/09/10 10:27:15 by trsmith          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_printer(char *printer)
{
	if (strcmp(printer, "x"))
	{
		ft_printf("%s\n", printer);
	}
	return ;
}

int	ft_is_sorted(t_stack *stack)
{
	int	i;

	i = 0;
	while (i < stack->len_a - 1)
	{
		if (stack->stack_a[i] > stack->stack_a[i + 1])
		{
			return (0);
		}
		i++;
	}
	return (1);
}

void	bubble_sort(int *array, int len)
{
	int	i;
	int	j;
	int	tmp;
	int	swapped;

	i = 0;
	swapped = 1;
	while (swapped)
	{
		swapped = 0;
		j = 0;
		while (j < len - i - 1)
		{
			if (array[j] > array[j + 1])
			{
				tmp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = tmp;
				swapped = 1;
			}
			j++;
		}
		i++;
	}
}

void	plot_indacies(t_stack *stack)
{
	int	i;
	int	j;

	i = 0;
	while (i < stack->len_a)
	{
		j = 0;
		while (j < stack->len_a)
		{
			if (stack->stack_input[i] == stack->stack_a[j])
			{
				stack->stack_input[i] = j;
				break ;
			}
			j++;
		}
		i++;
	}
}

void	freeall(t_stack *stack)
{
	free(stack->stack_a);
	free(stack->stack_b);
	free(stack->stack_input);
}
