/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_numbers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 22:51:03 by marvin            #+#    #+#             */
/*   Updated: 2023/03/26 22:51:03 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	for (i = 0; i < 19; i++)
	{
		for (j = 0; j < 19 - i; j++)
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
		for (i = 19; i >= 0; i--)
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
	printf("Esto es smallest: ");
	for (int i = 0; i < 20; i++)
		printf("%d ", smallest[i]);
	printf("\n");
	t_stack *current_a = *stack_a;
	t_stack *current_a_last = get_last_node(*stack_a);

	for (i = 0; i < 100; i++) // 
	{
		int	*smallest = save_20_smallest_chunk(*stack_a);
		j = 0;
		while(j < 20)
		{
			current_a = *stack_a;
			current_a_last = get_last_node(*stack_a);
			top_and_bottom_plus_detector_smallest(stack_a, stack_b, current_a, current_a_last, smallest);
			print_stacks(stack_a, stack_b);
			j++;
            if(j == 20)
            {
                while(!is_descending_sorted(*stack_b))
			        rb_or_rrb(stack_b);
            }
		}
		free(smallest);
		if (ft_lstsize2(*stack_b) == 100)
			break ;
	}
    //ERROR HACIENDO RB RRB SEG FAULT AL PONER EL NUMERO 100, HAY QUE ORDENAR DE 20 EN 20 Y LUEGO LOS 100 
    while(!is_descending_sorted(*stack_b))
		rb_or_rrb(stack_b);
	if(is_descending_sorted(*stack_b) && ft_lstsize2(*stack_b) == 100)
	{
		while(*stack_b != NULL)
			pa(stack_a, stack_b);
	}
	
}


void top_and_bottom_plus_detector_smallest(t_stack **stack_a, t_stack **stack_b, t_stack *current_a, t_stack *last, int *smallest)
{
	t_stack *temp = *stack_a;
	int top_movements = 0;
	int bottom_movements = 0;
	//t_stack *top_node = NULL;
	//t_stack *bottom_node = NULL;

	while(!(current_a->data >= smallest[19] && current_a->data <= smallest[0]))
		current_a = current_a->next;
	while (!(last->data >= smallest[19] && last->data <= smallest[0]))
		last = last->prev;
	if (current_a->data >= smallest[19] && current_a->data <= smallest[0])
	{
		//top_node = current_a;
		top_movements = top_to_bottom(temp, current_a);
		current_a->top_movements = top_movements;
	}
	if(last->data >= smallest[19] && last->data <= smallest[0])
	{
		//bottom_node = last;
		bottom_movements = bottom_to_top(temp, last);
		last->bottom_movements = bottom_movements;
	}
	if(last->data >= smallest[19] && last->data <= smallest[0] && current_a->data >= smallest[19] && current_a->data <= smallest[0])
		movements_checker_to_push_b(stack_a, stack_b, current_a, last, smallest);
}

void	movements_checker_to_push_b(t_stack **stack_a, t_stack **stack_b, t_stack *top_node, t_stack *bottom_node, int *smallest)
{
	if (top_node != NULL && bottom_node != NULL)
	{
		if (top_node->top_movements < bottom_node->bottom_movements)
		{
			while (top_node != *stack_a)
				ra(stack_a);
			if(top_node == *stack_a)
				check_position_to_push_b(stack_a, stack_b, top_node, bottom_node, smallest);
		}
	
		else if(top_node->top_movements > bottom_node->bottom_movements)
		{
			while (bottom_node != *stack_a)
				rra(stack_a);
			if(bottom_node == *stack_a)
				check_position_to_push_b(stack_a, stack_b, top_node, bottom_node, smallest);
		}
		else if(top_node->top_movements == bottom_node->bottom_movements)
		{
			while (top_node != *stack_a)
				ra(stack_a);
			while(bottom_node != *stack_a)
				rra(stack_a);
			if(top_node == *stack_a)
				check_position_to_push_b(stack_a, stack_b, top_node, bottom_node, smallest);
			if(bottom_node == *stack_a)
				check_position_to_push_b(stack_a, stack_b, top_node, bottom_node, smallest);
		}
		top_node = NULL;
		bottom_node = NULL;
	}
}


void    check_position_to_push_b(t_stack **stack_a, t_stack **stack_b, t_stack *current_a, t_stack *last, int *smallest)
{
	int i;
	int j;
	int	i2;
	int	j2;
	int	pushed;

	i = 0;
	j = 1;
	i2 = 0;
	j2 = 1;
	pushed = 0;
	int	movements = 0;
	int	h = 0;
	int	movements2 = 0;
	int	h2 = 0;
	t_stack *temp_b = *stack_b;
	int *smallest_pushed = malloc(sizeof(int) * 20);
	while(temp_b != NULL)
	{
		smallest_pushed[pushed] = temp_b->data;
		temp_b = temp_b->next;
		pushed++;
	}
	if (current_a == *stack_a)
	{
		if(*stack_b == NULL)
			pb(stack_a, stack_b);
		else if(current_a->data < (*stack_b)->data && ft_lstsize2(*stack_b) == 1)
		{
			pb(stack_a, stack_b);
			rb(stack_b);
		}
		else if(current_a->data > (*stack_b)->data && ft_lstsize2(*stack_b) == 1)
			pb(stack_a, stack_b);
		else if(current_a->data > (*stack_b)->data && current_a->data >= find_max_number(*stack_b) && (*stack_b)->data == find_max_number(*stack_b))
			pb(stack_a, stack_b); 
		else if(current_a->data < get_last_node(*stack_b)->data && current_a->data <= find_min_number(*stack_b) && get_last_node(*stack_b)->data == find_min_number(*stack_b))
		{
			pb(stack_a, stack_b);
			rb(stack_b);
		}
		else
		{
			while(smallest_pushed[i])
			{
				while(smallest_pushed[j])
				{
					if(!(current_a->data < smallest_pushed[i] && current_a->data > smallest_pushed[j]))
						movements++;
					while (h < movements + 1)
					{
						rb_or_rrb(stack_b);
						h++;
					}
					if (current_a->data < get_last_node(*stack_b)->data && current_a->data > (*stack_b)->data)
						pb(stack_a, stack_b);
					j++;
				}
				i++;
			}
		}
	}
		if(last == *stack_a)
		{
			if(*stack_b == NULL)
				pb(stack_a, stack_b);
			else if(last->data < (*stack_b)->data && ft_lstsize2(*stack_b) == 1)
			{
				pb(stack_a, stack_b);
				rb(stack_b);
			}
			else if(last->data > (*stack_b)->data && ft_lstsize2(*stack_b) == 1)
				pb(stack_a, stack_b);
			else if(last->data > (*stack_b)->data && last->data >= find_max_number(*stack_b) && (*stack_b)->data == find_max_number(*stack_b)) 
		   		pb(stack_a, stack_b); 
			else if(last->data < get_last_node(*stack_b)->data && last->data <= find_min_number(*stack_b) && get_last_node(*stack_b)->data == find_min_number(*stack_b))
			{
				pb(stack_a, stack_b);
				rb(stack_b);
			}
			else
			{
				while(smallest_pushed[i2])
				{
					while(smallest_pushed[j2])
					{
						if(!(last->data < smallest_pushed[i2] && last->data > smallest_pushed[j2]))
							movements2++;
						while (h2 < movements2 + 1)
						{
							rb_or_rrb(stack_b);
							h2++;
						}
						if (last->data < get_last_node(*stack_b)->data &&  last->data > (*stack_b)->data)
							pb(stack_a, stack_b);
						j2++;
					}
					i2++;
				}
			}

		}
	free(smallest_pushed);
		//Tal vez debo utilizar el mismo contador para last y para current_a ya que lo que quiero es que sume 1 cada vez que se haya utilizado un smallest?

}



//Actualmente estoy comprobando iteración a iteración, por ahora con el input que dejo abajo funciona hasta 5 veces, luego no encuentra el numero smallest 8 si no me equivoco:

// ./push_swap 53 78 99 54 76 7 35 65 23 3 98 66 95 82 77 72 67 83 61 45 69 63 6 59 58 96 89 16 21 52 97 71 87 51 81 30 32 80 91 39 2 93 5 24 22 17 43 60 44 88 31 1 40 18 37 10 12 13 27 56 74 94 19 49 38 47 15 41 29 55 33 8 92 75 26 84 62 70 4 42 20 68 48 36 25 79 28 100 64 86 90 73 85 14 34 46 50 11 57 110
