/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isromero <isromero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 21:27:42 by isromero          #+#    #+#             */
/*   Updated: 2023/03/24 22:38:09 by isromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//Se intercambian los 2 primeros nodos si hay más de 1
void    sa(t_stack **lst)
{
    t_stack *node_a;
    t_stack *node_b;
    
    //Verificamos si lst es nulo(0 nodos) o si no existe el siguiente(si no existe solo será un nodo, sino 2 o +)
    if(!(*lst) || !(*lst)->next)
        return ;
    //Apuntamos node_a al primer nodo de la lista
    node_a = *lst;
    //Apuntamos node_b al segundo nodo de la lista
    node_b = node_a->next;
    //Intercambiamos donde apuntan cada nodo
    node_b->next = node_a;
    node_b->prev = NULL;
    node_a->prev = node_b;
    node_a->next = NULL;
    //Apuntamos el inicio de la lista a node_b
    *lst = node_b;
}