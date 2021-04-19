/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rra.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmouduri <rmouduri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 15:12:31 by rmouduri          #+#    #+#             */
/*   Updated: 2021/04/19 15:24:13 by rmouduri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	rra(t_list **lista)
{
	t_node	*node;

	if (!lista || !*lista || !(*lista)->head || !(*lista)->tail)
		return ;
	node = (*lista)->tail;	
	(*lista)->tail = (*lista)->tail->prev;
	(*lista)->tail->next = NULL;
	(*lista)->head->prev = node;
	node->next = (*lista)->head;
	node->prev = NULL;
	(*lista)->head = node;
}
