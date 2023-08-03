/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_500.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isromero <isromero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 10:27:00 by isromero          #+#    #+#             */
/*   Updated: 2023/08/03 21:17:19 by isromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	desc_order_50_smallest(t_stack **temp, int i, int tmp, int *smallest)
{
	int	j;

	j = 0;
	while (i < 50 && *temp)
	{
		smallest[i] = (*temp)->data;
		*temp = (*temp)->next;
		i++;
	}
	i = 0;
	while (i < 49)
	{
		j = 0;
		while (j < 49 - i)
		{
			if (smallest[j] < smallest[j + 1])
			{
				tmp = smallest[j];
				smallest[j] = smallest[j + 1];
				smallest[j + 1] = tmp;
			}
			j++;
		}
		i++;
	}
}

void	update_50_smallest(t_stack **temp, int i, int *smallest)
{
	int	j;

	j = 0;
	while (*temp)
	{
		i = 49;
		while (i >= 0)
		{
			if ((*temp)->data < smallest[i])
			{
				j = 0;
				while (j < i)
				{
					smallest[j] = smallest[j + 1];
					j++;
				}
				smallest[i] = (*temp)->data;
				break ;
			}
			i--;
		}
		*temp = (*temp)->next;
	}
}

int	*save_50_smallest_chunk(t_stack *stack_a)
{
	int		*smallest;
	int		i;
	t_stack	*temp;
	int		tmp;

	smallest = malloc(sizeof(int) * 50);
	temp = stack_a;
	i = 0;
	tmp = 0;
	desc_order_50_smallest(&temp, i, tmp, smallest);
	i = 0;
	update_50_smallest(&temp, i, smallest);
	return (smallest);
}

void	sort_500(t_stack **stack_a, t_stack **stack_b)
{
	int	i;
	int	j;
	int	*smallest;

	i = 0;
	while (i < 10)
	{
		j = 0;
		smallest = save_50_smallest_chunk(*stack_a);
		while (j < 50)
		{
			top_and_bottom_plus_detector_smallest_50(stack_a, stack_b,
				smallest);
			j++;
		}
		free(smallest);
		i++;
	}
	while (!is_descending_sorted(*stack_b))
		rb_or_rrb(stack_b, find_max_node(*stack_b));
	while (*stack_b != NULL)
		pa(stack_a, stack_b);
}

void	top_and_bottom_plus_detector_smallest_50(t_stack **stack_a,
		t_stack **stack_b, int *smallest)
{
	t_stack	*current_a;
	t_stack	*last;

	current_a = *stack_a;
	last = get_last_node(*stack_a);
	while (!(current_a->data >= smallest[49] && current_a->data <= smallest[0]))
		current_a = current_a->next;
	while (!(last->data >= smallest[49] && last->data <= smallest[0]))
		last = last->prev;
	if (last->data >= smallest[49] && last->data <= smallest[0] && current_a
		&& current_a->data >= smallest[49] && current_a->data <= smallest[0])
	{
		last->bottom_a_movements = bottom_to_top(*stack_a, last);
		current_a->top_a_movements = top_to_bottom(*stack_a, current_a);
	}
	if (last->data >= smallest[49] && last->data <= smallest[0] && current_a
		&& current_a->data >= smallest[49] && current_a->data <= smallest[0])
		movements_checker_to_push_b(stack_a, stack_b, current_a, last);
}
