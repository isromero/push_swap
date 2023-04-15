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

    // for (i = 0; i < 20; i++)
    // {
       
            //ESTO ES NUEVO, LE QUITE EL BUCLE CURRENT Y LAST != NULL Y QUE VAYA AVANZANDO PARA QUE NO RECORRA UNO DENTRO DEL OTRO
 
            top_and_bottom_plus_detector_smallest(stack_a, stack_b, current_a, current_a_last, smallest);



    //     printf("esta es la i jeje: %d\n", i);
    // }
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
    current_a = *stack_a; //ESTO ES NUEVO
    last = get_last_node(*stack_a); //ESTO ES NUEVO

    while (current_a != NULL && last != NULL)
    {
        if (current_a->data >= smallest[19] && current_a->data <= smallest[0])
        {
            top_node = current_a;  // Guardamos el nodo seleccionado por top_to_bottom()
            current_aa = 1;
        }
            
        if(last->data >= smallest[19] && last->data <= smallest[0])
        {
           
            bottom_node = last;  // Guardamos el nodo seleccionado por bottom_to_top()
            last_aa = 1;
        }
        if(last->data >= smallest[19] && last->data <= smallest[0] && current_aa == 1)
        {
            bottom_movements = bottom_to_top(temp, bottom_node);
            printf("bottom: %d\n", bottom_movements);
            last->bottom_movements = bottom_movements;
        }
        if (current_a->data >= smallest[19] && current_a->data <= smallest[0] && last_aa == 1)
        {
            top_movements = top_to_bottom(temp, top_node);
            printf("top: %d\n", top_movements);
            current_a->top_movements = top_movements;
        }
        if (top_node != NULL && bottom_node != NULL && last_aa == 1 && current_aa == 1)
        {
            if (current_a->top_movements < last->bottom_movements)
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
            else if(current_a->top_movements > last->bottom_movements)
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
            else if(current_a->top_movements == last->bottom_movements)
            {
                while (top_node != *stack_a || bottom_node != *stack_a)
                    ra(stack_a);
                if(top_node == *stack_a || bottom_node == *stack_a)
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
	j = 1;
	if (current_a == *stack_a || last == *stack_a)
    {
        if(*stack_b == NULL)
            pb(stack_a, stack_b);
        else if(((last->data < (*stack_b)->data)) && ft_lstsize2(*stack_b) == 1) //he quitado current, tengo que añadirlo, pero sin el, hay cosas que funcionan
        {
            printf("hola\n");
            pb(stack_a, stack_b);
            rb(stack_b);
        }
        else if((current_a->data > (*stack_b)->data || (last->data > (*stack_b)->data)) && ft_lstsize2(*stack_b) == 1)
            pb(stack_a, stack_b);
        //Falla el 8 !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
        // else if(current_a->data > (*stack_b)->data && current_a->data >= find_max_number(*stack_b) && (*stack_b)->data == find_max_number(*stack_b))
        //     pb(stack_a, stack_b); 
        // else if(last->data > (*stack_b)->data && last->data >= find_max_number(*stack_b) && (*stack_b)->data == find_max_number(*stack_b)) 
        //     pb(stack_a, stack_b); 
        else if(current_a->data < get_last_node(*stack_b)->data && current_a->data <= find_min_number(*stack_b) && get_last_node(*stack_b)->data == find_min_number(*stack_b))
        {
            printf("que pasaaa peña\n");
            pb(stack_a, stack_b);
            rb(stack_b);
        }
        else if(last->data < get_last_node(*stack_b)->data && last->data <= find_min_number(*stack_b) && get_last_node(*stack_b)->data == find_min_number(*stack_b))
        {
            printf("que pasaaa git\n");
            pb(stack_a, stack_b);
            rb(stack_b);
        }
        
        else if (!((current_a->data < smallest[i] && get_last_node(*stack_b)->data == smallest[i])) && ((current_a->data > smallest[j] && (*stack_b)->data == smallest[j])) || 
            (!((last->data < smallest[i] && get_last_node(*stack_b)->data == smallest[i])) && ((last->data > smallest[j] && (*stack_b)->data == smallest[j]))))
        {
            while(smallest[i]) // A LO MEJOR TENGO QUE AGREGAR UN SMALLEST_PUSHED
            {
                while(smallest[j])
                {
                    while(!((current_a->data < smallest[i] && get_last_node(*stack_b)->data == smallest[i])) && ((current_a->data > smallest[j] && (*stack_b)->data == smallest[j])) || 
                    (!((last->data < smallest[i] && get_last_node(*stack_b)->data == smallest[i])) && ((last->data > smallest[j] && (*stack_b)->data == smallest[j]))))
                        rb_or_rrb(stack_b);
                    if(((current_a->data < smallest[i] && get_last_node(*stack_b)->data == smallest[i]) && (current_a->data > smallest[j] && (*stack_b)->data == smallest[j])) || 
                    ((last->data < smallest[i] && get_last_node(*stack_b)->data == smallest[i])) && ((last->data > smallest[j] && (*stack_b)->data == smallest[j])))
                        pb(stack_a, stack_b);
                    j++;
                }
            
                i++;
            }
        }
    }
    //     else if(!((current_a->data < smallest[i] && get_last_node(*stack_b)->data == smallest[i])) && ((current_a->data > smallest[i + 1] && (*stack_b)->data == smallest[i + 1])) || 
    //     (!((last->data < smallest[j] && get_last_node(*stack_b)->data == smallest[j])) && ((last->data > smallest[j + 1] && (*stack_b)->data == smallest[j + 1]))))
    //     {
    //         while(!((current_a->data < smallest[i] && get_last_node(*stack_b)->data == smallest[i])) && ((current_a->data > smallest[i + 1] && (*stack_b)->data == smallest[i + 1])) || 
    //         (!((last->data < smallest[j] && get_last_node(*stack_b)->data == smallest[j])) && ((last->data > smallest[j + 1] && (*stack_b)->data == smallest[j + 1]))))
    //             rb_or_rrb(stack_b);
    //     }
    //     else if(((current_a->data < smallest[i] && get_last_node(*stack_b)->data == smallest[i])) && ((current_a->data > smallest[i + 1] && (*stack_b)->data == smallest[i + 1])) || 
    //     ((last->data < smallest[j] && get_last_node(*stack_b)->data == smallest[j])) && ((last->data > smallest[j + 1] && (*stack_b)->data == smallest[j + 1])))
    //     {
    //         pb(stack_a, stack_b);
    //     }
    // }
		//Tal vez debo utilizar el mismo contador para last y para current_a ya que lo que quiero es que sume 1 cada vez que se haya utilizado un smallest?

}



//Actualmente estoy checkeando la funcion de pushear numeros en el orden correcto ya que ha habido unos problemas en condiciones como la que acabo de poner que veia que no testeaba si el numero era el primero de todos en un extremo u otro
//de esta manera si lo es, en vez de comprobare los movimientos directamente lo pusheamos en el sitio correcto, pero al hacer esto he visto que hay un problema que no sé de donde venia y  es por la cara un error en los maximos y minimos
//aunque sin ningun tipo de sentido
