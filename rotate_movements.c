/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_movements.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isromero <isromero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 09:44:27 by isromero          #+#    #+#             */
/*   Updated: 2023/04/26 09:44:31 by isromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*-----------------------------------------ROTATE-----------------------------------------*/

//El primer nodo pasa a ser el último en el stack_a
void	ra(t_stack **lst)
{
	t_stack *first_node;
	t_stack	*last_node;
	
	if (!(*lst) || !(*lst)->next) //No necesario realmente
		return ;

	//El primero nodo apunta al principio de la lista
	first_node = *lst;
	//El primer nodo ahora apunta al último para poder recorrer desde ahí
	last_node = first_node;
	
	//Un bucle que encuentra el último de last_node
	while(last_node->next)
		last_node = last_node->next;

	//El segundo nodo se convierte en el primer nodo apuntado por la lista
	*lst = first_node->next;
	
	//Esto realiza la rotación ya que el nuevo último nodo es el primero anteriormente
	last_node->next = first_node;
	//Nos aseguramos que el último elemento, que antes era el primero, apunta a NULL para no entrar en bucle
	first_node->next = NULL;
	first_node->prev = last_node;
	if(*lst)
		(*lst)->prev = NULL;
	printf("ra\n");
}

//El primer nodo pasa a ser el último en el stack_b
void	rb(t_stack **lst)
{
	t_stack *first_node;
	t_stack	*last_node;
	
	if (!(*lst) || !(*lst)->next) //No necesario realmente
		return ;

	//El primero nodo apunta al principio de la lista
	first_node = *lst;
	//El primer nodo ahora apunta al último para poder recorrer desde ahí
	last_node = first_node;
	
	//Un bucle que encuentra el último de last_node
	while(last_node->next)
		last_node = last_node->next;

	//El segundo nodo se convierte en el primer nodo apuntado por la lista
	*lst = first_node->next;
	
	//Esto realiza la rotación ya que el nuevo último nodo es el primero anteriormente
	last_node->next = first_node;
	//Nos aseguramos que el último elemento, que antes era el primero, apunta a NULL para no entrar en bucle
	first_node->next = NULL;
	first_node->prev = last_node;
	if(*lst)
		(*lst)->prev = NULL;
	printf("rb\n");
	
}

//Se hace ra y rb a la vez
void	rr(t_stack **stack_a, t_stack **stack_b)
{
	t_stack *first_node_a;
	t_stack	*last_node_a;
	t_stack *first_node_b;
	t_stack	*last_node_b;
	
	first_node_a = *stack_a;
	last_node_a = first_node_a;
	first_node_b = *stack_b;
	last_node_b = first_node_b;
	
	while(last_node_a->next)
		last_node_a = last_node_a->next;
	while(last_node_b->next)
		last_node_b = last_node_b->next;

	*stack_a = first_node_a->next;
	*stack_b = first_node_b->next;
	
	last_node_a->next = first_node_a;
	last_node_b->next = first_node_b;
	first_node_a->next = NULL;
	first_node_b->next = NULL;
	first_node_a->prev = last_node_a;
	first_node_b->prev = last_node_b;
	if(*stack_a)
		(*stack_a)->prev = NULL;
	if(*stack_b)
		(*stack_b)->prev = NULL;
	printf("rr\n");
}