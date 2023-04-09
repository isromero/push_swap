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

void    sort_100(t_stack **stack_a, t_stack **stack_b)
{
    
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


