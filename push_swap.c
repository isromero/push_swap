/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 11:58:51 by isromero          #+#    #+#             */
/*   Updated: 2023/03/25 22:25:25 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int argc, char **argv)
{
	t_stack *stack_a;
	t_stack *stack_b;
	int i;
	
	stack_a = NULL;
	stack_b = NULL;
	i = 1;

	while(i < argc)
	{
		// if (!good_input(argc, argv))
		//     ft_putstr("error input\n");
		node_add_back(&stack_a, ft_atoi(argv[i]));
		i++;
	}
	node_add_back(&stack_b, 10);
	print_stacks(stack_a, stack_b);
	pb(&stack_a, &stack_b);
	pb(&stack_a, &stack_b);
	rrr(&stack_a, &stack_b);
	printf("\n");
	printf("Después:\n");
	print_stacks(stack_a, stack_b);
	return (0);
}

//testeando moves de stack a