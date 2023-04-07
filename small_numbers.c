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
	pb(stack_a, stack_b);
	pb(stack_a, stack_b);


	sort_3(stack_a);
	while (*stack_b)
	{
		int min_b = find_min_number(*stack_b);
		int max_b = find_max_number(*stack_b);
		int min_a = find_min_number(*stack_a);
		int max_a = find_max_number(*stack_a);
		if((min_b == (*stack_b)->data && min_b < min_a) || (*stack_b)->data < min_a)
			pa(stack_a, stack_b);
		else if((max_b == (*stack_b)->data && max_b > max_a || (*stack_b)->data > max_a))
		{
			pa(stack_a, stack_b);
			ra(stack_a);
		}
		if(ft_lstsize2(*stack_a) == 3)
		{
			//Checkeamos si el primer nodo es el mínimo y es < que todos los nodos de A(3)
		
			if((*stack_b)->data > (*stack_a)->data && (*stack_b)->data < (*stack_a)->next->data)
			{
				pa(stack_a, stack_b);
				sa(stack_a);
			}
			else if((*stack_b)->data > (*stack_a)->next->data && (*stack_b)->data < get_last_node(*stack_a)->data)
			{
				rra(stack_a);
				pa(stack_a, stack_b);
				//STOPS HERE, It does not matter if it is pa, or another type of movement------------------------------------------------------------------------------
				ra(stack_a);
				ra(stack_a);
			}   
		}
		if(ft_lstsize2(*stack_a) == 4)
		{
			
			//Checkeamos si el primer nodo es el mínimo y es < que todos los nodos de A(4) después de que quede 1 nodo en B
			if((*stack_b)->data > (*stack_a)->data && (*stack_b)->data < (*stack_a)->next->data)
			{
				pa(stack_a, stack_b);
				sa(stack_a);
			}
			else if((*stack_b)->data > (*stack_a)->next->data && (*stack_b)->data < (*stack_a)->next->next->data)
			{
				ra(stack_a);
				ra(stack_a);
				pa(stack_a, stack_b);
				rra(stack_a);
				rra(stack_a);
			}
			else if((*stack_b)->data > (*stack_a)->next->next->data && (*stack_b)->data < get_last_node(*stack_a)->data)
			{
				rra(stack_a);
				pa(stack_a, stack_b);
				ra(stack_a);
				ra(stack_a);
			}
		}

	}
}
