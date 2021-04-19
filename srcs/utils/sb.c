/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sb.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmouduri <rmouduri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 12:33:32 by rmouduri          #+#    #+#             */
/*   Updated: 2021/04/19 13:11:59 by rmouduri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	sb(t_list **listb)
{
	t_node	*node;

	if (!listb || !*listb)
		return ;
	if (!(*listb)->head || !(*listb)->head->next)
		return ;
	node = (*listb)->head->next;
	(*listb)->head->next = node->next;
	(*listb)->head->prev = node;
	node->prev = NULL;
	node->next = (*listb)->head;
	(*listb)->head = node;
}
