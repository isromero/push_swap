/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isromero <isromero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 11:59:12 by isromero          #+#    #+#             */
/*   Updated: 2023/04/26 11:09:14 by isromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <stdbool.h>
# include <limits.h>
# include "libft_reduced/libft.h"

typedef struct s_stack {
	struct s_stack	*prev;
	int				data;
	struct s_stack	*next;
	int             rank;
	int             top_a_movements;
	int             bottom_a_movements;
	int             top_b_movements;
	int             bottom_b_movements;
}	t_stack;

/*ready_stacks.c*/
void	node_add_back(t_stack **lst, int data);
void    only_numbers(int argc, char **argv);
void    duplicated_numbers(int argc, char **argv);
int 	input_and_fill(int argc, char **argv, t_stack **stack_a, t_stack **stack_b);
//void	print_stacks(t_stack **stack_a, t_stack **stack_b);

/*push_movements.c*/
void	pa(t_stack **stack_a, t_stack **stack_b);
void	pb(t_stack **stack_a, t_stack **stack_b);

/*swap_movements.c*/
void    sa(t_stack **lst);
void    sb(t_stack **lst);
void	ss(t_stack **stack_a, t_stack **stack_b);

/*rotate_movements.c*/
void	ra(t_stack **lst);
void	rb(t_stack **lst);
void	rr(t_stack **stack_a, t_stack **stack_b);

/*reverse_rotate_movements.c*/
void    rra(t_stack **lst);
void    rrb(t_stack **lst);
void    rrr(t_stack **stack_a, t_stack **stack_b);

/*sort_small.c*/
void	sort_2(t_stack **stack_a);
void    sort_3(t_stack **stack_a);
void    sort_4(t_stack **stack_a, t_stack **stack_b);
void    sort_5(t_stack **stack_a, t_stack **stack_b);

/*utils.c*/
int		stack_size(t_stack *stack);
int 	is_sorted(t_stack *stack);
int 	is_descending_sorted(t_stack *stack);
t_stack	*find_max_node(t_stack *stack);
t_stack	*find_min_node(t_stack *stack);

/*utils2.c*/
t_stack	*get_last_node(t_stack *stack);
int		top_to_bottom(t_stack *stack, t_stack *selected);
int		bottom_to_top(t_stack *stack, t_stack *selected);
void	ra_or_rra(t_stack **stack, t_stack *selected);
void	rb_or_rrb(t_stack **stack, t_stack *selected);

/*sort_small.c*/
void	sort_2(t_stack **stack_a);
void    sort_3(t_stack **stack_a);
void    sort_4(t_stack **stack_a, t_stack **stack_b);
void 	sort_5(t_stack **stack_a, t_stack **stack_b);

/*sort_everything.c*/
void	sort_everything_with_dynamic_chunks_20(t_stack **stack_a, t_stack **stack_b);
void	save_rb_rrb_movements_for_rr_or_rrr(t_stack **stack_a, t_stack **stack_b, t_stack *current_a, t_stack *last);
void	movements_checker_to_push_b(t_stack **stack_a, t_stack **stack_b, t_stack *current_a, t_stack *last);
void    check_position_to_push_b(t_stack **stack_a, t_stack **stack_b);

/*sort_100.c*/
int		*save_20_smallest_chunk(t_stack *stack_a);
void	sort_100(t_stack **stack_a, t_stack **stack_b);
void	top_and_bottom_plus_detector_smallest_20(t_stack **stack_a, t_stack **stack_b, int *smallest);

/*sort_500.c*/
int    *save_50_smallest_chunk(t_stack *stack_a);
void	sort_500(t_stack **stack_a, t_stack **stack_b);
void 	top_and_bottom_plus_detector_smallest_50(t_stack **stack_a, t_stack **stack_b, int *smallest);

#endif