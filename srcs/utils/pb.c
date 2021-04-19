/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pb.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmouduri <rmouduri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 13:02:31 by rmouduri          #+#    #+#             */
/*   Updated: 2021/04/19 14:02:05 by rmouduri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	pb(t_list **lista, t_list **listb)
{
	t_node	*node;

	if (!lista || !*lista || !(*lista)->head)
		return ;
	node = (*lista)->head;
	(*lista)->head = (*lista)->head->next;
	(*lista)->head->prev = NULL;
	node->next = (*listb)->head;
	node->prev = NULL;
	if ((*listb)->head)
		(*listb)->head->prev = node;
	(*listb)->head = node;
}
