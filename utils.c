/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isromero <isromero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 21:30:47 by isromero          #+#    #+#             */
/*   Updated: 2023/04/20 10:56:28 by isromero         ###   ########.fr       */
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
    t_stack *temp = stack;
	while (temp->next != NULL)
		temp = temp->next;
	return (temp);
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
	while (lst)
	{
		lst = lst->next;
		len++;
	}
	return (len);
}


// void rb_or_rrb(t_stack **stack_b, int *smallest_pushed)
// {
//     int ra_movements = 0;
//     int rra_movements = 0;
//     int i, j;

//     // Calcular movimientos para ra
//     i = 0;
//     while (smallest_pushed[i])
//     {
//         j = i + 1;
//         while (smallest_pushed[j])
//         {
//             if (!((*stack_b)->data < smallest_pushed[i] && (*stack_b)->data > smallest_pushed[j]))
//                 ra_movements++;
//             j++;
//         }
//         i++;
//     }

//     // Calcular movimientos para rra
//     i = 0;
//     while (smallest_pushed[i])
//     {
//         j = i + 1;
//         while (smallest_pushed[j])
//         {
//             if (!((*stack_b)->data < smallest_pushed[j] && (*stack_b)->data > smallest_pushed[i]))
//                 rra_movements++;
//             j++;
//         }
//         i++;
//     }
//     // Elegir acción
//     if (ra_movements <= rra_movements)
//         rb(stack_b);
//     else
//         rrb(stack_b);
// }

void rb_or_rrb (t_stack **stack_b)
{
    int i = 0;
    int j = 0;
    t_stack *temp = *stack_b;
    while (temp != NULL)
    {
        if (temp->data < (*stack_b)->data)
            i++;
        else
            j++;
        temp = temp->next;
    }
    if (i < j)
    {
        while (i > 0)
        {
            rb(stack_b);
            i--;
        }
    }
    else
    {
        while (j > 0)
        {
            rrb(stack_b);
            j--;
        }
    }
}

void   rb_or_rrb_god(t_stack **stack_b, t_stack *selected)
{
    int top_movements = 0;
    int bottom_movements = 0;
    printf("selected: %d\n", selected->data);
    top_movements = top_to_bottom(*stack_b, selected);
    printf("top: %d\n", top_movements);
    bottom_movements = bottom_to_top(*stack_b, selected);
    printf("bottom: %d\n", bottom_movements);
    
    
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
    t_stack *temp = stack;
	while (temp && temp->data != get_last_node(temp)->data)
	{
        if (temp->data == current_a->data)
            break ;
		temp = temp->next;
		count++;
	}
	return count;
}

int bottom_to_top2(t_stack *stack, t_stack *last)
{
	int count = 0;
    t_stack *temp = get_last_node(stack);

	while (temp && temp->data != stack->data)
	{
        //printf("%d\n", temp->data);
        //printf("%d\n", last->data);
        if (temp->data == last->data)
            break ;
		temp = temp->prev;
		count++;
	}
	return count; //Esto PUEDE QUE tenga que poner + 1 y se debe a que tengo que contar también el último rra para ponerlo encima, y no solo para llegar al número como con ra
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