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
	int	*smallest = save_20_smallest_chunk(*stack_a);
	printf("Esto es smallest: ");
	for (int i = 0; i < 20; i++)
		printf("%d ", smallest[i]);
	printf("\n");
	t_stack *current_a = *stack_a;
	t_stack *current_a_last = get_last_node(*stack_a);

	for (i = 0; i < 6; i++) // 
	{
		t_stack *current_a = *stack_a;
		t_stack *current_a_last = get_last_node(*stack_a);
		top_and_bottom_plus_detector_smallest(stack_a, stack_b, current_a, current_a_last, smallest);
	    printf("esta es la i jeje: %d\n", i);
	}
}


void top_and_bottom_plus_detector_smallest(t_stack **stack_a, t_stack **stack_b, t_stack *current_a, t_stack *last, int *smallest)
{
	t_stack *temp = *stack_a;
	int top_movements = 0;
	int bottom_movements = 0;
	t_stack *top_node = NULL;  // Variable para guardar el nodo seleccionado por top_to_bottom()
	t_stack *bottom_node = NULL;  // Variable para guardar el nodo seleccionado por bottom_to_top()

	while(!(current_a->data >= smallest[19] && current_a->data <= smallest[0]))
		current_a = current_a->next;
	while (!(last->data >= smallest[19] && last->data <= smallest[0]))
		last = last->prev;
	if (current_a->data >= smallest[19] && current_a->data <= smallest[0])
	{
		top_node = current_a;
		printf("dataaaaaa topp: %d\n", top_node->data);
		top_movements = top_to_bottom(temp, top_node);
		printf("top: %d\n", top_movements);
		current_a->top_movements = top_movements;
	}
	if(last->data >= smallest[19] && last->data <= smallest[0])
	{
		
		bottom_node = last;
		printf("dataaaaaa: %d\n", bottom_node->data);
		bottom_movements = bottom_to_top(temp, bottom_node);
		printf("bottom: %d\n", bottom_movements);
		last->bottom_movements = bottom_movements;
	}
	if(last->data >= smallest[19] && last->data <= smallest[0] && current_a->data >= smallest[19] && current_a->data <= smallest[0])
		movements_checker_to_push_b(stack_a, stack_b, top_node, bottom_node, smallest);
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
			{
				rra(stack_a);
				printf("top: %d\n", top_node->top_movements);
				printf("bottom: %d\n", bottom_node->bottom_movements);
			}
			if(bottom_node == *stack_a)
				check_position_to_push_b(stack_a, stack_b, top_node, bottom_node, smallest);
		}
		else if(top_node->top_movements == bottom_node->bottom_movements)
		{
			while (top_node != *stack_a || bottom_node != *stack_a)
				ra(stack_a);
			if(top_node == *stack_a || bottom_node == *stack_a)
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

	i = 0;
	j = 1;
	if (current_a == *stack_a)
	{
		i = 0;
		j = 1;
		if(*stack_b == NULL)
			pb(stack_a, stack_b);
		else if(current_a->data < (*stack_b)->data && ft_lstsize2(*stack_b) == 1) //currentpero sin el, hay cosas que funcionan
		{
			printf("current: %d\n", current_a->data);
			printf("stack_b: %d\n", (*stack_b)->data);
			pb(stack_a, stack_b);
			rb(stack_b);
		}
		else if(current_a->data > (*stack_b)->data && ft_lstsize2(*stack_b) == 1)
			pb(stack_a, stack_b);
		else if(current_a->data > (*stack_b)->data && current_a->data >= find_max_number(*stack_b) && (*stack_b)->data == find_max_number(*stack_b))
		{
			printf("current: %d\n", current_a->data);
			printf("stack_b: %d\n", (*stack_b)->data);
			printf("max number: %d\n", find_max_number(*stack_b));
			pb(stack_a, stack_b); 
		}
		else if(current_a->data < get_last_node(*stack_b)->data && current_a->data <= find_min_number(*stack_b) && get_last_node(*stack_b)->data == find_min_number(*stack_b))
		{
			pb(stack_a, stack_b);
			rb(stack_b);
		}
		else if (!((current_a->data < smallest[i] && get_last_node(*stack_b)->data == smallest[i])) && ((current_a->data > smallest[j] && (*stack_b)->data == smallest[j])))
		{
			while(smallest[i]) // A LO MEJOR TENGO QUE AGREGAR UN SMALLEST_PUSHED
			{
				while(smallest[j])
				{
					while(!((current_a->data < smallest[i] && get_last_node(*stack_b)->data == smallest[i])) && ((current_a->data > smallest[j] && (*stack_b)->data == smallest[j])))
						rb_or_rrb(stack_b);
					if(((current_a->data < smallest[i] && get_last_node(*stack_b)->data == smallest[i]) && (current_a->data > smallest[j] && (*stack_b)->data == smallest[j])))
						pb(stack_a, stack_b);
					j++;
				}
				i++;
			}
		}
	}
		
		if(last == *stack_a)
		{
			i = 0;
			j = 1;
			if(*stack_b == NULL)
				pb(stack_a, stack_b);
			else if(last->data < (*stack_b)->data && ft_lstsize2(*stack_b) == 1) //currentpero sin el, hay cosas que funcionan
			{
				printf("current: %d\n", current_a->data);
				printf("stack_b: %d\n", (*stack_b)->data);
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
		
			else if ((!((last->data < smallest[i] && get_last_node(*stack_b)->data == smallest[i])) && ((last->data > smallest[j] && (*stack_b)->data == smallest[j]))))
			{
				while(smallest[i]) // A LO MEJOR TENGO QUE AGREGAR UN SMALLEST_PUSHED
				{
					while(smallest[j])
					{
						while(!((last->data < smallest[i] && get_last_node(*stack_b)->data == smallest[i])) && ((last->data > smallest[j] && (*stack_b)->data == smallest[j])))
							rb_or_rrb(stack_b);
						if(((last->data < smallest[i] && get_last_node(*stack_b)->data == smallest[i])) && ((last->data > smallest[j] && (*stack_b)->data == smallest[j])))
							pb(stack_a, stack_b);
						j++;
					}
					i++;
				}
			}
		}
		//Tal vez debo utilizar el mismo contador para last y para current_a ya que lo que quiero es que sume 1 cada vez que se haya utilizado un smallest?

}



//Actualmente estoy comprobando iteración a iteración, por ahora con el input que dejo abajo funciona hasta 5 veces, luego no encuentra el numero smallest 8 si no me equivoco:

// ./push_swap 53 78 99 54 76 7 35 65 23 3 98 66 95 82 77 72 67 83 61 45 69 63 6 59 58 96 89 16 21 52 97 71 87 51 81 30 32 80 91 39 2 93 5 24 22 17 43 60 44 88 31 1 40 18 37 10 12 13 27 56 74 94 19 49 38 47 15 41 29 55 33 8 92 75 26 84 62 70 4 42 20 68 48 36 25 79 28 100 64 86 90 73 85 14 34 46 50 11 57 110
