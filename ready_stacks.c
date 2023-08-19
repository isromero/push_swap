/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ready_stacks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isromero <isromero@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 18:48:56 by isromero          #+#    #+#             */
/*   Updated: 2023/08/19 12:25:37 by isromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	node_add_back(t_stack **lst, int data)
{
	t_stack	*new_node;
	t_stack	*last_node;

	new_node = malloc(sizeof(t_stack));
	if (!new_node)
		return ;
	new_node->data = data;
	new_node->next = NULL;
	if (!*lst)
	{
		new_node->prev = NULL;
		*lst = new_node;
	}
	else
	{
		last_node = *lst;
		while (last_node->next)
			last_node = last_node->next;
		last_node->next = new_node;
		new_node->prev = last_node;
	}
}

void	only_numbers(char **argv, int word)
{
	int	letter;

	letter = 0;
	while (argv[word])
	{
		letter = 0;
		while (argv[word][letter] != '\0')
		{
			if (!(argv[word][letter] >= '0' && argv[word][letter] <= '9')
			&& !(argv[word][letter + 1] >= '0'
			&& argv[word][letter + 1] <= '9'))
			{
				ft_putstr("Error\n");
				exit(1);
			}
			letter++;
		}
		word++;
	}
}

void	duplicated_numbers(char **argv, int i)
{
	int	j;
	int	num_i;
	int	num_j;

	while (argv[i])
	{
		num_i = ft_atoi(argv[i]);
		j = i + 1;
		while (argv[j])
		{
			num_j = ft_atoi(argv[j]);
			if (num_i == num_j)
			{
				ft_putstr("Error\n");
				exit(1);
			}
			j++;
		}
		i++;
	}
}

void	one_argument_input(char **argv, t_stack **stack_a)
{
	int		i;
	char	**splitted;

	splitted = ft_split(argv[1], ' ');
	only_numbers(splitted, 0);
	duplicated_numbers(splitted, 0);
	i = 0;
	while (splitted[i])
	{
		node_add_back(stack_a, ft_atoi(splitted[i]));
		(*stack_a)->how_many_one_arg++;
		i++;
	}
	i = 0;
	while (splitted[i])
		free(splitted[i++]);
	free(splitted);
}

int	input_and_fill(int argc, char **argv, t_stack **stack_a)
{
	int	i;

	i = 1;
	if (argc == 2)
		one_argument_input(argv, stack_a);
	else if (argc != 2)
	{
		only_numbers(argv, 1);
		duplicated_numbers(argv, 1);
		while (argv[i])
		{
			node_add_back(stack_a, ft_atoi(argv[i]));
			i++;
		}
	}
	return (0);
}
