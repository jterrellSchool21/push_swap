/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jterrell <jterrell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/01 14:15:41 by jterrell          #+#    #+#             */
/*   Updated: 2020/06/01 14:19:47 by jterrell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void				ps_sa(t_pushswap *ps, int ps_ch)
{
	t_stk *tmp;

	if (ps->a && ps->a->head && ps->a->head->next)
	{
		if ((tmp = remove_elem(ps->a->head->next)))
			ps->a = push(ps->a->head, tmp);
		if (ps->a)
		{
			ps->a->head = ps->a;
			change_head(ps->a->head, ps->a);
		}
		ps->analyse->instructions++;
		ps->analyse->sa++;
		if (ps_ch)
			ft_printf("sa\n");
	}
}

void				ps_sb(t_pushswap *ps, int ps_ch)
{
	t_stk *tmp;

	if (ps->b && ps->b->head && ps->b->head->next)
	{
		if ((tmp = remove_elem(ps->b->head->next)))
			ps->b = push(ps->b->head, tmp);
		if (ps->b)
		{
			ps->b->head = ps->b;
			change_head(ps->b->head, ps->b);
		}
		ps->analyse->instructions++;
		ps->analyse->sb++;
		if (ps_ch)
			ft_printf("sb\n");
	}
}

static void			change_heads_both_stacks(t_pushswap *ps)
{
	if (ps->a)
	{
		ps->a->head = ps->a;
		change_head(ps->a->head, ps->a);
	}
	if (ps->b)
	{
		ps->b->head = ps->b;
		change_head(ps->b->head, ps->b);
	}
}

void				ps_pa(t_pushswap *ps, int ps_ch)
{
	t_stk *tmp;
	t_stk *head_tmp;

	if (ps->b && ps->b->head)
	{
		head_tmp = ps->b->head->next;
		if ((tmp = remove_elem(ps->b->head)))
		{
			ps->b = head_tmp;
			if (ps->a && ps->a->head)
				ps->a = push(ps->a, tmp);
			else
			{
				ft_memdel((void **)&ps->a);
				ps->a = tmp;
			}
		}
		change_heads_both_stacks(ps);
		ps->analyse->instructions++;
		ps->analyse->pa++;
		if (ps_ch)
			ft_printf("pa\n");
	}
}

void				ps_pb(t_pushswap *ps, int ps_ch)
{
	t_stk *tmp;
	t_stk *head_tmp;

	if (ps->a && ps->a->head)
	{
		head_tmp = ps->a->head->next;
		if ((tmp = remove_elem(ps->a->head)))
		{
			ps->a = head_tmp;
			if (ps->b && ps->b->head)
				ps->b = push(ps->b, tmp);
			else
			{
				ft_memdel((void **)&ps->b);
				ps->b = tmp;
			}
		}
		change_heads_both_stacks(ps);
		ps->analyse->instructions++;
		ps->analyse->pb++;
		if (ps_ch)
			ft_printf("pb\n");
	}
}
