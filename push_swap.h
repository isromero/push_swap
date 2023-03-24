/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isromero <isromero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 11:59:12 by isromero          #+#    #+#             */
/*   Updated: 2023/03/24 22:30:27 by isromero         ###   ########.fr       */
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
void    print_stack(t_stack *stack);


void    sa(t_stack **lst);

#endif