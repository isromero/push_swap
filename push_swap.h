/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isromero <isromero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 11:59:12 by isromero          #+#    #+#             */
/*   Updated: 2023/04/05 21:02:48 by isromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <stdbool.h>
# include <limits.h>
# include "libft/libft.h"

typedef struct s_stack {
    struct s_stack	*prev;
	int				data;
	struct s_stack	*next;
    int             index;
}	t_stack;

// typedef struct s_situation {
// 	t_stack	  *stack_a;
// 	t_stack	  *stack_b;
// }	t_situation;


int		ft_ispace(char *str);
void    only_numbers(int argc, char **argv);
void    duplicated_numbers(int argc, char **argv);
int 	input_and_fill(int argc, char **argv, t_stack **stack_a, t_stack **stack_b);

t_stack *new_node(int data);
void	node_add_back(t_stack **lst, int data);
void    print_stacks(t_stack **stack_a, t_stack **stack_b);


void    sa(t_stack **lst);
void    sb(t_stack **lst);
void	ss(t_stack **stack_a, t_stack **stack_b);


void	pa(t_stack **stack_a, t_stack **stack_b);
void	pb(t_stack **stack_a, t_stack **stack_b);


void	ra(t_stack **lst);
void	rb(t_stack **lst);
void	rr(t_stack **stack_a, t_stack **stack_b);


void rra(t_stack **lst);
void rrb(t_stack **lst);
void rrr(t_stack **stack_a, t_stack **stack_b);


void    sort_2(t_stack **stack_a);
void    sort_3(t_stack **stack_a);
void    sort_5(t_stack **stack_a, t_stack **stack_b);


int     is_sorted(t_stack *stack);


void    sort_numbers(t_stack **stack_a, t_stack **stack_b);
void	check_movements_and_pb(t_stack **stack_a, t_stack **stack_b);
int 	calculate_moves(int num, t_stack *stack_b);
int 	find_min_moves(t_stack *stack_a, t_stack *stack_b);
int		ft_lstsize2(t_stack *lst);
int     is_stack_sorted(t_stack *stack);
int 	find_max_number(t_stack *stack);
int 	find_min_number(t_stack *stack);
t_stack	*get_last_node(t_stack *stack);
int     get_steps_to_top(t_stack *stack, int data);
int     get_steps_to_bottom(t_stack *stack, int data);
void    short_path_rb_or_rrb(t_stack **stack);

#endif