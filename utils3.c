/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isromero <isromero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 20:14:24 by isromero          #+#    #+#             */
/*   Updated: 2023/08/04 20:14:24 by isromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_stack(t_stack **stack_a)
{
	t_stack	*temp;

	while (*stack_a != NULL)
	{
		temp = *stack_a;
		*stack_a = (*stack_a)->next;
		free(temp);
	}
}

bool	contains_only_spaces(const char *str)
{
	while (*str != '\0')
	{
		if (*str != ' ')
			return (false);
		str++;
	}
	return (true);
}
