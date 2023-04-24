/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   try.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isromero <isromero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 22:51:03 by marvin            #+#    #+#             */
/*   Updated: 2023/04/20 22:14:16 by isromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

#include "push_swap.h"

int    *save_20_smallest_chunk(t_stack *stack_a)
{
	int *smallest = malloc(sizeof(int) * 20);
	int i;
	int j;
	t_stack *temp = stack_a;

	// Guardamos los primeros 20 elementos en el array smallest
	for (i = 0; i < 20 && temp; i++)
	{
		smallest[i] = temp->data;
		temp = temp->next;
	}

	// Ordenamos el array smallest con el algoritmo de burbuja
	for (i = 0; i < 20; i++)
	{
		for (j = 0; j < 20 - i; j++)
		{
			if (smallest[j] < smallest[j + 1])
			{
				int tmp = smallest[j];
				smallest[j] = smallest[j + 1];
				smallest[j + 1] = tmp;
			}
		}
	}

	// Recorremos el resto del stack y actualizamos el array smallest si encontramos un elemento menor
	while (temp)
	{
		for (i = 20; i >= 0; i--)
		{
			if (temp->data < smallest[i])
			{
				// Desplazamos los elementos mayores hacia la derecha para hacer espacio para el nuevo elemento
				for (j = 0; j < i; j++)
				{
					smallest[j] = smallest[j + 1];
				}
				// Insertamos el nuevo elemento en la posición correcta
				smallest[i] = temp->data;
				break ;
			}
		}
		temp = temp->next;
	}
	return smallest;
}


void sort_100(t_stack **stack_a, t_stack **stack_b)
{
	int i;
	int	j;
	int	*smallest = save_20_smallest_chunk(*stack_a);
	i = 0;
    j = 0;

	while (i < 5) // 
	{
		j = 0;
		int	*smallest = save_20_smallest_chunk(*stack_a);
		while(j < 20)
		{
			top_and_bottom_plus_detector_smallest(stack_a, stack_b, smallest);
			print_stacks(stack_a, stack_b);
			j++;
		}
		free(smallest);
		i++;
		if (ft_lstsize2(*stack_b) == 20)
			break ;
	}
    if (ft_lstsize2(*stack_b) == 100)
    {
        while(!is_descending_sorted(*stack_b))
            rb_or_rrb_god(stack_b, find_max_node(*stack_b));
        if(is_descending_sorted(*stack_b))
        {
            while(*stack_b != NULL)
                pa(stack_a, stack_b);
        }
    }
	//print_stacks(stack_a, stack_b);
}


void top_and_bottom_plus_detector_smallest(t_stack **stack_a, t_stack **stack_b, int *smallest)
{
	
	t_stack *current_a = *stack_a;
	t_stack	*last = get_last_node(*stack_a);
	int top_movements = 0;
	int bottom_movements = 0;
	while(current_a != NULL && !(current_a->data >= smallest[19] && current_a->data <= smallest[0]))
		current_a = current_a->next;
	while (last != NULL && !(last->data >= smallest[19] && last->data <= smallest[0]))
    	last = last->prev;
	if(last && current_a && last->data >= smallest[19] && last->data <= smallest[0] && current_a && current_a->data >= smallest[19] && current_a->data <= smallest[0])
	{
		printf("current selected: %d\n", current_a->data);
		printf("last selected: %d\n", last->data);
		bottom_movements = bottom_to_top(*stack_a, last);
		top_movements = top_to_bottom(*stack_a, current_a);
		printf("current movements: %d\n", top_movements);
		printf("last movements: %d\n", bottom_movements);
	}
	if(last->data >= smallest[19] && last->data <= smallest[0] && current_a && current_a->data >= smallest[19] && current_a->data <= smallest[0])
		movements_checker_to_push_b(stack_a, stack_b, top_movements, bottom_movements);
}

void	movements_checker_to_push_b(t_stack **stack_a, t_stack **stack_b, int top_movements, int bottom_movements)
{
	int	i;

    if (top_movements <= bottom_movements)
    {
        i = 0;
        while (i < top_movements)
        {
            ra(stack_a);
            i++;
        }
    }
    else
    {
        i = 0;
        while (i < bottom_movements)
        {
            rra(stack_a);
            i++;
        }
    }
    check_position_to_push_b(stack_a, stack_b);
}


void    check_position_to_push_b(t_stack **stack_a, t_stack **stack_b)
{
		if(*stack_b == NULL)
			pb(stack_a, stack_b);
		else if((*stack_a)->data < (*stack_b)->data && ft_lstsize2(*stack_b) == 1)
			pb(stack_a, stack_b);
		else if((*stack_a)->data > (*stack_b)->data && ft_lstsize2(*stack_b) == 1)
			pb(stack_a, stack_b);
        else if((*stack_a)->data >= find_max_number(*stack_b))
        {
                while(!(find_max_number(*stack_b) == (*stack_b)->data && find_min_number(*stack_b) == get_last_node(*stack_b)->data))
                    rb_or_rrb_god(stack_b, find_max_node(*stack_b));
                pb(stack_a, stack_b);
        }
        else if((*stack_a)->data <= find_min_number(*stack_b))
        {
                while(!(find_min_number(*stack_b) == get_last_node(*stack_b)->data && find_max_number(*stack_b) == (*stack_b)->data))
                    rb_or_rrb_god(stack_b, find_max_node(*stack_b));
                pb(stack_a, stack_b);
        }
		else if ((*stack_a)->data < get_last_node(*stack_b)->data && (*stack_a)->data > (*stack_b)->data)
				pb(stack_a, stack_b);
		else
		{
			t_stack *temp_b = *stack_b;
			t_stack *temp_save = NULL;
			while(temp_b)
			{
				if((*stack_a)->data < temp_b->data && (*stack_a)->data > temp_b->next->data)
				{
					temp_save = temp_b->next;
					break ;
				}
				temp_b = temp_b->next;
			}
			if(temp_save != NULL)
				rb_or_rrb_god(stack_b, temp_save);
			if ((*stack_a)->data < get_last_node(*stack_b)->data && (*stack_a)->data > (*stack_b)->data)
				pb(stack_a, stack_b);
		}	
}
