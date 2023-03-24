/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isromero <isromero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 15:01:47 by isromero          #+#    #+#             */
/*   Updated: 2023/03/24 19:15:10 by isromero         ###   ########.fr       */
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

int	good_input(int argc, char **argv)
{
    only_numbers(argc, argv);
	//int	i;
    //int num;
    //num = ft_atoi(argv[i]);
            // if (num == -1) //(no puedo utilizar porque -1 es un valor válido... esto arregla por ejemplo ./push_swap 54867543867438 3 o ./push_swap "214748364748385 28 47 29" Revisar si debería dar error -2147483647765 4 5?????
            // {
            //     ft_putstr("error\n");
            //     exit(1);
            // }
	return (0);
}

// void    split single_character_int(int argc, char **argv)
// {
//     //push_swap "3 4 6 8 9 74 -56 +495" en distintos ints, que no coja solo el primero
// }