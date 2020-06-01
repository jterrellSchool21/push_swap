/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solution_utils_2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jterrell <jterrell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/01 14:16:15 by jterrell          #+#    #+#             */
/*   Updated: 2020/06/01 14:19:47 by jterrell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int				show_last_num_in_stk(t_stk *stk)
{
	t_stk *tmp;

	if (stk && stk->head)
	{
		tmp = stk->head;
		while (tmp)
		{
			if (tmp->next == NULL)
				return (tmp->num);
			tmp = tmp->next;
		}
	}
	return (0);
}

void			reverse_order_of_chunks(t_pushswap *ps)
{
	int i;
	int chunks;

	if (!(ps->order = malloc(sizeof(int) * ps->chunks)))
		error_out(ps);
	i = 0;
	chunks = ps->chunks;
	while (i < ps->chunks)
	{
		ps->order[i] = chunks;
		i++;
		chunks--;
	}
}

int				is_num_in_chunk(int num, t_pushswap *ps, int curr_chunk)
{
	if (num >= find_holding_numbers(ps, ps->chunks, 0, curr_chunk) &&
		num <= find_holding_numbers(ps, ps->chunks, 1, curr_chunk))
		return (1);
	return (-1);
}

void			round_stk_a_before_max_num(t_pushswap *ps, int max,
		int start, int end)
{
	if (start <= end)
	{
		while (ps->b->head->num != max)
		{
			if ((find_index_of_num(ps, ps->b->head->num) + 1) ==
				find_index_of_num(ps, max))
				ps_pa(ps, 1);
			else
				ps_rb(ps, 1);
		}
	}
	else
	{
		while (ps->b->head->num != max)
		{
			if ((find_index_of_num(ps, ps->b->head->num) + 1) ==
				find_index_of_num(ps, max))
				ps_pa(ps, 1);
			else
				ps_rrb(ps, 1);
		}
	}
}
