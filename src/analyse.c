/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   analyse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jterrell <jterrell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/01 14:08:04 by jterrell          #+#    #+#             */
/*   Updated: 2020/06/01 14:22:16 by whool199         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

static void				swap_elements(int *tab, int p1, int p2)
{
	int tmp;

	tmp = tab[p1];
	tab[p1] = tab[p2];
	tab[p2] = tmp;
}

void					bubble_sort(int *tab, int size)
{
	int i;
	int j;

	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size - 1)
		{
			if (tab[j] > tab[j + 1])
				swap_elements(tab, j, j + 1);
			j++;
		}
		i++;
	}
}

int						create_sorted_array(t_pushswap *ps)
{
	t_stk		*tmp;
	int			i;

	i = 0;
	if (!(ps->analyse->sorted_arr =
		(int *)malloc(sizeof(int) * ps->quant_nums)))
		return (-1);
	tmp = ps->a->head;
	while (tmp && i < ps->quant_nums)
	{
		ps->analyse->sorted_arr[i] = tmp->num;
		i++;
		tmp = tmp->next;
	}
	bubble_sort(ps->analyse->sorted_arr, ps->quant_nums);
	return (1);
}

void					create_analyse_struct(t_pushswap *ps)
{
	if (!(ps->analyse = malloc(sizeof(t_analyse))))
		error_out(ps);
	ps->analyse->sa = 0;
	ps->analyse->sb = 0;
	ps->analyse->ss = 0;
	ps->analyse->pa = 0;
	ps->analyse->pb = 0;
	ps->analyse->ra = 0;
	ps->analyse->rb = 0;
	ps->analyse->rr = 0;
	ps->analyse->rra = 0;
	ps->analyse->rrb = 0;
	ps->analyse->rrr = 0;
	ps->analyse->instructions = 0;
}

void					print_analyse(t_pushswap *ps)
{
	print_stk(ps->a, 1);
	print_stk(ps->b, 2);
	ft_printf("INSTRUCTIONS: %i\n", ps->analyse->instructions);
	ft_printf("COMMANDS_USED:\nsa: %i  ", ps->analyse->sa);
	ft_printf("sb: %i  ", ps->analyse->sb);
	ft_printf("ss: %i  ", ps->analyse->ss);
	ft_printf("pa: %i  ", ps->analyse->pa);
	ft_printf("pb: %i  ", ps->analyse->pb);
	ft_printf("ra: %i  ", ps->analyse->ra);
	ft_printf("rb: %i  ", ps->analyse->rb);
	ft_printf("rr: %i  ", ps->analyse->rr);
	ft_printf("rra: %i  ", ps->analyse->rra);
	ft_printf("rrb: %i  ", ps->analyse->rrb);
	ft_printf("rrr: %i\n", ps->analyse->rrr);
	if (check_order(ps) == 1)
		ft_printf("****OK****\n");
	else
		ft_printf("****KO****\n");
}
