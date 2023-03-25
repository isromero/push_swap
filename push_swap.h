/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 11:59:12 by isromero          #+#    #+#             */
/*   Updated: 2023/03/25 22:25:42 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include "libft/libft.h"

typedef struct s_stack {
    struct s_stack	*prev;
	int				data;
	struct s_stack	*next;
}	t_stack;

// typedef struct s_situation {
// 	t_stack	  *stack_a;
// 	t_stack	  *stack_b;
// }	t_situation;


int	ft_ispace(char *str);
void    only_numbers(int argc, char **argv);
int	    good_input(int argc, char **argv);


t_stack *new_node(int data);
void	node_add_back(t_stack **lst, int data);
void    print_stacks(t_stack *stack_a, t_stack *stack_b);


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

#endif