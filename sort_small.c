/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_numbers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+
	+:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+
	+#+        */
/*                                                +#+#+#+#+#+
	+#+           */
/*   Created: 2023/03/26 20:15:20 by marvin            #+#    #+#             */
/*   Updated: 2023/03/26 20:15:20 by marvin           ###   ########.fr       */
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
	if (first_node->data > second_node->data
		&& first_node->data > third_node->data
		&& second_node->data > third_node->data)
	{
		ra(stack_a);
		if (first_node->data > second_node->data)
			sa(stack_a);
	}
	if (first_node->data > second_node->data
		&& first_node->data < third_node->data)
		sa(stack_a);
	if (first_node->data < second_node->data
		&& first_node->data < third_node->data
		&& second_node->data > third_node->data)
	{
		sa(stack_a);
		ra(stack_a);
	}
	if (first_node->data < second_node->data
		&& first_node->data > third_node->data)
		rra(stack_a);
	if (first_node->data > second_node->data
		&& first_node->data > third_node->data
		&& second_node->data < third_node->data)
		ra(stack_a);
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

void	sort_5(t_stack **stack_a, t_stack **stack_b)
{
	int	min_b;
	int	max_b;
	int	min_a;
	int	max_a;

	pb(stack_a, stack_b);
	pb(stack_a, stack_b);
	sort_3(stack_a);
	while (*stack_b)
	{
		min_b = find_min_node(*stack_b)->data;
		max_b = find_max_node(*stack_b)->data;
		min_a = find_min_node(*stack_a)->data;
		max_a = find_max_node(*stack_a)->data;
		if ((min_b == (*stack_b)->data && min_b < min_a)
			|| (*stack_b)->data < min_a)
			pa(stack_a, stack_b);
		else if ((max_b == (*stack_b)->data && max_b > max_a)
			|| (*stack_b)->data > max_a)
		{
			pa(stack_a, stack_b);
			ra(stack_a);
		}
		if (stack_size(*stack_a) == 3)
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
		if (stack_size(*stack_a) == 4)
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
	}
}
