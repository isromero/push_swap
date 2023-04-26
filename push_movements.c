/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_movements.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isromero <isromero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 09:41:56 by isromero          #+#    #+#             */
/*   Updated: 2023/04/26 09:44:03 by isromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*-----------------------------------------PUSH-----------------------------------------*/

//Coge el primer nodo de stack b y lo pone encima de stack a
void	pa(t_stack **stack_a, t_stack **stack_b)
{
	t_stack *node_stack_b;
	
	if(!*stack_b)
		return ;
	
	//Creación de nodo del stack b apuntando al primero
	node_stack_b = *stack_b;
	//Eliminamos el primer nodo de stack_b
	*stack_b = node_stack_b->next; 
	
	//El primer nodo se añade al stack_a
	node_stack_b->next = *stack_a;
	//El nodo añadido se apila encima del anterior primer nodo de stack_a(importante hacer una condición que revise si hay algun nodo en stack_a para actualizar prev, ya que si no hay no hay que actualizar)
	if(*stack_a)
		(*stack_a)->prev = node_stack_b;
	//Esto es necesario para actualizar el puntero que apunta al primer elemento de la lista de stack_a
	*stack_a = node_stack_b;
	if(*stack_a)
		(*stack_a)->prev = NULL;
	printf("pa\n");
}

//Coge el primer nodo de stack a y lo pone encima de stack b
void	pb(t_stack **stack_a, t_stack **stack_b)
{
	t_stack *node_stack_a;
	
	if(!*stack_a)
		return ;
	
	//Creación de nodo del stack a apuntando al primero
	node_stack_a = *stack_a;
	//Eliminamos el primer nodo de stack_a
	*stack_a = node_stack_a->next; 
	
	//El primer nodo se añade al stack_a
	node_stack_a->next = *stack_b;
	//El nodo añadido se apila encima del anterior primer nodo de stack_a(importante hacer una condición que revise si hay algun nodo en stack_b para actualizar prev, ya que si no hay no hay que actualizar)
	if(*stack_b)
		(*stack_b)->prev = node_stack_a;
	//Esto es necesario para actualizar el puntero que apunta al primer elemento de la lista de stack_b
	*stack_b = node_stack_a;
	if(*stack_b)
		(*stack_b)->prev = NULL;
	printf("pb\n");
}