/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_movements.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isromero <isromero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 09:42:00 by isromero          #+#    #+#             */
/*   Updated: 2023/08/04 20:13:01 by isromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_stack **lst)
{
	t_stack	*node_a;
	t_stack	*node_b;
	t_stack	*node_c;

	if (!*lst || !(*lst)->next)
		return ;
	node_a = *lst;
	node_b = (*lst)->next;
	node_c = (*lst)->next->next;
	node_b->next = node_a;
	node_a->prev = node_b;
	node_a->next = NULL;
	if (node_c)
		node_a->next = node_c;
	*lst = node_b;
	printf("sa\n");
}

void	sb(t_stack **lst)
{
	t_stack	*node_a;
	t_stack	*node_b;
	t_stack	*node_c;

	if (!*lst || !(*lst)->next)
		return ;
	node_a = *lst;
	node_b = (*lst)->next;
	node_c = (*lst)->next->next;
	node_b->next = node_a;
	node_a->prev = node_b;
	node_a->next = NULL;
	if (node_c)
		node_a->next = node_c;
	*lst = node_b;
	printf("sb\n");
}

void	ss(t_stack **stack_a, t_stack **stack_b)
{
	sa(stack_a);
	sb(stack_b);
	printf("ss\n");
}
