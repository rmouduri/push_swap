#include "utils.h"

void	get_min_max(int	*min, int *max, t_list *lst_a)
{
	t_node	tmp;

	tmp = *lst_a->head;
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

int	push_swap(t_list *lst_a, t_list *lst_b, int size ,int med)
{
	int	half;
	int	sorted;
	int	min;
	int	max;

	sorted = 0;
	half = 0;
	get_min_max(&min, &max, lst_a);
	while (half < (size / 2))
	{
		if (lst_a->head->nb <= med)
		{
			write(1, "pb\n", 3);
			pb(&lst_a, &lst_b);
			half++;
		}
		else
		{
			write(1, "ra\n", 3);
			ra(&lst_a);
		}
	}
	while (sorted != 1)
	{
		if (((lst_a->head->next) && (lst_b->head->next)) && ((lst_a->head->nb > lst_a->head->next->nb) && (lst_a->head->nb < max)) && ((lst_b->head->nb < lst_b->head->next->nb) && (lst_b->head->nb > min)))
		{
			write(1, "ss\n", 3);
			ss(&lst_a, &lst_b);
		}
		else if ((lst_a->head->next) && (lst_a->head->nb > lst_a->head->next->nb) && (lst_a->head->nb < max))
		{
			write(1, "sa\n", 3);
			sa(&lst_a);
		}
		else if ((lst_b->head->next) && (lst_b->head->nb < lst_b->head->next->nb) && (lst_b->head->nb > min)/* || (lst_b->head->next->nb < -100)*/)
		{
			write(1, "sb\n", 3);
			sb(&lst_b);
		}
		int a = is_sorted(lst_a);
		int b = is_rev_sorted(lst_b);
		if (a == 0 && b == 0)
		{
			write(1, "rr\n", 3);
			rr(&lst_a, &lst_b);
		}
		else if (a == 0)
		{
			write(1, "ra\n", 3);
			ra(&lst_a);
		}
		else if (b == 0/* && lst_b->head->next->nb > -100*/)
		{
			write(1, "rb\n", 3);
			rb(&lst_b);
		}
		if (a == 1 && b == 1)
		{
			while (half-- > 0)
			{
				write(1, "pa\n", 3);
				pa(&lst_a, &lst_b);
			}
			sorted = 1;
		}
	}
//	print_list(lst_a);
//	print_list(lst_b);
}
