/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ready_stacks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isromero <isromero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 18:48:56 by isromero          #+#    #+#             */
/*   Updated: 2023/08/03 19:51:12 by isromero         ###   ########.fr       */
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

void	only_numbers(int argc, char **argv)
{
	int	word;
	int	letter;

	word = 1;
	letter = 0;
	while (word < argc)
	{
		letter = 0;
		while (argv[word][letter] != '\0')
		{
			if (ft_isalpha(argv[word][letter]))
			{
				ft_putstr("Error\n");
				exit(1);
			}
			letter++;
		}
		word++;
	}
}

void	duplicated_numbers(int argc, char **argv)
{
	int	j;
	int	i;
	int	num_i;
	int	num_j;

	i = 1;
	while (i < argc)
	{
		num_i = ft_atoi(argv[i]);
		j = i + 1;
		while (j < argc)
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

int	input_and_fill(int argc, char **argv, t_stack **stack_a)
{
	int	i;
	int	stack_size;

	stack_size = 0;
	i = 1;
	only_numbers(argc, argv);
	duplicated_numbers(argc, argv);
	while (i < argc)
	{
		node_add_back(stack_a, ft_atoi(argv[i]));
		i++;
		stack_size++;
	}
	return (0);
}

void	print_stacks(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*node_a;
	t_stack	*node_b;

	node_a = *stack_a;
	node_b = *stack_b;
	while (node_a || node_b)
	{
		if (node_a)
		{
			printf("%d", node_a->data);
			node_a = node_a->next;
		}
		else
			printf("-");
		printf("\t");
		if (node_b)
		{
			printf("%d", node_b->data);
			node_b = node_b->next;
		}
		else
			printf("-");
		printf("\n");
	}
	printf("a\tb\n");
}
