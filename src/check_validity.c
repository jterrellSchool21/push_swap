/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_validity.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jterrell <jterrell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/01 14:15:20 by jterrell          #+#    #+#             */
/*   Updated: 2020/06/01 14:18:05 by jterrell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int				check_duplicates(int ac, char **av, int start_num)
{
	int i;
	int j;

	i = start_num;
	while (i < ac)
	{
		j = i + 1;
		while (j < ac)
		{
			if (ft_atoi(av[i]) == ft_atoi(av[j]))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int				check_nums(int ac, char **av, int start_num)
{
	int					i;
	int					j;
	long long int		num;

	j = 0;
	i = start_num;
	while (i < ac)
	{
		num = ft_atoi_long_long(av[i]);
		if (num > INT_MAX || num < INT_MIN)
			return (0);
		j = 0;
		while (av[i][j] != '\0')
		{
			if (j == 0 && av[i][j] == '-')
				j++;
			if (ft_isdigit(av[i][j]) != 1)
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int				check_instructions(char *av)
{
	char		**commands;
	int			j;

	commands = (char *[22]){"sa\n", "sb\n", "ss\n", "pa\n", "pb\n", "ra\n",
		"rb\n", "rr\n", "rra\n", "rrb\n", "rrr\n", "sa", "sb", "ss", "pa",
		"pb", "ra", "rb", "rr", "rra", "rrb", "rrr"};
	j = 0;
	while (j < 22)
	{
		if (ft_strequ(commands[j], av) == 1)
			return (1);
		j++;
	}
	return (0);
}

int				check_order_args(int ac, char **av, int start_num)
{
	int i;

	i = start_num;
	while (i < ac)
	{
		if ((i + 1 < ac) && ft_atoi(av[i]) > ft_atoi(av[i + 1]))
			return (1);
		i++;
	}
	exit(1);
}

int				check_validity(int ac, char **av, int start_num, int flag_ch_ps)
{
	if (check_nums(ac, av, start_num) == 0)
		return (0);
	if (check_duplicates(ac, av, start_num) == 0)
		return (0);
	if (flag_ch_ps)
		if (check_order_args(ac, av, start_num) == 0)
			return (0);
	return (1);
}
