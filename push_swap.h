/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isromero <isromero@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 11:59:12 by isromero          #+#    #+#             */
/*   Updated: 2022/12/08 20:09:25 by isromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

typedef struct s_stack {
	int				data;
	struct s_stack	*next;
	struct s_stack	*prev;
}	t_stack;

typedef struct s_situation {
	t_stack		*stack_a;
	t_stack		*stack_b;
}	t_situation;

#endif