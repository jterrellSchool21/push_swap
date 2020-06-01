/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jterrell <jterrell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/01 14:16:25 by jterrell          #+#    #+#             */
/*   Updated: 2020/06/01 14:18:05 by jterrell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void				print_stk(t_stk *head, int stack)
{
	if (!head || !head->head)
		ft_printf("Stack %c is empty.\n", stack == 1 ? 'A' : 'B');
	else
	{
		if (stack == 1)
			ft_printf("stack A is: ");
		else if (stack == 2)
			ft_printf("stack B is: ");
		while (head)
		{
			ft_printf("%i ", head->num);
			head = head->next;
		}
		ft_printf("\n");
	}
}

int					check_order_simple(t_pushswap *ps, char stack)
{
	t_stk *stk;

	if (stack == 'a' && ps->a && ps->a->head)
		stk = ps->a->head;
	else if (stack == 'b' && ps->b && ps->b->head)
		stk = ps->b->head;
	else
		return (1);
	while (stk)
	{
		if (stk->next)
			if (stk->num > stk->next->num)
				return (-1);
		stk = stk->next;
	}
	return (1);
}

int					find_steps_before_num(t_stk *stk, char start_end,
		int quant, int num)
{
	int			st;
	t_stk		*tmp;

	st = 0;
	if (stk && stk->head)
	{
		tmp = stk->head;
		while (tmp)
		{
			if (tmp->num == num)
				break ;
			st++;
			tmp = tmp->next;
		}
	}
	return (start_end == 's' ? st : (quant - st));
}

char				**parse_string_arg(char *str)
{
	char **res;

	res = ft_strsplit(str, ' ');
	return (res);
}

int					find_2d_arr_size(char **arr)
{
	int i;

	i = 0;
	while (arr[i])
		i++;
	return (i);
}
