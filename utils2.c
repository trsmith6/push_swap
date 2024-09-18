/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trsmith <trsmith@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 14:09:02 by trsmith           #+#    #+#             */
/*   Updated: 2024/09/18 10:37:10 by trsmith          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	full_check(int argc, char *argv[], t_stack *stack)
{
	int		i;
	char	*str;

	i = 0;
	stack->len_a = 0;
	str = arg_processor(argc, argv);
	if (!str)
		return (1);
	if (check_if_num(str) || ft_check_zero(str))
		return (free(str), 1);
	if (str_processor(argc, argv, stack))
		return (free(str), free(stack->stack_a), 1);
	if (ft_dupe_check(stack->stack_a, ft_wordcount(str, ' ')))
		return (free(str), free(stack->stack_a), 1);
	while (i < ft_wordcount(str, ' '))
	{
		i++;
		stack->len_a++;
	}
	stack->len_start = stack->len_a;
	copy_to_initstack(stack);
	free(str);
	return (0);
}

char	*arg_processor(int argc, char *argv[])
{
	int		length;
	char	*str;
	int		i;

	length = len_of_args(argc, argv);
	str = (char *)malloc(length + 1);
	if (!str)
	{
		return (NULL);
	}
	str[0] = '\0';
	i = 0;
	while (++i < argc)
	{
		ft_strlcat(str, argv[i], length + 1);
		if (i < argc - 1)
		{
			ft_strlcat(str, " ", length + 1);
		}
	}
	return (str);
}

int	str_processor(int argc, char *argv[], t_stack *stack)
{
	char	*string;
	int		i;
	char	**string_splitter;

	i = 0;
	string = arg_processor(argc, argv);
	if (!string)
		return (1);
	stack->stack_a = malloc((ft_wordcount(string, ' ')) * sizeof(int));
	if (!stack->stack_a)
		return (free(string), 1);
	string_splitter = ft_split(string, ' ');
	while (i < ft_wordcount(string, ' '))
	{
		if (ft_atol(string_splitter[i]) > 2147483647
			|| ft_atol(string_splitter[i]) < -2147483648)
			return (free(string), free_string_splitter(string_splitter),
				free(string_splitter), 1);
		stack->stack_a[i] = ft_atoi(string_splitter[i]);
		i++;
	}
	ft_bzero(string, ft_strlen(string));
	another_free_thing(string, string_splitter);
	return (0);
}

void	copy_to_initstack(t_stack *stack)
{
	int	i;

	i = 0;
	stack->stack_input = malloc(sizeof(int) * stack->len_a);
	if (!stack->stack_input)
		return ;
	while (i < stack->len_a)
	{
		stack->stack_input[i] = stack->stack_a[i];
		i++;
	}
}

int	len_of_args(int argc, char *argv[])
{
	int	tot_len;
	int	i;

	tot_len = 0;
	i = 1;
	while (i < argc)
	{
		tot_len += ft_strlen(argv[i]);
		i++;
	}
	tot_len += argc;
	return (tot_len);
}
