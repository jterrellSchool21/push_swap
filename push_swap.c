#include <stdio.h>
#include "libft.h"
#include <stdlib.h>

//sa sb ss						- done!
//pa pb							- done!
//ra rb rr						- done!
//rra rrb rrr					- done!
//algorithm :
//	1. Median value sort		- done!
//	2. Median value find in
//		my list					- in action

void	RaiseError(int err)
{
	if (err == 0)
		ft_putstr(">> Bad array on input, check it and try again\n");
	if (err == 1)
		ft_putstr(">> Please enter array on std input\n");
	if (err == 2)
		ft_putstr(">> Failed with allocation memory, try again\n");
	if (err == 3)
		ft_putstr(">> Not valid format of array or array is empty\n");
	exit(1);
}

typedef	struct	s_swap
{
	int				elem;
	int 			sort;
	struct s_swap	*next;
}				t_swap;

int		size_of_list(t_swap *tmp)
{
	t_swap	*head;
	int		i;

	i = 0;
	head = tmp;
	while (head->next)
	{
		i++;
		head = head->next;
	}
	return (i);
}

void	print_list(t_swap *tmp)
{
	t_swap	*head;
	int		i;

	head = tmp;
	i = 0;
	printf("\n");
	if (head && head->next)
	{
		while (head->next/* && i < 5*/) {
			printf("list[%d] = %d\t", i, head->elem);
			head = head->next;
			i++;
		}
	}
	else if (head)
		printf("list[0] = %d\n", head->elem);
}

void	add_new_elem(t_swap *tmp, int new_elem)
{
	tmp->elem = new_elem;
	tmp->sort = 0;
	tmp->next = (t_swap*)malloc(sizeof(t_swap));
}

t_swap	*new_list(char **array)
{
	t_swap	*t;
	t_swap	*head;
	int		i;

	i = 1;
	if (!(t = (t_swap*)malloc(sizeof(t_swap))))
		return (NULL);
	head = t;
	t->next = NULL;
	if (array != NULL)
		while (array[i])
		{
			add_new_elem(t, ft_atoi(array[i]));
			t = t->next;
			i++;
		}
	else
		add_new_elem(t, 0);
	t->next = NULL;
	return (head);
}

void	s(t_swap *tmp)
{
	t_swap	*head;

	head = tmp;
	if (size_of_list(head) >= 2)
	{
		head->elem ^= head->next->elem ^= head->elem ^= head->next->elem;
	}
}

void	ss(t_swap *tmp1, t_swap *tmp2)
{
	s(tmp1);
	s(tmp2);
}

int		stack_del_top(t_swap **frame)
{
	t_swap	*curr;
	int 	x;

	x = (*frame)->elem;
	curr = (*frame)->next;
	free((*frame));
	(*frame) = curr;
	return (x);
}

void	stack_add_top(t_swap **frame, int element)
{
	t_swap	*new;
	t_swap	**tmp;

	if (!(new = (t_swap*)malloc(sizeof(t_swap))))
		RaiseError(2);
	tmp = frame;
	if (*tmp)
	{
		new->next = *tmp;
		new->elem = element;
		*tmp = new;
	}
}

void	p(t_swap **tmp1, t_swap **tmp2)	// from tmp2 to tmp1
{
	stack_add_top(tmp1, stack_del_top(tmp2));
}

void	stack_add_end(t_swap **frame, int element)
{
	t_swap	*top;
	t_swap	*new;

	top = *frame;
	if (!(new = (t_swap*)malloc(sizeof(t_swap))))
		RaiseError(2);
	new->next = NULL;
	while ((*frame)->next)
		*frame = (*frame)->next;
	(*frame)->next = new;
	(*frame)->elem = element;
	*frame = top;
}

int		stack_del_end(t_swap **frame)
{
	t_swap	*top;
	t_swap	**head;
	t_swap	*mid;
	int 	x;

	top = *frame;
	head = frame;
	while ((*frame)->next->next->next)
	{
		*frame = (*frame)->next;
	}
	//print_list(*frame);
	x = (*frame)->next->elem;
	*head = (*frame)->next;
	(*frame)->next = NULL;
	*frame = top;
	return (x);
}

void	r(t_swap **tmp)
{
	t_swap	**head;
	t_swap	*main;
	int 	x;

	x = (*tmp)->elem;
	stack_del_top(tmp);
	stack_add_end(tmp, x);
}

void	rr(t_swap **tmp1, t_swap **tmp2)
{
	r(tmp1);
	r(tmp2);
}

void	rr_a_b(t_swap **tmp)
{
	stack_add_top(tmp, stack_del_end(tmp));
}

void	rrr(t_swap **tmp1, t_swap **tmp2)
{
	stack_add_top(tmp1, stack_del_end(tmp1));
	stack_add_top(tmp2, stack_del_end(tmp2));
}

int 	check(char *str)
{
	int 	i;

	i = 0;
	while (str[i])
	{
		if ((str[i] >= 48 && str[i] < 58) || (str[i] == '-' && i == 0))
			i++;
		else
			RaiseError(0);
	}
	return (1);
}

int 	*quick_sort(int *array, int size)
{
	int 	left;
	int 	right;
	int 	central;
	int 	tmp;

	central = array[size / 2];
	left = 0;
	right = size - 1;
	do
	{
		while (array[left] < central)
			left++;
		while (array[right] > central)
			right--;
		if (left <= right)
		{
			tmp = array[right];
			array[right] = array[left];
			array[left] = tmp;
		}
		left++;
		right--;
	} while (left < right);
	if (right > 0)
		quick_sort(array, right + 1);
	if (left < size)
		quick_sort(&array[left], size - left);
	return (array);
}

void	print_massive(int *array, int size)
{
	int 	i;

	i = 0;
	while (i < size)
		printf("%d\t", array[i++]);
	printf("\n");
}

int 	*new_sort(char **argv)
{
	int 	*result;
	int 	len;
	int 	i;

	len = 0;
	while (argv[len])
	{
		if (check(argv[len]))
			len++;
		else
		{
			RaiseError(3);
		}
	}
	result = (int*)malloc(sizeof(int) * len);
	i = 0;
	while (argv[i])
	{
		result[i] = ft_atoi(argv[i]);
		i++;
	}
	print_massive(result, len);
	return (quick_sort(result, len));
}

int 	find_central(t_swap *tmp, int *list)
{
	int 	i;
	int 	size;

	size = size_of_list(tmp);
	i = 0;
	while (tmp->elem != list[size / 2])
	{
		tmp = tmp->next;
		i++;
	}
	printf("central %d = %d\n", i, tmp->elem);
	return (tmp->elem);
}

int		under_median(t_swap **a, t_swap **b, int median)
{
	int 	size;
	int 	i;
	int 	in_b;

	i = 0;
	size = size_of_list(*a);
	in_b = 0;
	while (i < size)
	{
		if ((*a)->elem > median)
		{
			p(b, a);
			in_b++;
			i--;
		}
		else
			r(a);
		i++;
	}
	return (in_b);
}

int		sorted(t_swap *tmp)
{
	int		x;
	int 	i;

	x = tmp->elem;
	i = 0;
	while (tmp->next)
	{
		tmp = tmp->next;
		if (x > tmp->elem)
		{
			return (0);
		}
		i++;
		x = tmp->elem;
	}
	return (1);
}

int 	min(t_swap *a, int start)
{
	int 	res;
	int 	i;

	res = a->elem;
	i = 0;
	while (a->next)
	{
		if (i >= start)
		{
			if (res < a->elem)
				res = a->elem;
		}
		else
			i++;

		a = a->next;
	}
	return (res);
}

void	sort_ost_a(t_swap **a, t_swap **b)
{
	int 	i;
	int 	size;
	int 	minimum;

	size = size_of_list(*a);
	i = 0;
	print_list(*a);
	while (i < size)
	{
		minimum = min(*a, i);
		printf("minimum = %d\n", minimum);
		if ((*a)->elem == minimum)
		{
			p(b ,a);
			p(a, b);
			i++;
		}
		else
		{
			r(a);
		}
	}
}

void	sort_list(t_swap **a, t_swap **b, int *list)
{
	int 	central;
	t_swap	*head_a;
	t_swap	*head_b;
	int 	in_b;

	head_a = *a;
	head_b = *b;
	in_b = 0;
	while (/*b && */!(sorted(*a)))
	{
		central = find_central(head_a, list);
//		central = 1;
		in_b = under_median(a, b, central);
		printf("in_b = %d\n", in_b);
		sort_ost_a(a, b);
	}

}

//do
//{
//while (array[left] < central)
//left++;
//while (array[right] > central)
//right--;
//if (left <= right)
//{
//tmp = array[right];
//array[right] = array[left];
//array[left] = tmp;
//}
//left++;
//right--;
//} while (left < right);
//if (right > 0)
//quick_sort(array, right + 1);
//if (left < size)
//quick_sort(&array[left], size - left);
//return (array);


int		main(int argc, char *argv[])
{
	t_swap	*a;
	t_swap	*b;
	int 	*list;

	if (argc < 2)
		RaiseError(1);
	a = new_list(argv);
	b = new_list(NULL);
	list = new_sort(&argv[1]);
	print_massive(list, argc - 1);
	print_list(a);
	print_list(b);
//	r(&a);
	sort_list(&a, &b, list);
	print_list(a);
	print_list(b);
}

//1 4 6 7 2 5 4