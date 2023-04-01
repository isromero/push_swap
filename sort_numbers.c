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

	while (*stack_a != NULL)
    {
        if (*stack_a == NULL)
            break;
        check_movements_and_pb(stack_a, stack_b);
    }
}

int calculate_moves(int num, t_stack *stack_b)
{
    int moves = 0;
    t_stack *current = stack_b;

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


bool is_stack_b_sorted(t_stack *stack_b)
{
	t_stack *current = stack_b;

	while (current->next != NULL)
	{
		if (current->data < current->next->data)
			return false;
		current = current->next;
	}
	return true;
}

t_stack	*get_last_node(t_stack *stack)
{
	if (stack == NULL)
		return (NULL);
	while (stack->next != NULL)
		stack = stack->next;
	return (stack);
}

void check_movements_and_pb(t_stack **stack_a, t_stack **stack_b)
{
    t_stack *current_a = NULL;
    t_stack *best_node = NULL;
    int moves;
    int min_moves = INT_MAX;

    current_a = *stack_a;
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
    while (best_node != NULL)
    {
        // Verificar si el nodo seleccionado es el número más grande de stack_b
        if (best_node->data > (*stack_b)->data)
        {
			printf("que pasa chavalesss\n");
			while (*stack_b != NULL && (*stack_b)->next != NULL && (*stack_b)->data != find_max_number(*stack_b))
                rrb(stack_b);
            pb(stack_a, stack_b);
        }
		//Ahora quiero la condición del número menor y quiero que sea menor que el primero y < que el ultimo por lo tanto sera el menor del stack b
		int min_number = find_min_number(*stack_b);
		t_stack *last_node_b = get_last_node(*stack_b);
		if (best_node->data <  (*stack_b)->data)
   			pb(stack_a, stack_b);
		if (best_node->data < last_node_b->data || (best_node->data < (*stack_b)->data && last_node_b->data == min_number))
    		rrb(stack_b);
		pb(stack_a, stack_b);
    }
}

