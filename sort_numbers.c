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
			if (smallest[j] > smallest[j + 1])
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
		for (i = 0; i < 20; i++)
		{
			if (temp->data < smallest[i])
			{
				// Desplazamos los elementos mayores hacia la derecha para hacer espacio para el nuevo elemento
				for (j = 19; j > i; j--)
				{
					smallest[j] = smallest[j - 1];
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
    for (i = 0; i < 20; i++)
    {
        t_stack *current_a = *stack_a;
        t_stack *current_a_last = get_last_node(*stack_a);

        while (current_a != NULL && current_a_last != NULL)
        {
            top_and_bottom_plus_detector_smallest(stack_a, stack_b, current_a, current_a_last, smallest);
            current_a = current_a->next;
            current_a_last = current_a_last->prev;
        }

        if (ft_lstsize2(*stack_b) == 20)
            break;
    }
}


void top_and_bottom_plus_detector_smallest(t_stack **stack_a, t_stack **stack_b, t_stack *current_a, t_stack *last, int *smallest)
{
    t_stack *temp = *stack_a;
    int top_movements = 0;
    int bottom_movements = 0;
    t_stack *top_node = NULL;  // Variable para guardar el nodo seleccionado por top_to_bottom()
    t_stack *bottom_node = NULL;  // Variable para guardar el nodo seleccionado por bottom_to_top()
    bool current_aa = 0;
    bool last_aa = 0;

    while (current_a != NULL && last != NULL)
    {
        if (current_a->data >= smallest[0] && current_a->data <= smallest[19])
        {
            current_aa = 1;
            top_node = current_a;  // Guardamos el nodo seleccionado por top_to_bottom()
        }
            
        if(last->data >= smallest[0] && last->data <= smallest[19])
        {
            last_aa = 1;
            bottom_node = last;  // Guardamos el nodo seleccionado por bottom_to_top()
        }
            
        if (current_a->data >= smallest[0] && current_a->data <= smallest[19] && last_aa == 1)
        {
            top_movements = top_to_bottom(temp, current_a);
            printf("top: %d\n", top_movements);
            current_a->top_movements = top_movements;
           
        }
        if(last->data >= smallest[0] && last->data <= smallest[19] && current_aa == 1)
        {
            bottom_movements = bottom_to_top(temp, last);
            printf("bottom: %d\n", bottom_movements);
            last->bottom_movements = bottom_movements;
            
        }
        if (top_node != NULL && bottom_node != NULL) //Se checkea para ver si los dos bucles han encontrado smallest
        {
            if (top_node->top_movements < bottom_node->bottom_movements)
            {
                while (top_node != *stack_a)
                    ra(stack_a);
                if(top_node == *stack_a)
                {
                    check_position_to_push_b(stack_a, stack_b, top_node, bottom_node, smallest);
                    current_aa = 0;
                    last_aa = 0;
                }
            }
            else if(top_node->top_movements > bottom_node->bottom_movements)
            {
                while (bottom_node != *stack_a)
                    rra(stack_a);
                if(bottom_node == *stack_a)
                {
                    check_position_to_push_b(stack_a, stack_b, top_node, bottom_node, smallest);
                    current_aa = 0;
                    last_aa = 0;
                }
            }
            else // top_node->top_movements == bottom_node->bottom_movements
            {
                while (top_node != *stack_a && bottom_node != *stack_a)
                    ra(stack_a);
                if(top_node == *stack_a && bottom_node == *stack_a)
                {
                    check_position_to_push_b(stack_a, stack_b, top_node, bottom_node, smallest);
                    current_aa = 0;
                    last_aa = 0;
                }
            }
            // Reiniciamos las variables para la siguiente iteración
            top_node = NULL;
            bottom_node = NULL;
        }
        current_a = current_a->next;
        last = last->prev;
    }
}


void    check_position_to_push_b(t_stack **stack_a, t_stack **stack_b, t_stack *current_a, t_stack *last, int *smallest)
{
	int i;
	int j;

	i = 0;
	j = 0;
		if (current_a == *stack_a)
		{
			if(*stack_b == NULL)
				pb(stack_a, stack_b);
			if(current_a->data > (*stack_b)->data && (*stack_b)->data == find_max_number(*stack_b))
				pb(stack_a, stack_b);
			if(current_a->data < get_last_node(*stack_b)->data && get_last_node(*stack_b)->data == find_min_number(*stack_b))
			{
				pb(stack_a, stack_b);
				rb(stack_b);
			}
			else if(!((current_a->data < smallest[i] && get_last_node(*stack_b)->data == smallest[i])) && ((current_a->data > smallest[i + 1] && (*stack_b)->data == smallest[i + 1])))
			{
				//Pendiente de revisión!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!1
				while(!((current_a->data < smallest[i] && get_last_node(*stack_b)->data == smallest[i])) && ((current_a->data > smallest[i + 1] && (*stack_b)->data == smallest[i + 1])))
					rb_or_rrb(stack_b);
				pb(stack_a, stack_b);
			}
			i++;
		}
		if (last == *stack_a)
		{
			if(*stack_b == NULL)
				pb(stack_a, stack_b);
			if(last->data > (*stack_b)->data && (*stack_b)->data == find_max_number(*stack_b))
				pb(stack_a, stack_b);
			if(last->data < get_last_node(*stack_b)->data && get_last_node(*stack_b)->data == find_min_number(*stack_b))
			{
				pb(stack_a, stack_b);
				rb(stack_b);
			}
			else if(!((last->data < smallest[j] && get_last_node(*stack_b)->data == smallest[j])) && ((last->data > smallest[j + 1] && (*stack_b)->data == smallest[j + 1])))
			{
				//Pendiente de revisión!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!1
				while(!((last->data < smallest[j] && get_last_node(*stack_b)->data == smallest[j])) && ((last->data > smallest[j + 1] && (*stack_b)->data == smallest[j + 1])))
					rb_or_rrb(stack_b);
				pb(stack_a, stack_b);
                //rrb no ordenar maybe
			}
			j++;
		}
		//Tal vez debo utilizar el mismo contador para last y para current_a ya que lo que quiero es que sume 1 cada vez que se haya utilizado un smallest?
}




