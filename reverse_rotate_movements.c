/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate_movements.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isromero <isromero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 09:41:58 by isromero          #+#    #+#             */
/*   Updated: 2023/08/03 19:58:10 by isromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_stack **lst)
{
	t_stack	*first_node;
	t_stack	*last_node;
	t_stack	*dont_lose_info;

	if (!(*lst) || !(*lst)->next)
		return ;
	first_node = *lst;
	last_node = first_node;
	while (last_node->next)
	{
		dont_lose_info = last_node;
		last_node = last_node->next;
	}
	dont_lose_info->next = NULL;
	last_node->prev = NULL;
	last_node->next = first_node;
	first_node->prev = last_node;
	*lst = last_node;
	printf("rra\n");
}

// El último nodo de stack_b pasa a ser el primero
void	rrb(t_stack **lst)
{
	t_stack	*first_node;
	t_stack	*last_node;
	t_stack	*dont_lose_info;

	if (!(*lst) || !(*lst)->next)
		return ;
	first_node = *lst;
	last_node = first_node;
	while (last_node->next)
	{
		dont_lose_info = last_node;
		last_node = last_node->next;
	}
	dont_lose_info->next = NULL;
	last_node->prev = NULL;
	last_node->next = first_node;
	first_node->prev = last_node;
	*lst = last_node;
	printf("rrb\n");
}

void	reverse_stack(t_stack **stack)
{
	t_stack	*first_node;
	t_stack	*last_node;
	t_stack	*dont_lose_info;

	first_node = *stack;
	last_node = first_node;
	dont_lose_info = NULL;
	while (last_node->next)
	{
		dont_lose_info = last_node;
		last_node = last_node->next;
	}
	dont_lose_info->next = NULL;
	last_node->prev = NULL;
	last_node->next = first_node;
	first_node->prev = last_node;
	*stack = last_node;
}

void	rrr(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*last_node_a;
	t_stack	*last_node_b;

	last_node_a = get_last_node(*stack_a);
	last_node_b = get_last_node(*stack_b);
	reverse_stack(stack_a);
	reverse_stack(stack_b);
	(*stack_a)->prev = last_node_a;
	(*stack_b)->prev = last_node_b;
	printf("rrr\n");
}
