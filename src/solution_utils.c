/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solution_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jterrell <jterrell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/01 14:16:11 by jterrell          #+#    #+#             */
/*   Updated: 2020/06/01 14:19:47 by jterrell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int				is_num_smaller_than_others(t_stk *stk, int num)
{
	t_stk *head;

	if (!stk || !(head = stk->head))
		return (1);
	while (head)
	{
		if (num > head->num)
			return (-1);
		head = head->next;
	}
	return (1);
}

int				find_quant_nums_in_chunk(t_pushswap *ps, int counter)
{
	t_stk	*tmp;
	int		numbers_in_chunk;

	numbers_in_chunk = 0;
	if (ps->a && ps->a->head)
	{
		tmp = ps->a->head;
		while (tmp)
		{
			if (tmp->num >=
				find_holding_numbers(ps, ps->chunks, 0, counter) &&
				tmp->num <=
				find_holding_numbers(ps, ps->chunks, 1, counter))
				numbers_in_chunk++;
			tmp = tmp->next;
		}
	}
	return (numbers_in_chunk);
}

int				find_the_biggest_num(t_stk *stk)
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
			if (max < tmp->next->num)
				max = tmp->next->num;
			tmp = tmp->next;
		}
	}
	return (max);
}

int				find_index_of_num(t_pushswap *ps, int num)
{
	int i;

	i = 0;
	while (i < ps->quant_nums)
	{
		if (ps->analyse->sorted_arr[i] == num)
			break ;
		i++;
	}
	return (i);
}

/*
** 0 is start 1 is end
*/

int				find_holding_numbers(t_pushswap *ps, int chunks,
		int param, int counter)
{
	int num_in_chunks;

	num_in_chunks = ps->quant_nums / chunks;
	if (counter == 1)
		return (param == 0 ? ps->analyse->sorted_arr[0] :
		ps->analyse->sorted_arr[num_in_chunks]);
	else if (counter == chunks)
		return (param == 0 ? ps->analyse->sorted_arr[num_in_chunks *
		(counter - 1) + 1] : ps->analyse->sorted_arr[ps->quant_nums - 1]);
	else
		return (param == 0 ? ps->analyse->sorted_arr[num_in_chunks *
		(counter - 1) + 1] : ps->analyse->sorted_arr[num_in_chunks * counter]);
}
