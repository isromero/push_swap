/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isromero <isromero@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 11:59:12 by isromero          #+#    #+#             */
/*   Updated: 2023/08/19 12:20:25 by isromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft_reduced/libft.h"
# include <limits.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_stack
{
	struct s_stack	*prev;
	int				data;
	struct s_stack	*next;
	int				rank;
	int				top_a_movements;
	int				bottom_a_movements;
	int				top_b_movements;
	int				bottom_b_movements;
	int				how_many_one_arg;
}					t_stack;

/*push_movements.c*/
void	pa(t_stack **stack_a, t_stack **stack_b);
void	pb(t_stack **stack_a, t_stack **stack_b);
/* push_swap.c */
void	check_how_many_sort(int argc, t_stack **stack_a, t_stack **stack_b);

/*ready_stacks.c*/
void	node_add_back(t_stack **lst, int data);
void	only_numbers(char **argv, int word);
void	duplicated_numbers(char **argv, int i);
void	one_argument_input(char **argv, t_stack **stack_a);
int		input_and_fill(int argc, char **argv, t_stack **stack_a);

/*reverse_rotate_movements.c*/
void	rra(t_stack **lst);
void	rrb(t_stack **lst);
void	reverse_stack(t_stack **stack);
void	rrr(t_stack **stack_a, t_stack **stack_b);

/*rotate_movements.c*/
void	ra(t_stack **lst);
void	rb(t_stack **lst);
void	rotate_stack(t_stack **stack);
void	rr(t_stack **stack_a, t_stack **stack_b);

/*sort_2_3_4.c*/
void	sort_2(t_stack **stack_a);
void	sort_3(t_stack **stack_a);
void	sort_3_part2(t_stack **stack_a, t_stack *first_node,
			t_stack *second_node, t_stack *third_node);
void	sort_4(t_stack **stack_a, t_stack **stack_b);

/* sort_5.c */
void	sort_5_size_3(t_stack **stack_a, t_stack **stack_b);
void	sort_5_size_4(t_stack **stack_a, t_stack **stack_b);
void	sort_5(t_stack **stack_a, t_stack **stack_b);

/* sort_100.c */
void	desc_order_20_smallest(t_stack **temp, int i, int tmp, int *smallest);
void	update_20_smallest(t_stack **temp, int i, int *smallest);
int		*save_20_smallest_chunk(t_stack *stack_a);
void	sort_100(t_stack **stack_a, t_stack **stack_b);
void	top_and_bottom_plus_detector_smallest_20(t_stack **stack_a,
			t_stack **stack_b, int *smallest);

/* sort_500.c */
void	desc_order_50_smallest(t_stack **temp, int i, int tmp, int *smallest);
void	update_50_smallest(t_stack **temp, int i, int *smallest);
int		*save_50_smallest_chunk(t_stack *stack_a);
void	sort_500(t_stack **stack_a, t_stack **stack_b);
void	top_and_bottom_plus_detector_smallest_50(t_stack **stack_a,
			t_stack **stack_b, int *smallest);

/* sort_everything.c */
void	sort_everything_with_dynamic_chunks_20(t_stack **stack_a,
			t_stack **stack_b);

/* sort_utils.c */
void	movements_top_a_less_than_top_b(t_stack **stack_a, t_stack **stack_b,
			t_stack *current_a);
void	movements_top_a_greater_than_top_b(t_stack **stack_a, t_stack **stack_b,
			t_stack *last);
void	movements_checker_to_push_b(t_stack **stack_a, t_stack **stack_b,
			t_stack *current_a, t_stack *last);
void	rotate_b_until_push(t_stack **stack_a, t_stack **stack_b,
			t_stack *temp_b);
void	check_position_to_push_b(t_stack **stack_a, t_stack **stack_b);

/*swap_movements.c*/
void	sa(t_stack **lst);
void	sb(t_stack **lst);
void	ss(t_stack **stack_a, t_stack **stack_b);

/*utils.c*/
int		stack_size(t_stack *stack);
int		is_sorted(t_stack *stack);
int		is_descending_sorted(t_stack *stack);
t_stack	*find_max_node(t_stack *stack);
t_stack	*find_min_node(t_stack *stack);

/*utils2.c*/
t_stack	*get_last_node(t_stack *stack);
int		top_to_bottom(t_stack *stack, t_stack *selected);
int		bottom_to_top(t_stack *stack, t_stack *selected);
void	ra_or_rra(t_stack **stack, t_stack *selected);
void	rb_or_rrb(t_stack **stack, t_stack *selected);

/*utils3.c*/
void	free_stack(t_stack **stack_a);
bool	contains_only_spaces(const char *str);

#endif