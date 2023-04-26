/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_500.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isromero <isromero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 10:27:00 by isromero          #+#    #+#             */
/*   Updated: 2023/04/26 10:27:55 by isromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int    *save_50_smallest_chunk(t_stack *stack_a)
{
	int *smallest = malloc(sizeof(int) * 50);
	int i;
	int j;
	t_stack *temp = stack_a;

	// Guardamos los primeros 20 elementos en el array smallest
	for (i = 0; i < 50 && temp; i++)
	{
		smallest[i] = temp->data;
		temp = temp->next;
	}

	// Ordenamos el array smallest con el algoritmo de burbuja
	for (i = 0; i < 49; i++)
	{
		for (j = 0; j < 49 - i; j++)
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
		for (i = 49; i >= 0; i--)
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

void sort_500(t_stack **stack_a, t_stack **stack_b)
{
	int i;
	int	j;
	int	*smallest = save_50_smallest_chunk(*stack_a);
	i = 0;
	j = 0;

	while (i < 10) // 
	{
		j = 0;
		int	*smallest = save_50_smallest_chunk(*stack_a);
		while(j < 50)
		{
			top_and_bottom_plus_detector_smallest_50(stack_a, stack_b, smallest);
			j++;
		}
		free(smallest);
		i++;
		if (stack_size(*stack_b) == 500)
			break ;
	}
	if (stack_size(*stack_b) == 500)
	{
		while(!is_descending_sorted(*stack_b))
			rb_or_rrb(stack_b, find_max_node(*stack_b));
		if(is_descending_sorted(*stack_b))
		{
			while(*stack_b != NULL)
				pa(stack_a, stack_b);
		}
	}
}

void top_and_bottom_plus_detector_smallest_50(t_stack **stack_a, t_stack **stack_b, int *smallest)
{
	
	t_stack *current_a = *stack_a;
	t_stack	*last = get_last_node(*stack_a);
	int top_movements = 0;
	int bottom_movements = 0;
	while(!(current_a->data >= smallest[49] && current_a->data <= smallest[0]))
		current_a = current_a->next;
	while (!(last->data >= smallest[49] && last->data <= smallest[0]))
		last = last->prev;
	if(last->data >= smallest[49] && last->data <= smallest[0] && current_a && current_a->data >= smallest[49] && current_a->data <= smallest[0])
	{
		last->bottom_a_movements = bottom_to_top(*stack_a, last);
		current_a->top_a_movements = top_to_bottom(*stack_a, current_a);
	}
	if(*stack_b != NULL && stack_size(*stack_b) > 2) 
	{
		if(current_a->data >= find_max_node(*stack_b)->data || current_a->data <= find_min_node(*stack_b)->data)
			current_a->top_b_movements = top_to_bottom(*stack_b, find_max_node(*stack_b));
		else if(last->data >= find_max_node(*stack_b)->data || last->data <= find_min_node(*stack_b)->data)
			last->bottom_b_movements = bottom_to_top(*stack_b, find_max_node(*stack_b));
		else if(!(current_a->data >= find_max_node(*stack_b)->data || current_a->data <= find_min_node(*stack_b)->data))
		{
			t_stack *temp_b_current = *stack_b;
			t_stack *temp_save_current = NULL;
			while(temp_b_current)
			{
				if(temp_b_current->next != NULL && current_a->data < temp_b_current->data && current_a->data > temp_b_current->next->data)
				{
					temp_save_current = temp_b_current->next;
					break ;
				}
				temp_b_current = temp_b_current->next;
			}
			current_a->top_b_movements = top_to_bottom(*stack_b, temp_save_current);
		}

		else if(!(last->data >= find_max_node(*stack_b)->data || last->data <= find_min_node(*stack_b)->data))
		{
			t_stack *temp_b_last = *stack_b;
			t_stack *temp_save_last = NULL;
			while(temp_b_last)
			{
				if(temp_b_last->next != NULL && last->data < temp_b_last->data && last->data > temp_b_last->next->data)
				{
					temp_save_last = temp_b_last->next;
					break ;
				}
				temp_b_last = temp_b_last->next;
			}
			last->bottom_b_movements = bottom_to_top(*stack_b, temp_save_last);
		}
	}
	if(last->data >= smallest[49] && last->data <= smallest[0] && current_a && current_a->data >= smallest[49] && current_a->data <= smallest[0])
		movements_checker_to_push_b(stack_a, stack_b, current_a, last);
}