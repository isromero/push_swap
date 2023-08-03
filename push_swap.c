/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isromero <isromero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 11:58:51 by isromero          #+#    #+#             */
/*   Updated: 2023/08/03 19:47:02 by isromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Añadir checkeo de si hay números ordenados no hacer nada */

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
	check_how_many_sort(argc, &stack_a, &stack_b);
	/* print_stacks(&stack_a, &stack_b); */
	free_stack(&stack_a);
	return (0);
}
