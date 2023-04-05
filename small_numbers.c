/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_numbers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 20:15:20 by marvin            #+#    #+#             */
/*   Updated: 2023/03/26 20:15:20 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    sort_2(t_stack **stack_a)
{
	t_stack *first_node;

	first_node = *stack_a;
	if(first_node->data < first_node->next->data)
		return ;
	if(first_node->data > first_node->next->data)
		sa(stack_a);
}

void    sort_3(t_stack **stack_a)
{
	t_stack *first_node;
	t_stack *second_node;
	t_stack *third_node;

	first_node = *stack_a;
	second_node = (*stack_a)->next;
	third_node = (*stack_a)->next->next;

	if(first_node->data < second_node->data && second_node->data < third_node->data)
		return ;
	if(first_node->data > second_node->data && first_node->data > third_node->data && second_node->data > third_node->data) //3 2 1
	{
		ra(stack_a);
		if(first_node->data > second_node->data) // 2 1 3
			sa(stack_a);
	}
	if(first_node->data > second_node->data && first_node->data < third_node->data) // 2 1 3
			sa(stack_a);
	if(first_node->data < second_node->data && first_node->data < third_node->data && second_node->data > third_node->data) //1 3 2
	{
		sa(stack_a);
		ra(stack_a);
	}
	if(first_node->data < second_node->data && first_node->data > third_node->data) // 2 3 1
		rra(stack_a);
	if(first_node->data > second_node->data && first_node->data > third_node->data && second_node->data < third_node->data) //3 1 2
		ra(stack_a);
}

void sort_5(t_stack **stack_a, t_stack **stack_b)
{
    while (*stack_a)
    {
        int max_a = find_max_number(*stack_a);
        int min_a = find_min_number(*stack_a);

        while((*stack_a)->data != max_a)
            ra(stack_a);
        if((*stack_a)->data == max_a)
            pb(stack_a, stack_b);
        if((*stack_a)->data == min_a)
            pb(stack_a, stack_b);
        if(ft_lstsize2(*stack_a) == 3)
            sort_3(stack_a);
        if((*stack_b)->data == find_min_number(*stack_b))
        {
            if ((*stack_b)->next && (*stack_b)->next->data == find_max_number(*stack_b))
                pa(stack_a, stack_b);
        }
        if((*stack_b)->data == find_max_number(*stack_b))
        {
            if ((*stack_b)->next && (*stack_b)->next->data == find_min_number(*stack_b))
            {
                pa(stack_a, stack_b);
                ra(stack_a);
            }
        }
    }   
  
}
