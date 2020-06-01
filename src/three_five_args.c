/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   three_five_args.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jterrell <jterrell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/01 14:16:18 by jterrell          #+#    #+#             */
/*   Updated: 2020/06/01 14:19:47 by jterrell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

static int			find_the_smallest_num(t_stk *stk)
{
	t_stk		*tmp;
	int			max;

	max = 0;
	if (stk && stk->head)
	{
		tmp = stk->head;
		max = tmp->num;
		while (tmp && tmp->next)
		{
			if (max > tmp->next->num)
				max = tmp->next->num;
			tmp = tmp->next;
		}
	}
	return (max);
}

void				sort_three_args(t_pushswap *ps)
{
	t_stk		*sec_num;
	t_stk		*third_num;
	int			min;

	min = find_the_smallest_num(ps->a);
	sec_num = ps->a->head->next;
	third_num = sec_num->next;
	if (check_order_simple(ps, 'a') == 1)
		return ;
	if (ps->a->head->num == min)
	{
		ps_rra(ps, 1);
		ps_sa(ps, 1);
	}
	else if ((third_num->num == min && ps->a->head->num > sec_num->num) ||
	sec_num->num == min)
	{
		ps_sa(ps, 1);
		sort_three_args(ps);
	}
	else if (third_num->num == min && ps->a->head->num < sec_num->num)
		ps_rra(ps, 1);
}

static void			get_minimum_on_top_on_a(t_pushswap *ps)
{
	int start;
	int end;
	int min;

	min = find_the_smallest_num(ps->a);
	start = find_steps_before_num(ps->a, 's', find_lst_size(ps->a), min);
	end = find_steps_before_num(ps->a, 'e', find_lst_size(ps->a), min);
	if (start <= end)
		while (ps->a->head->num != min)
			ps_ra(ps, 1);
	else
		while (ps->a->head->num != min)
			ps_rra(ps, 1);
}

void				sort_twelve_max_args(t_pushswap *ps)
{
	int diff;

	diff = ps->quant_nums - 3;
	while (diff)
	{
		get_minimum_on_top_on_a(ps);
		ps_pb(ps, 1);
		diff--;
	}
	sort_three_args(ps);
	while (diff != ps->quant_nums - 3)
	{
		ps_pa(ps, 1);
		diff++;
	}
}
