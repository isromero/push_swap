/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isromero <isromero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 20:14:46 by isromero          #+#    #+#             */
/*   Updated: 2023/08/04 20:14:46 by isromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_2(t_stack **stack_a)
{
	t_stack	*first_node;

	first_node = *stack_a;
	if (first_node->data < first_node->next->data)
		return ;
	if (first_node->data > first_node->next->data)
		sa(stack_a);
}

void	sort_3_part2(t_stack **stack_a, t_stack *first_node,
	t_stack *second_node, t_stack *third_node)
{
	if (first_node->data < second_node->data
		&& first_node->data < third_node->data
		&& second_node->data > third_node->data)
	{
		sa(stack_a);
		ra(stack_a);
	}
	else if (first_node->data < second_node->data
		&& first_node->data > third_node->data)
		rra(stack_a);
	else if (first_node->data > second_node->data
		&& first_node->data > third_node->data
		&& second_node->data < third_node->data)
		ra(stack_a);
}

void	sort_3(t_stack **stack_a)
{
	t_stack	*first_node;
	t_stack	*second_node;
	t_stack	*third_node;

	first_node = *stack_a;
	second_node = (*stack_a)->next;
	third_node = (*stack_a)->next->next;
	if (first_node->data < second_node->data
		&& second_node->data < third_node->data)
		return ;
	else if (first_node->data > second_node->data
		&& first_node->data > third_node->data
		&& second_node->data > third_node->data)
	{
		ra(stack_a);
		if (first_node->data > second_node->data)
			sa(stack_a);
	}
	else if (first_node->data > second_node->data
		&& first_node->data < third_node->data)
		sa(stack_a);
	sort_3_part2(stack_a, first_node, second_node, third_node);
}

void	sort_4(t_stack **stack_a, t_stack **stack_b)
{
	while (find_min_node(*stack_a) != (*stack_a))
		ra_or_rra(stack_a, find_min_node(*stack_a));
	if (find_min_node(*stack_a) == (*stack_a))
		pb(stack_a, stack_b);
	sort_3(stack_a);
	pa(stack_a, stack_b);
}
