/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_everything.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isromero <isromero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 10:26:58 by isromero          #+#    #+#             */
/*   Updated: 2023/04/26 11:14:21 by isromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void sort_everything_with_dynamic_chunks_20(t_stack **stack_a, t_stack **stack_b)
{
	int i;
	int	j;
	int	*smallest = save_20_smallest_chunk(*stack_a);
	
	i = 0;
	while (stack_size(*stack_a) != 0) 
	{
		j = 0;
		int	*smallest = save_20_smallest_chunk(*stack_a);
		top_and_bottom_plus_detector_smallest_20(stack_a, stack_b, smallest);
		free(smallest);
		i++;
	}
    while(!is_descending_sorted(*stack_b))
    	rb_or_rrb(stack_b, find_max_node(*stack_b));
    while(*stack_b != NULL)
        pa(stack_a, stack_b);
}

void	save_rb_rrb_movements_for_rr_or_rrr(t_stack **stack_a, t_stack **stack_b, t_stack *current_a, t_stack *last)
{
	t_stack *temp_b_current;
	t_stack *temp_b_last;

	temp_b_current = *stack_b;
	temp_b_last = *stack_b;

	if(current_a->data >= find_max_node(*stack_b)->data || current_a->data <= find_min_node(*stack_b)->data)
		current_a->top_b_movements = top_to_bottom(*stack_b, find_max_node(*stack_b));
	else if(last->data >= find_max_node(*stack_b)->data || last->data <= find_min_node(*stack_b)->data)
		last->bottom_b_movements = bottom_to_top(*stack_b, find_max_node(*stack_b));
	else if(!(current_a->data >= find_max_node(*stack_b)->data || current_a->data <= find_min_node(*stack_b)->data))
	{
		while(temp_b_current)
		{
			if(temp_b_current->next != NULL && current_a->data < temp_b_current->data && current_a->data > temp_b_current->next->data)
			{
				temp_b_current = temp_b_current->next;
				break ;
			}
			temp_b_current = temp_b_current->next;
		}
		current_a->top_b_movements = top_to_bottom(*stack_b, temp_b_current);
	}

	else if(!(last->data >= find_max_node(*stack_b)->data || last->data <= find_min_node(*stack_b)->data))
	{
		while(temp_b_last)
		{
			if(temp_b_last->next != NULL && last->data < temp_b_last->data && last->data > temp_b_last->next->data)
			{
					temp_b_last = temp_b_last->next;
					break ;
			}
			temp_b_last = temp_b_last->next;
		}
		last->bottom_b_movements = bottom_to_top(*stack_b, temp_b_last);
	}
}

void	movements_checker_to_push_b(t_stack **stack_a, t_stack **stack_b, t_stack *current_a, t_stack *last)
{
	int	i;
	
	i = 0;
    if (current_a->top_a_movements <= last->bottom_a_movements)
    {
		if(current_a->top_a_movements != current_a->top_b_movements)
		{
			while (i++ < current_a->top_a_movements)
				ra(stack_a);
			check_position_to_push_b(stack_a, stack_b);
		}
		if(current_a->top_a_movements == current_a->top_b_movements)
		{
			while (i++ < current_a->top_a_movements)
				rr(stack_a, stack_b);
			check_position_to_push_b(stack_a, stack_b);
		}
	}
    else
    {
        if(last->bottom_a_movements != last->bottom_b_movements)
		{
			while (i++ < last->bottom_a_movements)
				rra(stack_a);
			check_position_to_push_b(stack_a, stack_b);
		}
		if(last->bottom_a_movements == last->bottom_b_movements)
		{
			while (i++ < last->bottom_a_movements)
				rrr(stack_a, stack_b);
			check_position_to_push_b(stack_a, stack_b);
		}
	}
}

void    check_position_to_push_b(t_stack **stack_a, t_stack **stack_b)
{
	t_stack *temp_b;
	
	temp_b = *stack_b;
	if(*stack_b == NULL)
		pb(stack_a, stack_b);
	else if(((*stack_a)->data < (*stack_b)->data ||(*stack_a)->data > (*stack_b)->data) && stack_size(*stack_b) == 1)
		pb(stack_a, stack_b);
    else if((*stack_a)->data >= find_max_node(*stack_b)->data || (*stack_a)->data <= find_min_node(*stack_b)->data)
    {
        while(!(find_max_node(*stack_b)->data == (*stack_b)->data && find_min_node(*stack_b)->data == get_last_node(*stack_b)->data))
            rb_or_rrb(stack_b, find_max_node(*stack_b));
        pb(stack_a, stack_b);
    }
	else if ((*stack_a)->data < get_last_node(*stack_b)->data && (*stack_a)->data > (*stack_b)->data)
		pb(stack_a, stack_b);
	else
	{
		while(temp_b)
		{
			if((*stack_a)->data < temp_b->data && (*stack_a)->data > temp_b->next->data)
			{
				temp_b = temp_b->next;
				break ;
			}
			temp_b = temp_b->next;
		}
		rb_or_rrb(stack_b, temp_b);
		pb(stack_a, stack_b);
	}	
}