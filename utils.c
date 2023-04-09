/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isromero <isromero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 21:30:47 by isromero          #+#    #+#             */
/*   Updated: 2023/04/08 18:22:13 by isromero         ###   ########.fr       */
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