/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solution.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jterrell <jterrell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/01 14:16:08 by jterrell          #+#    #+#             */
/*   Updated: 2020/06/01 14:19:47 by jterrell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void				push_back_elements_on_a(t_pushswap *ps)
{
	int start;
	int end;
	int max_num_in_stk;

	while (ps->b && ps->b->head)
	{
		max_num_in_stk = find_the_biggest_num(ps->b);
		start = find_steps_before_num(ps->b, 's',
				find_lst_size(ps->b), max_num_in_stk);
		end = find_steps_before_num(ps->b, 'e',
				find_lst_size(ps->b), max_num_in_stk);
		round_stk_a_before_max_num(ps, max_num_in_stk, start, end);
		ps_pa(ps, 1);
		if (ps->a->head->next && ps->a->head->num > ps->a->head->next->num)
			ps_sa(ps, 1);
	}
}

static int			round_stk_a_before_tmp_num(t_pushswap *ps, int num)
{
	while (ps->a && ps->a->head->num != num)
	{
		if (ps->b && ps->b->head && (find_index_of_num(ps,
				show_last_num_in_stk(ps->b)) + 1) ==
				find_index_of_num(ps, ps->b->head->num))
			ps_rr(ps, 1);
		else
			ps_ra(ps, 1);
	}
	if (ps->a && ps->a->head && ps->a->head->num == num)
	{
		ps_pb(ps, 1);
		return (1);
	}
	return (0);
}

static void			round_tmp(t_pushswap *ps, t_stk *tmp, int counter)
{
	while (tmp)
	{
		if (is_num_in_chunk(tmp->num, ps, ps->order[counter]) == 1 &&
			round_stk_a_before_tmp_num(ps, tmp->num) == 1)
		{
			if (is_num_smaller_than_others(ps->b, ps->b->head->num) == 1)
			{
				if (ps->a && ps->a->head && is_num_in_chunk(ps->a->head->num,
				ps, ps->order[counter]) == 1)
					ps_rb(ps, 1);
				else if (ps->a && ps->a->head)
					ps_rr(ps, 1);
			}
			if (ps->a && ps->a->head)
				tmp = ps->a->head;
			else
				break ;
		}
		else
			tmp = tmp->next;
	}
}

void				sort_args(t_pushswap *ps)
{
	t_stk		*tmp;
	int			counter;

	counter = -1;
	while (++counter < ps->chunks)
	{
		while (find_quant_nums_in_chunk(ps, ps->order[counter]) != 0)
		{
			if (ps->a && ps->a->head)
			{
				tmp = ps->a->head;
				round_tmp(ps, tmp, counter);
			}
		}
	}
	push_back_elements_on_a(ps);
}

/*
** print_analyse(ps);
*/

void				push_swap(t_pushswap *ps)
{
	if (ps->quant_nums == 2)
		ps_sa(ps, 1);
	else if (ps->quant_nums > 2 && ps->quant_nums <= 12)
		sort_twelve_max_args(ps);
	else if (ps->quant_nums > 12)
	{
		if (ps->quant_nums <= 100)
			ps->chunks = 5;
		else if (ps->quant_nums <= 500)
			ps->chunks = 12;
		else
			ps->chunks = 5 + (ps->quant_nums - 100) / 50;
		reverse_order_of_chunks(ps);
		sort_args(ps);
		ft_memdel((void **)&ps->order);
	}
}
