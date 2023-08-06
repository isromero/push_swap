/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isromero <isromero@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 11:58:51 by isromero          #+#    #+#             */
/*   Updated: 2023/08/06 17:28:48 by isromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_is_sorted(t_stack *stack_a)
{
	int		i;
	t_stack	*temp;

	temp = stack_a;
	i = 0;
	while ((temp)->next)
	{
		if ((temp)->data > (temp)->next->data)
			return (-1);
		(temp) = (temp)->next;
		i++;
	}
	return (0);
}

void	check_how_many_sort(int argc, t_stack **stack_a, t_stack **stack_b)
{
	if (argc == 3)
		sort_2(stack_a);
	else if (argc == 4)
		sort_3(stack_a);
	else if (argc == 5)
		sort_4(stack_a, stack_b);
	else if (argc == 6)
		sort_5(stack_a, stack_b);
	else if (argc == 101)
		sort_100(stack_a, stack_b);
	else if (argc == 501)
		sort_500(stack_a, stack_b);
	else
		sort_everything_with_dynamic_chunks_20(stack_a, stack_b);
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (argc < 2)
		exit(1);
	input_and_fill(argc, argv, &stack_a);
	if (check_is_sorted(stack_a) == -1)
		check_how_many_sort(argc, &stack_a, &stack_b);
	free_stack(&stack_a);
	return (0);
}
