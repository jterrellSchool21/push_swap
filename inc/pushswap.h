/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jterrel <jterrell@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/22 16:24:28 by jterrell          #+#    #+#             */
/*   Updated: 2020/06/01 14:19:47 by jterrell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H
# define PUSHSWAP_H
# include "libft.h"
# include <stdarg.h>
# include <string.h>
# include <stdio.h>
# include <limits.h>
# include <float.h>
# include <fcntl.h>

typedef struct			s_stk
{
	int					num;
	struct s_stk		*head;
	struct s_stk		*next;
}						t_stk;

typedef struct			s_analyse
{
	int					sa;
	int					sb;
	int					ss;
	int					pa;
	int					pb;
	int					ra;
	int					rb;
	int					rr;
	int					rra;
	int					rrb;
	int					rrr;
	int					instructions;
	int					*sorted_arr;
}						t_analyse;

typedef struct			s_ps
{
	t_stk				*a;
	t_stk				*b;
	int					quant_nums;
	int					chunks;
	int					*order;
	t_analyse			*analyse;

}						t_pushswap;
/*
** check_validity.c
*/
int						check_order_args(int ac, char **av, int start_num);
int						check_validity(int ac, char **av, int start_num,
		int flag_ch_ps);
int						check_instructions(char *av);
int						check_nums(int ac, char **av, int start_num);
int						check_duplicates(int ac, char **av, int start_num);
/*
** commands.c
*/
void					ps_sa(t_pushswap *ps, int ps_ch);
void					ps_sb(t_pushswap *ps, int ps_ch);
void					ps_pa(t_pushswap *ps, int ps_ch);
void					ps_pb(t_pushswap *ps, int ps_ch);
/*
** coomands_2.c
*/
void					ps_ra(t_pushswap *ps, int ps_ch);
void					ps_rr(t_pushswap *ps, int ps_ch);
void					ps_rrr(t_pushswap *ps, int ps_ch);
void					ps_ss(t_pushswap *ps, int ps_ch);
/*
** execute_instructions.c
*/
void					execute_instruction(t_pushswap *ps, char *cmd,
		int ps_ch);
void					ps_rrb(t_pushswap *ps, int ps_ch);
void					ps_rra(t_pushswap *ps, int ps_ch);
void					ps_rb(t_pushswap *ps, int ps_ch);
/*
** utils_1.c
*/
t_stk					*create_data(int ac, char **av, char stack,
		char *param);
void					error_out(t_pushswap *ps);
t_pushswap				*create_stacks(int ac, char **av, char *param);
void					free_ps(t_pushswap *ps);
int						check_order(t_pushswap *ps);
/*
** utils_2.c
*/
void					print_stk(t_stk *head, int stack);
int						check_order_simple(t_pushswap *ps, char stack);
int						find_steps_before_num(t_stk *stk, char start_end,
		int quant, int num);
int						find_2d_arr_size(char **arr);
char					**parse_string_arg(char *str);
/*
** lst_tools.c
*/
t_stk					*push(t_stk *head, t_stk *new_head);
t_stk					*remove_elem(t_stk *elem);
void					change_head(t_stk *stack, t_stk *new_head);
t_stk					*append_elem(t_stk *stack, t_stk *elem);
int						find_lst_size(t_stk *head);
/*
** three_five_args.c
*/
void					sort_three_args(t_pushswap *ps);
void					sort_twelve_max_args(t_pushswap *ps);
/*
** solution.c
*/
void					push_back_elements_on_a(t_pushswap *ps);
void					push_swap(t_pushswap *ps);
/*
** analyse.c
*/
int						create_sorted_array(t_pushswap *ps);
void					bubble_sort(int *tab, int size);
void					create_analyse_struct(t_pushswap *ps);
void					print_analyse(t_pushswap *ps);
/*
** solution_utils.c
*/
int						is_num_smaller_than_others(t_stk *stk, int num);
int						find_quant_nums_in_chunk(t_pushswap *ps, int counter);
int						find_the_biggest_num(t_stk *stk);
int						find_index_of_num(t_pushswap *ps, int num);
int						find_holding_numbers(t_pushswap *ps, int chunks,
		int param, int counter);
/*
** solution_utils_2.c
*/
int						show_last_num_in_stk(t_stk *stk);
void					reverse_order_of_chunks(t_pushswap *ps);
int						is_num_in_chunk(int num, t_pushswap *ps,
		int curr_chunk);
void					round_stk_a_before_max_num(t_pushswap *ps, int max,
		int start, int end);

#endif
