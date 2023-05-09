/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isromero <isromero@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 08:44:28 by isromero          #+#    #+#             */
/*   Updated: 2023/05/09 08:44:28 by isromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_stack(t_stack **stack_a)
{
	t_stack *temp;
	while(*stack_a != NULL)
    {
		temp = *stack_a;
        *stack_a = (*stack_a)->next;
        free(temp);
    }
}