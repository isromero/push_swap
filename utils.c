/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isromero <isromero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 21:30:47 by isromero          #+#    #+#             */
/*   Updated: 2023/08/04 20:13:32 by isromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	stack_size(t_stack *stack)
{
	int		len;
	t_stack	*temp;

	len = 0;
	temp = stack;
	while (temp)
	{
		temp = temp->next;
		len++;
	}
	return (len);
}

int	is_sorted(t_stack *stack)
{
	t_stack	*temp;

	temp = stack;
	while (temp && temp->next)
	{
		if (temp->data > temp->next->data)
			return (0);
		temp = temp->next;
	}
	return (1);
}

int	is_descending_sorted(t_stack *stack)
{
	t_stack	*temp;

	temp = stack;
	while (temp && temp->next)
	{
		if (temp->data < temp->next->data)
			return (0);
		temp = temp->next;
	}
	return (1);
}

t_stack	*find_max_node(t_stack *stack)
{
	t_stack	*max_node;
	t_stack	*temp;

	if (!stack)
		return (NULL);
	max_node = stack;
	temp = stack;
	while (temp)
	{
		if (temp->data > max_node->data)
			max_node = temp;
		temp = temp->next;
	}
	return (max_node);
}

t_stack	*find_min_node(t_stack *stack)
{
	t_stack	*min_node;
	t_stack	*temp;

	if (!stack)
		return (NULL);
	min_node = stack;
	temp = stack;
	while (temp)
	{
		if (temp->data < min_node->data)
			min_node = temp;
		temp = temp->next;
	}
	return (min_node);
}
