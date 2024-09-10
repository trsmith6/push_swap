/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trsmith <trsmith@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 09:17:32 by trsmith           #+#    #+#             */
/*   Updated: 2024/09/10 10:37:45 by trsmith          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

		//includes//
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
//include your libs

		//structs//
typedef struct s_stack
{
	int	*stack_a;
	int	*stack_b;
	int	*stack_input;
	int	errornum;
	int	len_a;
	int	len_b;
	int	len_start;
}			t_stack;

		//push_swap.c//
int		main(int argc, char *argv[]);
int		sort_index(t_stack *stack);

		//push_revrot.c//
void	push_a(t_stack *stack, char *printer);
void	push_b(t_stack *stack, char *printer);
void	revrot_a(t_stack *stack, char *printer);
void	revrot_b(t_stack *stack, char *printer);
void	revrot_both(t_stack *stack, char *printer);

		//utils.c//
void	ft_printer(char *printer);
int		ft_is_sorted(t_stack *stack);
void	bubble_sort(int *array, int len);
void	plot_indacies(t_stack *stack);
void	freeall(t_stack *stack);

#endif