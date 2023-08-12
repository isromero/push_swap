/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_movements.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isromero <isromero@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 09:44:27 by isromero          #+#    #+#             */
/*   Updated: 2023/08/12 14:23:37 by isromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_stack **lst)
{
	t_stack	*first_node;
	t_stack	*last_node;

	if (!(*lst) || !(*lst)->next)
		return ;
	first_node = *lst;
	last_node = first_node;
	while (last_node->next)
		last_node = last_node->next;
	*lst = first_node->next;
	last_node->next = first_node;
	first_node->next = NULL;
	first_node->prev = last_node;
	if (*lst)
		(*lst)->prev = NULL;
	ft_putstr("ra\n");
}

void	rb(t_stack **lst)
{
	t_stack	*first_node;
	t_stack	*last_node;

	if (!(*lst) || !(*lst)->next)
		return ;
	first_node = *lst;
	last_node = first_node;
	while (last_node->next)
		last_node = last_node->next;
	*lst = first_node->next;
	last_node->next = first_node;
	first_node->next = NULL;
	first_node->prev = last_node;
	if (*lst)
		(*lst)->prev = NULL;
	ft_putstr("rb\n");
}

void	rotate_stack(t_stack **stack)
{
	t_stack	*first_node;
	t_stack	*last_node;

	if (*stack && (*stack)->next)
	{
		first_node = *stack;
		*stack = first_node->next;
		(*stack)->prev = NULL;
		last_node = first_node;
		while (last_node->next)
			last_node = last_node->next;
		last_node->next = first_node;
		first_node->next = NULL;
		first_node->prev = last_node;
	}
}

void	rr(t_stack **stack_a, t_stack **stack_b)
{
	rotate_stack(stack_a);
	rotate_stack(stack_b);
	ft_putstr("rr\n");
}
