/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isromero <isromero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 10:16:04 by isromero          #+#    #+#             */
/*   Updated: 2023/08/04 20:13:39 by isromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*get_last_node(t_stack *stack)
{
	while (stack)
	{
		if (!stack->next)
			return (stack);
		stack = stack->next;
	}
	return (stack);
}

int	top_to_bottom(t_stack *stack, t_stack *selected)
{
	int		count;
	t_stack	*temp;

	count = 0;
	temp = stack;
	while (temp)
	{
		if (temp == selected)
			break ;
		temp = temp->next;
		count++;
	}
	return (count);
}

int	bottom_to_top(t_stack *stack, t_stack *selected)
{
	int		count;
	t_stack	*temp;

	count = 0;
	temp = get_last_node(stack);
	while (temp)
	{
		if (temp == selected)
			break ;
		temp = temp->prev;
		count++;
	}
	return (count + 1);
}

void	ra_or_rra(t_stack **stack, t_stack *selected)
{
	int	top_movements;

	top_movements = 0;
	top_movements = top_to_bottom(*stack, selected);
	if (top_movements <= stack_size(*stack) / 2)
	{
		while (selected != (*stack))
			ra(stack);
	}
	else
	{
		while (selected != (*stack))
			rra(stack);
	}
}

void	rb_or_rrb(t_stack **stack, t_stack *selected)
{
	int	top_movements;

	top_movements = 0;
	top_movements = top_to_bottom(*stack, selected);
	if (top_movements <= stack_size(*stack) / 2)
	{
		while (selected != (*stack))
			rb(stack);
	}
	else
	{
		while (selected != (*stack))
			rrb(stack);
	}
}
