/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isromero <isromero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 15:01:47 by isromero          #+#    #+#             */
/*   Updated: 2023/04/03 17:54:03 by isromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_ispace(char *str)
{
	int	i;

	i = 0;
	while(str[i] != '\0')
	{
		
		if (str[i] == ' ')
			return (0);
		i++;
	}
	return (1);
}

void    only_numbers(int argc, char **argv)
{
    int word;
    int letter;

    word = 1; //se empieza en argv[1]; que quiere decir después del nombre del programa
    letter = 0;
    while(word < argc)
    {
        while(argv[word][letter] != '\0')
        {
            if(ft_isalpha(argv[word][letter]))
            {
                ft_putstr("Error, there are letters\n");
                exit(1);
            }
            letter++;  
        }
        word++;
    }
}

void    duplicated_numbers(int argc, char **argv)
{
    int j;
    int i;
    int num_i;
    int num_j;

    i = 1;
    while(i < argc)
    {
        num_i = ft_atoi(argv[i]);
        j = i + 1;
        while(j < argc)
        {
            num_j = ft_atoi(argv[j]);
            if(num_i == num_j)
                {
                    ft_putstr("Duplicated number\n");
                    exit(1);
                }
            j++;
        }
        i++;
    }
}

int input_and_fill(int argc, char **argv, t_stack **stack_a, t_stack **stack_b)
{
    int i;

    i = 1;
    //only_numbers(argc, argv);
    duplicated_numbers(argc, argv);
    while(i < argc)
	{
		// if (!good_input(argc, argv))
		//     ft_putstr("error input\n");
		node_add_back(stack_a, ft_atoi(argv[i]));
		i++;
	}
    print_stacks(stack_a, stack_b);
	return (0);
}

// void    split single_character_int(int argc, char **argv)
// {
//     //push_swap "3 4 6 8 9 74 -56 +495" en distintos ints, que no coja solo el primero
// }