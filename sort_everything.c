/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_everything.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isromero <isromero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 10:26:58 by isromero          #+#    #+#             */
/*   Updated: 2023/08/04 20:19:10 by isromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_everything_with_dynamic_chunks_20(t_stack **stack_a,
		t_stack **stack_b)
{
	int	i;
	int	*smallest;

	i = 0;
	while (stack_size(*stack_a) != 0)
	{
		smallest = save_20_smallest_chunk(*stack_a);
		top_and_bottom_plus_detector_smallest_20(stack_a, stack_b, smallest);
		free(smallest);
		i++;
	}
	while (!is_descending_sorted(*stack_b))
		rb_or_rrb(stack_b, find_max_node(*stack_b));
	while (*stack_b != NULL)
		pa(stack_a, stack_b);
}
