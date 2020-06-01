/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_main.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jterrell <jterrell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/01 14:15:32 by jterrell          #+#    #+#             */
/*   Updated: 2020/06/01 14:19:47 by jterrell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

static void			handle_start_args(int ac, char **av, t_pushswap **ps)
{
	char		**str_av;
	int			arr_size;

	if (ac == 2)
	{
		str_av = parse_string_arg(av[1]);
		arr_size = find_2d_arr_size(str_av);
		if (!str_av || check_validity(arr_size, str_av, 0, 0) != 1 ||
		!(*ps = create_stacks(arr_size, str_av, "str")))
			error_out(*ps);
		memfree(str_av, arr_size);
	}
	else if (check_validity(ac, av, 1, 0) != 1 ||
	!(*ps = create_stacks(ac, av, NULL)))
		error_out(*ps);
}

int					main(int ac, char **av)
{
	char			*line;
	t_pushswap		*ps;

	line = NULL;
	ps = NULL;
	if (ac <= 1)
		exit(1);
	handle_start_args(ac, av, &ps);
	while (get_next_line(0, &line))
	{
		if (check_instructions(line) != 1)
		{
			free(line);
			error_out(ps);
		}
		else
			execute_instruction(ps, line, 0);
		free(line);
	}
	if (check_order(ps) == 1)
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	free_ps(ps);
	return (0);
}
