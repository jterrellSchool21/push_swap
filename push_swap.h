//
// Created by Ivan Belenko on 13.05.2020.
//

#ifndef PUSH_SWAP_PUSH_SWAP_H
#define PUSH_SWAP_PUSH_SWAP_H

#define ABS(x) (x >= 0) ? x : -x

int 	COUNT;
int 	*MAX;
int 	*MIN;
int 	HEAD;
int 	BACK;
int 	RESULT;

typedef	struct	s_swap
{
	int				elem;
	char 			k;
	struct s_swap	*next;
}				t_swap;

void	RaiseError(int err);
int		size_of_list(t_swap *tmp);
void	print_list(t_swap *tmp);
void	add_new_elem(t_swap *tmp, int new_elem, char l);
t_swap	*new_list(char **array, char k);
void	s(t_swap *tmp);
void	ss(t_swap *tmp1, t_swap *tmp2);
int		stack_del_top(t_swap **frame);
void	stack_add_top(t_swap **frame, int element);
void	p(t_swap **tmp1, t_swap **tmp2);	// from tmp2 to tmp1
void	stack_add_end(t_swap **frame, int element);
int		stack_del_end(t_swap **frame);
void	r(t_swap **tmp);
void	rr(t_swap **tmp1, t_swap **tmp2);
void	rr_a_b(t_swap **tmp);
void	rrr(t_swap **tmp1, t_swap **tmp2);
int 	check(char *str);
int 	*quick_sort(int *array, int size);
void	print_massive(int *array, int size);
int 	*new_sort(char **argv);
int 	find_central(int *list, int size);
void	under_median(t_swap **a, t_swap **b, int median);
void	find_min(t_swap *a);
void	sort_list(t_swap **a, t_swap **b, int *list, int size);


#endif //PUSH_SWAP_PUSH_SWAP_H
