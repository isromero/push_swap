/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isromero <isromero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 21:27:42 by isromero          #+#    #+#             */
/*   Updated: 2023/04/03 21:35:32 by isromero         ###   ########.fr       */
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
	printf("pb\n");
}

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
	printf("rb\n");
}

//Se hace ra y rb a la vez
void	rr(t_stack **stack_a, t_stack **stack_b)
{
	ra(stack_a);
	rb(stack_b);
	printf("rr\n");
}

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
	
	//Un bucle que encuentra el último de last_node
	while(last_node->next)
		last_node = last_node->next;

	dont_lose_info = last_node->prev; //Se guarda el penúltimo nodo(se puede hacer en el while sin el prev). Este se guarda ya que posteriormente tiene que apuntar a NULL para no entrar en bucle
	*lst = last_node;

	//El último nodo ahora es el primero por lo que el siguiente será el antiguo primero, donde ahora es segundo
	last_node->next = first_node;
	//Ponemos el penúltimo nodo, que ahora es el último a NULL para no entrar en bucle y que sea el final de la lista
	dont_lose_info->next = NULL;

	//Se crea una auxiliar porque:  en rra, el primer nodo de la lista original se convierte 
	//en el último nodo de la lista rotada, y su campo next debe apuntar a NULL, ya que no hay más 
	//elementos después de él. Por lo tanto, se pierde la referencia al resto de la lista.
	printf("rra\n");
}

//El último nodo de stack_b pasa a ser el primero
void rrb(t_stack **lst)
{
    //esta wea nos pone ultimo primero
	t_stack *new_node = malloc(sizeof(t_stack));
    t_stack *secLast = NULL;
    
    new_node->next = *lst;
    while(new_node->next != NULL)
    {
        secLast = new_node;
        new_node = new_node->next;
    }
    secLast->next = NULL;
    new_node->next = *lst;
    *lst = new_node;
    ft_putstr("rrb\n");
}

//Se hace rra y rrb a la vez
void rrr(t_stack **stack_a, t_stack **stack_b)
{
	rra(stack_a);
	rrb(stack_b);
	printf("rrr\n");
}
