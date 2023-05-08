/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isromero <isromero@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 21:30:47 by isromero          #+#    #+#             */
/*   Updated: 2023/05/08 14:58:11 by isromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	stack_size(t_stack *stack)
{
	int	len;

	len = 0;
    t_stack *temp = stack;
	while (temp)
	{
		temp = temp->next;
		len++;
	}
	return (len);
}

int is_sorted(t_stack *stack)
{
    t_stack *temp = stack;
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

t_stack *find_min_node(t_stack *stack)
{
    if (!stack)
        return NULL;
    t_stack *min_node = stack;
    t_stack *temp = stack;
    while (temp)
    {
        if (temp->data < min_node->data)
            min_node = temp;
        temp = temp->next;
    }
    return min_node;
}
