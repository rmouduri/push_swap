/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_min_max_abso.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmarien <cmarien@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 14:04:46 by cmarien           #+#    #+#             */
/*   Updated: 2021/05/05 14:04:48 by cmarien          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

int		abso(int nb)
{
	if (nb == -2147483648)
		return (0);
	if (nb < 0)
		return (-nb);
	return (nb);
}

void	get_min_max(int *min, int *max, t_list *lista)
{
	t_node	tmp;

	tmp = *lista->head;
	*min = tmp.nb;
	*max = tmp.nb;
	while (tmp.next)
	{
		if (*max < tmp.nb)
			*max = tmp.nb;
		if (*min > tmp.nb)
			*min = tmp.nb;
		tmp = *tmp.next;
	}
	if (*max < tmp.nb)
		*max = tmp.nb;
	if (*min > tmp.nb)
		*min = tmp.nb;
}
