/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_instructions.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jterrell <jterrell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/01 14:15:52 by jterrell          #+#    #+#             */
/*   Updated: 2020/06/01 14:19:47 by jterrell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void		ps_rb(t_pushswap *ps, int ps_ch)
{
	t_stk *tmp;
	t_stk *head_tmp;

	if (ps->b && ps->b->head && ps->b->head->next)
	{
		head_tmp = ps->b->head->next;
		if ((tmp = remove_elem(ps->b->head)))
		{
			ps->b = head_tmp;
			if (ps->b)
			{
				ps->b->head = ps->b;
				change_head(ps->b->head, ps->b);
			}
			append_elem(ps->b, tmp);
		}
		ps->analyse->instructions++;
		ps->analyse->rb++;
		if (ps_ch)
			ft_printf("rb\n");
	}
}

void		ps_rra(t_pushswap *ps, int ps_ch)
{
	t_stk *tmp;

	if (ps->a && ps->a->head && ps->a->head->next)
	{
		tmp = ps->a->head;
		while (tmp && tmp->next)
			tmp = tmp->next;
		if ((tmp = remove_elem(tmp)))
		{
			ps->a = push(ps->a, tmp);
			change_head(ps->a->head, ps->a);
		}
		ps->analyse->instructions++;
		ps->analyse->rra++;
		if (ps_ch)
			ft_printf("rra\n");
	}
}

void		ps_rrb(t_pushswap *ps, int ps_ch)
{
	t_stk *tmp;

	if (ps->b && ps->b->head && ps->b->head->next)
	{
		tmp = ps->b->head;
		while (tmp && tmp->next)
			tmp = tmp->next;
		if ((tmp = remove_elem(tmp)))
		{
			ps->b = push(ps->b, tmp);
			change_head(ps->b->head, ps->b);
		}
		ps->analyse->instructions++;
		ps->analyse->rrb++;
		if (ps_ch)
			ft_printf("rrb\n");
	}
}

void		execute_instruction(t_pushswap *ps, char *cmd, int ps_ch)
{
	if (ft_strequ(cmd, "sa\n") == 1 || ft_strequ(cmd, "sa") == 1)
		ps_sa(ps, ps_ch);
	else if (ft_strequ(cmd, "sb\n") == 1 || ft_strequ(cmd, "sb") == 1)
		ps_sb(ps, ps_ch);
	else if (ft_strequ(cmd, "ss\n") == 1 || ft_strequ(cmd, "ss") == 1)
		ps_ss(ps, ps_ch);
	else if (ft_strequ(cmd, "pa\n") == 1 || ft_strequ(cmd, "pa") == 1)
		ps_pa(ps, ps_ch);
	else if (ft_strequ(cmd, "pb\n") == 1 || ft_strequ(cmd, "pb") == 1)
		ps_pb(ps, ps_ch);
	else if (ft_strequ(cmd, "ra\n") == 1 || ft_strequ(cmd, "ra") == 1)
		ps_ra(ps, ps_ch);
	else if (ft_strequ(cmd, "rb\n") == 1 || ft_strequ(cmd, "rb") == 1)
		ps_rb(ps, ps_ch);
	else if (ft_strequ(cmd, "rr\n") == 1 || ft_strequ(cmd, "rr") == 1)
		ps_rr(ps, ps_ch);
	else if (ft_strequ(cmd, "rra\n") == 1 || ft_strequ(cmd, "rra") == 1)
		ps_rra(ps, ps_ch);
	else if (ft_strequ(cmd, "rrb\n") == 1 || ft_strequ(cmd, "rrb") == 1)
		ps_rrb(ps, ps_ch);
	else if (ft_strequ(cmd, "rrr\n") == 1 || ft_strequ(cmd, "rrr") == 1)
		ps_rrr(ps, ps_ch);
}
