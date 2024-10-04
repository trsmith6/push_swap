/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trsmith <trsmith@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 09:17:32 by trsmith           #+#    #+#             */
/*   Updated: 2024/10/04 14:50:33 by trsmith          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

		//includes//
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include "main-libs/libft/libft.h"
# include "main-libs/printf/ft_printf.h"

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
int		ft_lower_sort(int nb);
int		ft_lower_sort_search(int b, int low, int high);
void	free_string_splitter(char **string_splitter);

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

		//rotate.c//
void	rotate_a(t_stack *stack, char *printer);
void	rotate_b(t_stack *stack, char *printer);
void	rotate_both(t_stack *stack, char *printer);

		//sort_index.c//
void	sort_three(t_stack *stack);
void	sort_five(t_stack *stack);
void	sort(t_stack *stack);
void	ft_sort_back(t_stack *stack);
void	ft_highest_to_top(t_stack *stack);

		//checks.c//
int		check_if_num(char *str);
int		ft_dupe_check(int *nbr, int size);
int		ft_check_zero(char *nbr);
int		check_if_sorted(t_stack *stack);
void	another_free_thing(char *string, char **string_splitter);

		//utils2.c//
int		full_check(int argc, char *argv[], t_stack *stack);
char	*arg_processor(int argc, char *argv[]);
int		str_processor(int argc, char *argv[], t_stack *stack);
void	copy_to_initstack(t_stack *stack);
int		len_of_args(int argc, char *argv[]);

		//swap.c//
void	swap_a(t_stack*stack, char *printer);
void	swap_b(t_stack *stack, char *printer);
void	swap_both(t_stack *stack, char *printer);

#endif