/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jterrell <jterrell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/01 14:16:21 by jterrell          #+#    #+#             */
/*   Updated: 2020/06/01 14:18:05 by jterrell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int					check_order(t_pushswap *ps)
{
	t_stk *tmp;

	if (!ps->a)
		return (-1);
	tmp = ps->a->head;
	while (tmp && tmp->next)
	{
		if (tmp->num > tmp->next->num)
			return (-1);
		tmp = tmp->next;
	}
	if (find_lst_size(ps->a->head) != ps->quant_nums)
		return (-1);
	return (1);
}

t_stk				*create_data(int ac, char **av, char stack, char *param)
{
	int		i;
	t_stk	*head;
	t_stk	*first;

	if (!(first = malloc(sizeof(t_stk))))
		return (NULL);
	first->next = NULL;
	first->head = NULL;
	if (stack == 'b')
		return (first);
	first->head = first;
	head = first;
	i = param == NULL ? 2 : 1;
	first->num = ft_atoi(av[i - 1]);
	while (i < ac)
	{
		if (!(first->next = malloc(sizeof(t_stk))))
			return (NULL);
		first->next->head = head;
		first->next->num = ft_atoi(av[i]);
		first->next->next = NULL;
		first = first->next;
		i++;
	}
	return (head);
}

t_pushswap			*create_stacks(int ac, char **av, char *param)
{
	t_pushswap *ps;

	if (!(ps = malloc(sizeof(t_pushswap))))
		error_out(ps);
	ps->b = create_data(ac, av, 'b', param);
	if (!(ps->a = create_data(ac, av, 'a', param)))
		error_out(ps);
	if (!ps->a || !ps->b)
		error_out(ps);
	create_analyse_struct(ps);
	ps->quant_nums = param == NULL ? ac - 1 : ac;
	ps->a->head = ps->a;
	if (create_sorted_array(ps) != 1)
		error_out(ps);
	return (ps);
}

void				free_ps(t_pushswap *ps)
{
	t_stk *tmp;

	if (ps)
	{
		while (ps->a)
		{
			tmp = ps->a->next;
			ft_memdel((void **)&ps->a);
			ps->a = tmp;
		}
		ft_memdel((void **)&ps->a);
		while (ps->b)
		{
			tmp = ps->b->next;
			ft_memdel((void **)&ps->b);
			ps->b = tmp;
		}
		if (ps->analyse->sorted_arr)
			ft_memdel((void **)&ps->analyse->sorted_arr);
		if (ps->analyse)
			ft_memdel((void **)&ps->analyse);
		ft_memdel((void **)&ps->b);
		ft_memdel((void **)&ps);
	}
}

void				error_out(t_pushswap *ps)
{
	free_ps(ps);
	write(2, "Error\n", 7);
	exit(1);
}
