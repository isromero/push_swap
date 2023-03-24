/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isromero <isromero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 11:58:51 by isromero          #+#    #+#             */
/*   Updated: 2023/03/24 22:45:59 by isromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int argc, char **argv)
{
    t_stack *stack_a;
    //t_stack *stack_b;
    int i;
    
    stack_a = NULL;
    //stack_b = NULL;
    i = 1;
    if (argc <= 1)
    {
        ft_putstr("Not enough parameters\n"); //No hay que mostrar nada??
        exit(1);
    }
    while(i < argc)
    {
        // if (!good_input(argc, argv))
        //     ft_putstr("error input\n");
        node_add_back(&stack_a, ft_atoi(argv[i]));
        i++;
    }
    print_stack(stack_a);
    sa(&stack_a);
    printf("\n");
    print_stack(stack_a);

    
    i = 1;
    while(i < argc)
    {
        // if (!good_input(argc, argv))
        //     ft_putstr("error input\n");
        node_add_back(&stack_a, ft_atoi(argv[i]));
        i++;
    }
    print_stack(stack_a);
	return (0);
}

//testeando moves de stack a