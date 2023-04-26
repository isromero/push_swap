/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_movements.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isromero <isromero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 09:42:00 by isromero          #+#    #+#             */
/*   Updated: 2023/04/26 09:43:38 by isromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*-----------------------------------------SWAPS-----------------------------------------*/

//Se intercambian los 2 primeros nodos de stack_a si hay más de 1
void    sa(t_stack **lst)
{
	t_stack *node_a;
	t_stack *node_b;
	t_stack *node_c; //node_c es un "temp" que evita la perdida de información de los demás nodos

	if (!*lst || !(*lst)->next)
		return ;
	//Creación de nodos en orden
	node_a = *lst; 
	node_b = (*lst)->next;
	node_c = (*lst)->next->next;
	//swap node_a y node_b
	node_b->next = node_a; 
	node_a->prev = node_b; 
	//node_a apunta a null si solo hay dos nodos
	node_a->next = NULL; 
	//Si existen mas de dos nodos, existe node_c entonces el siguiente de node_a apuntará a ese nodo
	if(node_c) 
		node_a->next = node_c;
	//node_b ahora contiene la información del primer nodo(no es necesario si se hace: node_b->next = node_a
	*lst = node_b;
	printf("sa\n");
}

//Se intercambian los 2 primeros nodos de stack_b si hay más de 1
void    sb(t_stack **lst)
{
	t_stack *node_a;
	t_stack *node_b;
	t_stack *node_c; //node_c es un "temp" que evita la perdida de información de los demás nodos

	if (!*lst || !(*lst)->next)
		return ;
	//Creación de nodos en orden
	node_a = *lst; 
	node_b = (*lst)->next;
	node_c = (*lst)->next->next;
	//swap node_a y node_b
	node_b->next = node_a; 
	node_a->prev = node_b; 
	//node_a apunta a null si solo hay dos nodos
	node_a->next = NULL; 
	//Si existen mas de dos nodos, existe node_c entonces el siguiente de node_a apuntará a ese nodo
	if(node_c) 
		node_a->next = node_c;
	//node_b ahora contiene la información del primer nodo(no es necesario si se hace: node_b->next = node_a
	*lst = node_b;
	printf("sb\n");
}

//Se hace sa y sb a la vez
void	ss(t_stack **stack_a, t_stack **stack_b)
{
	sa(stack_a);
	sb(stack_b);
	printf("ss\n");
}
