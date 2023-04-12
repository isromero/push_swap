/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isromero <isromero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 21:30:47 by isromero          #+#    #+#             */
/*   Updated: 2023/04/12 21:42:06 by isromero         ###   ########.fr       */
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

void   rb_or_rrb(t_stack **stack_b)
{
    int size = ft_lstsize2(*stack_b);
    int index = get_index(*stack_b, (*stack_b)->data);

    size /= 2;
    if(index < size)
        rb(stack_b);
    if(index > size)
        rrb(stack_b);
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

int top_to_bottom(t_stack *stack, int *selected)
{
    t_stack *temp = stack;
	int count = 0;
	int max = get_last_node(stack)->data;
	while (temp && temp->data != max)
	{
        if (temp->data == *selected)
            break ;
		temp = temp->next;
		count++;
	}
	return count;
}

int bottom_to_top(t_stack *stack, t_stack *last, int *selected)
{
	int count = 0;
	int min = stack->data;
	while (last && last->data != min)
	{
        if (last->data == *selected)
            break ;
		last = last->prev;
		count++;
	}
	return count; //Esto PUEDE QUE se debe a que tengo que contar también el último rra para ponerlo encima, y no solo para llegar al número como con ra
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