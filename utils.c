/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isromero <isromero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 21:30:47 by isromero          #+#    #+#             */
/*   Updated: 2023/04/18 10:42:18 by isromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int is_sorted(t_stack *stack)
{
    while (stack && stack->next)
    {
        if (stack->data > stack->next->data)
            return 0;
        stack = stack->next;
    }
    return 1;
}

int is_descending_sorted(t_stack *stack)
{
    while (stack && stack->next)
    {
        if (stack->data < stack->next->data)
            return 0;
        stack = stack->next;
    }
    return 1;
}

t_stack	*get_last_node(t_stack *stack)
{
	if (!stack)
		return (NULL);
	while (stack->next != NULL)
		stack = stack->next;
	return (stack);
}

int find_min_number(t_stack *stack)
{
    if(!stack)
        return 0;
    int min_number = INT_MAX;
    while (stack)
    {
        if (stack->data < min_number)
        {
            min_number = stack->data;
        }
            
        stack = stack->next;
    }
    return min_number;
}

int find_max_number(t_stack *stack)
{    if(!stack)
        return 0;
    int max_number = INT_MIN;
    while (stack)
    {
        if (stack->data > max_number)
            max_number = stack->data;
        stack = stack->next;
    }
    return max_number;
}

t_stack *find_max_node(t_stack *stack)
{
    if (!stack)
        return NULL;
    t_stack *max_node = stack;
    while (stack)
    {
        if (stack->data > max_node->data)
            max_node = stack;
        stack = stack->next;
    }
    return max_node;
}


int	ft_lstsize2(t_stack *lst)
{
	int	len;

	len = 0;
	while (lst)
	{
		lst = lst->next;
		len++;
	}
	return (len);
}

void   rb_or_rrb(t_stack **stack_b, int movements)
{
    if(movements + 1 > (ft_lstsize2(*stack_b) / 2))
        rrb(stack_b);
}

void   rb_or_rrb_god(t_stack **stack_b, t_stack *selected)
{
    
    int top_movements = top_to_bottom(*stack_b, selected);
    int bottom_movements = bottom_to_top(get_last_node(*stack_b), selected);
    
    if(top_movements > bottom_movements)
    {
        while(selected != (*stack_b))
            rrb(stack_b);
    }
    else if(top_movements < bottom_movements)
    {
        while(selected != (*stack_b))
            rb(stack_b);
    }
    else
    {
        while(selected != (*stack_b))
            rb(stack_b);
    }
        
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

int   minimum_rotate_movements(t_stack *stack_a)
{
    int size = ft_lstsize2(stack_a);
    int index = get_index(stack_a, stack_a->data);
    int movements;

    size /= 2;
    movements = 0;
    if(index < size)
        movements = index;
    if(index > size)
        movements = size + (size - index);
    return (movements);
}

int top_to_bottom(t_stack *stack, t_stack *current_a)
{
	int count = 0;
	int max = get_last_node(stack)->data;
	while (stack && stack->data != max)
	{
        if (stack->data == current_a->data)
            break ;
		stack = stack->next;
		count++;
	}
	return count;
}

int bottom_to_top(t_stack *stack, t_stack *last)
{
	int count = 0;
    t_stack *top = stack;
    t_stack *temp = stack;
	int min = top->data;
    
    
	while (temp && temp->data != min)
	{
        if (temp->data == last->data)
            break ;
		temp = temp->prev;
		count++;
	}
	return count + 1; //Esto PUEDE QUE se debe a que tengo que contar también el último rra para ponerlo encima, y no solo para llegar al número como con ra
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