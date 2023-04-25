/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isromero <isromero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 11:59:12 by isromero          #+#    #+#             */
/*   Updated: 2023/04/25 08:47:32 by isromero         ###   ########.fr       */
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
    int             rank;
    int             top_a_movements;
    int             bottom_a_movements;
    int             top_b_movements;
    int             bottom_b_movements;
}	t_stack;

typedef struct		s_move
{
	char			*name;
	struct s_move	*next;
}					t_move;

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


void    rra(t_stack **lst);
void    rrb(t_stack **lst);
void    rrr(t_stack **stack_a, t_stack **stack_b);


void    sort_2(t_stack **stack_a);
void    sort_3(t_stack **stack_a);
void    sort_5(t_stack **stack_a, t_stack **stack_b);


int     is_sorted(t_stack *stack);
int		ft_lstsize2(t_stack *lst);
int     is_sorted(t_stack *stack);
int 	find_max_number(t_stack *stack);
int		find_min_number(t_stack *stack);
t_stack	*get_last_node(t_stack *stack);
int		minimum_rotate_movements(t_stack *stack_a);
void   rb_or_rrb_god(t_stack **stack, t_stack *selected);
int find_min_number_smallest(int *smallest);
void    rb_or_rrb(t_stack **stack_b);
t_stack *find_max_node(t_stack *stack);
int		get_index(t_stack *stack, int value);

int     get_index_bottom(t_stack *stack, int value);

int     is_descending_sorted(t_stack *stack);

int    *save_50_smallest_chunk(t_stack *stack_a);
void    check_position_to_push_b(t_stack **stack_a, t_stack **stack_b);
void	movements_checker_to_push_b(t_stack **stack_a, t_stack **stack_b, t_stack *current_a, t_stack *last);
void top_and_bottom_plus_detector_smallest_20(t_stack **stack_a, t_stack **stack_b, int *smallest);
void top_and_bottom_plus_detector_smallest_50(t_stack **stack_a, t_stack **stack_b, int *smallest);
int find_max_number_smallest(int *smallest);

int    *save_20_smallest_chunk(t_stack *stack_a);
void    push_to_b_good_position(t_stack *stack_b);
void    sort_100(t_stack **stack_a, t_stack **stack_b);
void    sort_500(t_stack **stack_a, t_stack **stack_b);
void sort_everything_with_dynamic_chunks_20(t_stack **stack_a, t_stack **stack_b);
void    short_path_rb_or_rrb(t_stack **stack);
int     rrb_short_path(t_stack *stack);
int top_to_bottom(t_stack *stack, t_stack *selected);
int     bottom_to_top(t_stack *stack, t_stack *selected);
int     find_index_of_selected(int *smallest, int selected);
int     top_to_bottom_modified(t_stack *stack, t_stack *last);

#endif