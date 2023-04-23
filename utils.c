/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isromero <isromero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 21:30:47 by isromero          #+#    #+#             */
/*   Updated: 2023/04/23 08:19:43 by isromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int is_sorted(t_stack *stack)
{
    t_stack *temp = temp;
    while (temp && temp->next)
    {
        if (temp->data > temp->next->data)
            return 0;
        temp = temp->next;
    }
    return 1;
}

int is_descending_sorted(t_stack *stack)
{
    t_stack *temp = stack;
    while (temp && temp->next)
    {
        if (temp->data < temp->next->data)
            return 0;
        temp = temp->next;
    }
    return 1;
}

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
int find_min_number(t_stack *stack)
{
    t_stack *temp = stack;
    int min_number = INT_MAX;
    while (temp)
    {
        if (temp->data < min_number)
        {
            min_number = temp->data;
        }
            
        temp = temp->next;
    }
    return min_number;
}

int find_max_number(t_stack *stack)
{ 
    t_stack *temp = stack;
    int max_number = INT_MIN;
    while (temp)
    {
        if (temp->data > max_number)
            max_number = temp->data;
        temp = temp->next;
    }
    return max_number;
}

t_stack *find_max_node(t_stack *stack)
{
    if (!stack)
        return NULL;
    t_stack *max_node = stack;
    t_stack *temp = stack;
    while (temp)
    {
        if (temp->data > max_node->data)
            max_node = temp;
        temp = temp->next;
    }
    return max_node;
}


int	ft_lstsize2(t_stack *lst)
{
	int	len;

	len = 0;
    t_stack *temp = lst;
	while (temp)
	{
		temp = temp->next;
		len++;
	}
	return (len);
}

void   rb_or_rrb_god(t_stack **stack, t_stack *selected)
{
    int top_movements = 0;
    top_movements = top_to_bottom(*stack, selected);

    if(top_movements <= ft_lstsize2(*stack) / 2)
    {
        while(selected != (*stack))
            rb(stack);
    }
    else 
    {
        while(selected != (*stack))
            rrb(stack);
    }
}

int find_max_number_smallest(int *smallest)
{
    int max = smallest[0];
    for (int i = 1; i < 20; i++)
    {
        if (smallest[i] > max)
            max = smallest[i];
    }
    return max;
}

int find_min_number_smallest(int *smallest)
{
    int min = smallest[0];
    for (int i = 1; i < 20; i++)
    {
        if (smallest[i] < min)
            min = smallest[i];
    }
    return min;
}

int get_index(t_stack *stack, int value)
{
    int index = 0;
    t_stack *current = stack;
    
    while (current != NULL)
    {
        if (current->data == value)
            return index;
        current = current->next;
        index++;
    }
    return index;
}

int get_index_bottom(t_stack *stack, int value)
{
    int index = 0;
    t_stack *current = get_last_node(stack);
    
    while (current)
    {
        if (current->data == value)
            return index;
        current = current->prev;
        index++;
    }
    return index + 1;
}

int top_to_bottom(t_stack *stack, t_stack *selected)
{
	int count = 0;
    t_stack *temp = stack;
    
	while (temp)
	{
        if (temp == selected)
            break ;
		temp = temp->next;
		count++;
	}
	return count;
}

int bottom_to_top(t_stack *stack, t_stack *selected)
{
	int count = 0;
    t_stack *temp = get_last_node(stack);

	while (temp)
	{
        if (temp == selected)
            break ;
		temp = temp->prev;
		count++;
	}
	return count + 1;
}

int rrb_short_path(t_stack *stack)
{
	int count = 0;
	int min = find_min_number(stack);
	while (stack && stack->data != min)
	{
		stack = stack->next;
		count++;
	}
	return count;
}

//Si el mínimo se encuentra más tarde(es decir, es mayor la longitud a la del máximo) que el máximo es mejor hacer rrb para conseguir el orden ascendiente