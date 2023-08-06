/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isromero <isromero@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 20:18:19 by isromero          #+#    #+#             */
/*   Updated: 2023/08/06 17:27:11 by isromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	movements_top_a_less_than_top_b(t_stack **stack_a, t_stack **stack_b,
	t_stack *current_a)
{
	int	i;

	i = 0;
	if (current_a->top_a_movements != current_a->top_b_movements)
	{
		while (i++ < current_a->top_a_movements)
			ra(stack_a);
		check_position_to_push_b(stack_a, stack_b);
	}
	else if (current_a->top_a_movements == current_a->top_b_movements)
	{
		while (i++ < current_a->top_a_movements)
			rr(stack_a, stack_b);
		check_position_to_push_b(stack_a, stack_b);
	}
}

void	movements_top_a_greater_than_top_b(t_stack **stack_a, t_stack **stack_b,
	t_stack *last)
{
	int	i;

	i = 0;
	if (last->bottom_a_movements != last->bottom_b_movements)
	{
		while (i++ < last->bottom_a_movements)
			rra(stack_a);
		check_position_to_push_b(stack_a, stack_b);
	}
	else if (last->bottom_a_movements == last->bottom_b_movements)
	{
		while (i++ < last->bottom_a_movements)
			rrr(stack_a, stack_b);
		check_position_to_push_b(stack_a, stack_b);
	}
}

void	movements_checker_to_push_b(t_stack **stack_a, t_stack **stack_b,
		t_stack *current_a, t_stack *last)
{
	if (current_a->top_a_movements <= last->bottom_a_movements)
		movements_top_a_less_than_top_b(stack_a, stack_b, current_a);
	else
		movements_top_a_greater_than_top_b(stack_a, stack_b, last);
}

void	rotate_b_until_push(t_stack **stack_a, t_stack **stack_b,
		t_stack *temp_b)
{
	while (temp_b)
	{
		if ((*stack_a)->data < temp_b->data
			&& (*stack_a)->data > temp_b->next->data)
		{
			temp_b = temp_b->next;
			break ;
		}
		temp_b = temp_b->next;
	}
	rb_or_rrb(stack_b, temp_b);
	pb(stack_a, stack_b);
}

void	check_position_to_push_b(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*temp_b;

	temp_b = *stack_b;
	if (*stack_b == NULL)
		pb(stack_a, stack_b);
	else if (((*stack_a)->data < (*stack_b)->data
			|| (*stack_a)->data > (*stack_b)->data)
		&& stack_size(*stack_b) == 1)
		pb(stack_a, stack_b);
	else if ((*stack_a)->data >= find_max_node(*stack_b)->data
		|| (*stack_a)->data <= find_min_node(*stack_b)->data)
	{
		while (!(find_max_node(*stack_b)->data == (*stack_b)->data
				&& find_min_node(*stack_b)->data
				== get_last_node(*stack_b)->data))
			rb_or_rrb(stack_b, find_max_node(*stack_b));
		pb(stack_a, stack_b);
	}
	else if ((*stack_a)->data < get_last_node(*stack_b)->data
		&& (*stack_a)->data > (*stack_b)->data)
		pb(stack_a, stack_b);
	else
		rotate_b_until_push(stack_a, stack_b, temp_b);
}
