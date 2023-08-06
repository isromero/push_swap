/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_5.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isromero <isromero@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 20:17:23 by isromero          #+#    #+#             */
/*   Updated: 2023/08/06 17:28:03 by isromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_5_size_3(t_stack **stack_a, t_stack **stack_b)
{
	if ((*stack_b)->data > (*stack_a)->data
		&& (*stack_b)->data < (*stack_a)->next->data)
	{
		pa(stack_a, stack_b);
		sa(stack_a);
	}
	else if ((*stack_b)->data > (*stack_a)->next->data
		&& (*stack_b)->data < get_last_node(*stack_a)->data)
	{
		rra(stack_a);
		pa(stack_a, stack_b);
		ra(stack_a);
		ra(stack_a);
	}
}

void	sort_5_size_4(t_stack **stack_a, t_stack **stack_b)
{
	if ((*stack_b)->data > (*stack_a)->data
		&& (*stack_b)->data < (*stack_a)->next->data)
	{
		pa(stack_a, stack_b);
		sa(stack_a);
	}
	else if ((*stack_b)->data > (*stack_a)->next->data
		&& (*stack_b)->data < (*stack_a)->next->next->data)
	{
		ra(stack_a);
		pa(stack_a, stack_b);
		sa(stack_a);
		rra(stack_a);
	}
	else if ((*stack_b)->data > (*stack_a)->next->next->data
		&& (*stack_b)->data < get_last_node(*stack_a)->data)
	{
		rra(stack_a);
		pa(stack_a, stack_b);
		ra(stack_a);
		ra(stack_a);
	}
}

void	sort_5(t_stack **stack_a, t_stack **stack_b)
{
	pb(stack_a, stack_b);
	pb(stack_a, stack_b);
	sort_3(stack_a);
	while (*stack_b)
	{
		if ((find_min_node(*stack_b)->data == (*stack_b)->data
				&& find_min_node(*stack_b)->data
				< find_min_node(*stack_a)->data)
			|| (*stack_b)->data < find_min_node(*stack_a)->data)
			pa(stack_a, stack_b);
		else if ((find_max_node(*stack_b)->data == (*stack_b)->data
				&& find_max_node(*stack_b)->data
				> find_max_node(*stack_a)->data)
			|| (*stack_b)->data > find_max_node(*stack_a)->data)
		{
			pa(stack_a, stack_b);
			ra(stack_a);
		}
		if (stack_size(*stack_a) == 3)
			sort_5_size_3(stack_a, stack_b);
		if (stack_size(*stack_a) == 4)
			sort_5_size_4(stack_a, stack_b);
	}
}
