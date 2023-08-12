/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_movements.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isromero <isromero@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 09:41:56 by isromero          #+#    #+#             */
/*   Updated: 2023/08/12 14:22:36 by isromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*node_stack_b;

	if (!*stack_b)
		return ;
	node_stack_b = *stack_b;
	*stack_b = node_stack_b->next;
	node_stack_b->next = *stack_a;
	if (*stack_a)
		(*stack_a)->prev = node_stack_b;
	*stack_a = node_stack_b;
	if (*stack_a)
		(*stack_a)->prev = NULL;
	ft_putstr("pa\n");
}

void	pb(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*node_stack_a;

	if (!*stack_a)
		return ;
	node_stack_a = *stack_a;
	*stack_a = node_stack_a->next;
	node_stack_a->next = *stack_b;
	if (*stack_b)
		(*stack_b)->prev = node_stack_a;
	*stack_b = node_stack_a;
	if (*stack_b)
		(*stack_b)->prev = NULL;
	ft_putstr("pb\n");
}
