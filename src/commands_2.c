/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jterrell <jterrell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/01 14:15:46 by jterrell          #+#    #+#             */
/*   Updated: 2020/06/01 14:19:47 by jterrell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void				ps_ra(t_pushswap *ps, int ps_ch)
{
	t_stk *tmp;
	t_stk *head_tmp;

	if (ps->a && ps->a->head)
	{
		head_tmp = ps->a->head->next;
		if ((tmp = remove_elem(ps->a->head)))
		{
			ps->a = head_tmp;
			if (ps->a)
			{
				ps->a->head = ps->a;
				change_head(ps->a->head, ps->a);
				append_elem(ps->a, tmp);
			}
		}
		ps->analyse->instructions++;
		ps->analyse->ra++;
		if (ps_ch)
			ft_printf("ra\n");
	}
}

void				ps_rrr(t_pushswap *ps, int ps_ch)
{
	if (ps->a && ps->a->head && ps->b && ps->b->head)
	{
		ps_rra(ps, 0);
		ps_rrb(ps, 0);
		ps->analyse->instructions++;
		ps->analyse->rrr++;
		ps->analyse->rra--;
		ps->analyse->rrb--;
		if (ps_ch)
			ft_printf("rrr\n");
	}
}

void				ps_rr(t_pushswap *ps, int ps_ch)
{
	if (ps->a && ps->a->head && ps->b && ps->b->head)
	{
		ps_ra(ps, 0);
		ps_rb(ps, 0);
		ps->analyse->instructions++;
		ps->analyse->rr++;
		ps->analyse->ra--;
		ps->analyse->rb--;
		if (ps_ch)
			ft_printf("rr\n");
	}
}

void				ps_ss(t_pushswap *ps, int ps_ch)
{
	if (ps->a && ps->a->head && ps->b && ps->b->head)
	{
		ps_sa(ps, 0);
		ps_sb(ps, 0);
		ps->analyse->instructions++;
		ps->analyse->ss++;
		ps->analyse->sa--;
		ps->analyse->sb--;
		if (ps_ch)
			ft_printf("ss\n");
	}
}
