/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trsmith <trsmith@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 13:37:20 by trsmith           #+#    #+#             */
/*   Updated: 2024/09/13 11:42:54 by trsmith          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_if_num(char *str)
{
	int	i;

	i = 0;
	if ((str[i] == '-' || str[i] == '+') && str [i + 1] != '\0')
		i++;
	while (str[i] && ((ft_isdigit(str[i]) || str[i] == ' ') || str[i] == '-'
			|| str[i] == '+'))
		i++;
	if (str[i] != '\0' && (ft_isdigit(str[i])
			|| str[i] == ' ' || str[i] == '-'
			|| str[i] == '+'))
		return (1);
	while (str[i])
		if ((str[i] >= 'a' && str[i] <= 'z')
			|| (str[i] >= 'A' && str[i] <= 'Z'))
			return (1);
	return (0);
}

int	ft_dupe_check(int *nbr, int size)
{
	int	i;
	int	j;

	i = 0;
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			if (nbr[i] == nbr[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	ft_check_zero(char *nbr)
{
	int	i;

	i = 0;
	if (nbr[i] == '+' || nbr[i] == '-')
	{
		i++;
	}
	while (nbr[i] != '\0')
	{
		return (0);
	}
	return (1);
}

int	check_if_sorted(t_stack *stack)
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
