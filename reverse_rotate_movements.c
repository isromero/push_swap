/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate_movements.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isromero <isromero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 09:41:58 by isromero          #+#    #+#             */
/*   Updated: 2023/04/26 09:45:00 by isromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*-----------------------------------------REVERSE ROTATE-----------------------------------------*/

//El último nodo de stack_a pasa a ser el primero
void rra(t_stack **lst)
{
	t_stack *first_node;
	t_stack	*last_node;
	t_stack	*dont_lose_info;
	
	if (!(*lst) || !(*lst)->next) //No necesario realmente
		return ;

	//El primero nodo apunta al principio de la lista
	first_node = *lst;
	//El primer nodo ahora apunta al último para poder recorrer desde ahí
	last_node = first_node;
	
	//Un bucle que encuentra el último de last_node y guarda la información de last_node
	while(last_node->next)
    {
        dont_lose_info = last_node;
		last_node = last_node->next;
    }
    //Ponemos a NULL dont_lose_info porque es el último nodo y last_node en cambio prev le ponemos NULL porque vamos a hacer que sea el primero
	dont_lose_info->next = NULL;
    last_node->prev = NULL;
    
    //Hacemos que el antiguo último ahora es el primero ya que apunta el next al primero y el primero su prev apunta al antiguo último
	last_node->next = first_node;
    first_node->prev = last_node;

    //last_node apunta finalmente al principio de la lista
    *lst = last_node;

	//Se crea una auxiliar porque:  en rra, el primer nodo de la lista original se convierte 
	//en el último nodo de la lista rotada, y su campo next debe apuntar a NULL, ya que no hay más 
	//elementos después de él. Por lo tanto, se pierde la referencia al resto de la lista.
	printf("rra\n");
}

//El último nodo de stack_b pasa a ser el primero
void rrb(t_stack **lst)
{
	t_stack *first_node;
	t_stack	*last_node;
	t_stack	*dont_lose_info;
	
	if (!(*lst) || !(*lst)->next) //No necesario realmente
		return ;

	//El primero nodo apunta al principio de la lista
	first_node = *lst;
	//El primer nodo ahora apunta al último para poder recorrer desde ahí
	last_node = first_node;
	
	//Un bucle que encuentra el último de last_node y guarda la información de last_node
	while(last_node->next)
    {
        dont_lose_info = last_node;
		last_node = last_node->next;
    }
    //Ponemos a NULL dont_lose_info porque es el último nodo y last_node en cambio prev le ponemos NULL porque vamos a hacer que sea el primero
	dont_lose_info->next = NULL;
    last_node->prev = NULL;
    
    //Hacemos que el antiguo último ahora es el primero ya que apunta el next al primero y el primero su prev apunta al antiguo último
	last_node->next = first_node;
    first_node->prev = last_node;

    //last_node apunta finalmente al principio de la lista
    *lst = last_node;

	//Se crea una auxiliar porque:  en rra, el primer nodo de la lista original se convierte 
	//en el último nodo de la lista rotada, y su campo next debe apuntar a NULL, ya que no hay más 
	//elementos después de él. Por lo tanto, se pierde la referencia al resto de la lista.
	printf("rrb\n");
}

//Se hace rra y rrb a la vez
void rrr(t_stack **stack_a, t_stack **stack_b)
{
	t_stack *first_node_a;
	t_stack	*last_node_a;
	t_stack	*dont_lose_info_a;
	t_stack *first_node_b;
	t_stack	*last_node_b;
	t_stack	*dont_lose_info_b;

	first_node_a = *stack_a;
	first_node_b = *stack_b;
	last_node_a = first_node_a;
	last_node_b = first_node_b;
	
	while(last_node_a->next)
    {
        dont_lose_info_a = last_node_a;
		last_node_a = last_node_a->next;
    }
	while(last_node_b->next)
    {
        dont_lose_info_b = last_node_b;
		last_node_b = last_node_b->next;
    }
	dont_lose_info_a->next = NULL;
	dont_lose_info_b->next = NULL;
    last_node_a->prev = NULL;
    last_node_b->prev = NULL;
    
	last_node_a->next = first_node_a;
	last_node_b->next = first_node_b;
    first_node_a->prev = last_node_a;
	first_node_b->prev = last_node_b;

    //last_node apunta finalmente al principio de la lista
    *stack_a = last_node_a;
	*stack_b = last_node_b;
	printf("rrr\n");
}
