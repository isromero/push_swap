/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isromero <isromero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 11:58:51 by isromero          #+#    #+#             */
/*   Updated: 2023/04/03 22:16:03 by isromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int argc, char **argv)
{
	t_stack *stack_a;
	t_stack	*stack_b;

	
	stack_a = NULL;
	stack_b = NULL;

	if (argc < 2)
	{
		ft_putstr("Not enough parameters\n");
		exit(1);
	}
	input_and_fill(argc, argv, &stack_a, &stack_b);
	if(argc == 3)
	{
		sort_2(&stack_a);
		printf("\n");
		print_stacks(&stack_a, &stack_b);
	}
	if(argc == 4)
	{
		sort_3(&stack_a);
		printf("\n");
		print_stacks(&stack_a, &stack_b);
	}
	if(argc > 4)
	{
		sort_numbers(&stack_a, &stack_b);
		printf("\n");
		print_stacks(&stack_a, &stack_b);
	}

	
	return (0);
}

