/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmouduri <rmouduri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 11:29:53 by rmouduri          #+#    #+#             */
/*   Updated: 2021/04/19 15:23:45 by rmouduri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "utils.h"
#include "push_swap.h"

#include <stdio.h>

int	main(int ac, char **av)
{
	int		*tab;
	int		med;
	t_list	*lista;
	t_list	*listb;

	if (ac < 2)
		return (return_error("Not enough arguments\n"));
	if (!(tab = malloc(sizeof(int) * (ac - 1))))
		return (return_error("Malloc of int tab\n"));
	if (!fill_tab(ac, av, &tab))
	{
		free(tab);
		return (return_error("Invalid argument\n"));
	}
	if (!(init_lists(&lista, &listb)))
		return (0);
	convert(tab, &lista, ac - 1);
	free(tab);
	med = median(lista, (ac - 1));
	push_swap(lista, listb, (ac - 1), med);
	free_list(&lista);
	free_list(&listb);
	return (1);
}
