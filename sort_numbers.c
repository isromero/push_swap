/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_numbers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 22:51:03 by marvin            #+#    #+#             */
/*   Updated: 2023/03/26 22:51:03 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    sort_numbers(t_stack **stack_a, t_stack **stack_b)
{
	//Hacemos push to b de los dos primeros numeros sin checkear nada
	pb(stack_a, stack_b);
	pb(stack_a, stack_b);

    check_movements_and_pb(stack_a, stack_b);

    while(!is_stack_sorted(*stack_b))
        short_path_rb_or_rrb(stack_b);
    while(*stack_b != NULL)
        pa(stack_a, stack_b);

}

int calculate_moves(int num, t_stack *stack_b)
{
    int moves = 0;
    t_stack *current = stack_b;

    if (current == NULL || num < current->data) {
        return moves;
    }

    while (current != NULL && num < current->data)
    {
        moves++;
        current = current->prev;
    }
    return moves;
}

int find_min_moves(t_stack *stack_a, t_stack *stack_b)
{
    int min_moves = calculate_moves(stack_a->data, stack_b);
    t_stack *current = stack_a->next;

    while (current != NULL)
    {
        int moves = calculate_moves(current->data, stack_b);
        if (moves < min_moves)
            min_moves = moves;
        current = current->next;
    }
    return min_moves;
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

int find_max_number(t_stack *stack)
{
    int max_number = INT_MIN;
    while (stack)
    {
        if (stack->data > max_number)
            max_number = stack->data;
        stack = stack->next;
    }
    return max_number;
}

int find_min_number(t_stack *stack)
{
    int min_number = INT_MAX;
    while (stack)
    {
        if (stack->data < min_number)
            min_number = stack->data;
        stack = stack->next;
    }
    return min_number;
}


t_stack	*get_last_node(t_stack *stack)
{
	if (stack == NULL)
		return (NULL);
	while (stack->next != NULL)
		stack = stack->next;
	return (stack);
}

int is_stack_sorted(t_stack *stack)
{
    while (stack && stack->next)
    {
        if (stack->data < stack->next->data)
            return 0;
        stack = stack->next;
    }
    return 1;
}

int rb_short_path(t_stack *stack)
{
    int count = 0;
    int max = find_max_number(stack);
    while (stack && stack->data != max)
    {
        stack = stack->next;
        count++;
    }
    return count;
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

void    short_path_rb_or_rrb(t_stack **stack)
{
    if (rrb_short_path(*stack) <= rb_short_path(*stack))
        rrb(stack);
    else
        rb(stack);
}

//Si el mínimo se encuentra más tarde(es decir, es mayor la longitud a la del máximo) que el máximo es mejor hacer rrb para conseguir el orden ascendiente

void check_movements_and_pb(t_stack **stack_a, t_stack **stack_b)
{
    t_stack *current_a = NULL;
    t_stack *best_node = NULL;
    int moves;
    int min_moves = INT_MAX;
    int min_number = find_min_number(*stack_b);
    t_stack *last_node_b = get_last_node(*stack_b);
    
	while(*stack_a != NULL)
	{
	    current_a = *stack_a;
	    int min_moves = INT_MAX;
        while (current_a)
        {
            moves = find_min_moves(current_a, *stack_b);
            if (moves < min_moves)
            {
                min_moves = moves;
                best_node = current_a;
            }

            current_a = current_a->next;
        }
        
        if(best_node->data != (*stack_a)->data)
                short_path_rb_or_rrb(stack_a);
        if(best_node->data == (*stack_a)->data)
        {
            // Verificar si el nodo seleccionado es el número más grande de stack_b
            while ((*stack_b)->data != find_max_number(*stack_b))
                rb(stack_b);
            if (best_node->data > find_max_number(*stack_b) && find_max_number(*stack_b) == (*stack_b)->data)
                pb(stack_a, stack_b);
            //Ahora quiero la condición del número menor y quiero que sea menor que el primero y < que el ultimo por lo tanto sera el menor del stack b
       
		    if (best_node->data < (*stack_b)->data && best_node->data < get_last_node(*stack_b)->data && best_node->data < min_number)
            {

                pb(stack_a, stack_b);
                rb(stack_b);
            }
		    t_stack *current_b = *stack_b;
	        if (best_node->data > get_last_node(*stack_b)->data && best_node->data < (*stack_b)->data)
            {
                rb(stack_b);
                while (best_node->data < get_last_node(*stack_b)->data && best_node->data < (*stack_b)->data) //EL PROBLEMA DE RB SIN SENTIDO ESTÁ AQUÍ
                    rb(stack_b);
                if (best_node->data < get_last_node(*stack_b)->data && best_node->data > (*stack_b)->data)
                    pb(stack_a, stack_b);
            }
	    }
    }
}

