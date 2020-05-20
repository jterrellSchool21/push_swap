#include <stdio.h>
#include "libft.h"
#include <stdlib.h>
#include "push_swap.h"

void	free_list(t_swap **tmp)
{
	if (!((*tmp)->next))
	{
		*tmp = NULL;
		free(*tmp);
	}
}

void	refresh()
{
	BACK = 0;
	HEAD = 0;
}

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

void	add_new_elem(t_swap *tmp, int new_elem, char l)
{
	tmp->elem = new_elem;
	tmp->k = l;
	tmp->next = (t_swap*)malloc(sizeof(t_swap));
}

t_swap	*new_list(char **array, char k)
{
	t_swap	*t;
	t_swap	*head;
	int		i;

	i = 1;
	if (!(t = (t_swap*)malloc(sizeof(t_swap))))
		RaiseError(2);
	head = t;
	t->next = NULL;
	if (array != NULL)
		while (array[i])
		{
			add_new_elem(t, ft_atoi(array[i]), k);
			t = t->next;
			i++;
		}
	else
		add_new_elem(t, 0, k);
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
	COUNT++;
//	if ((*head).k == 'a')
//		printf("sa\n");
//	else
//		printf("sb\n");
}

void	ss(t_swap *tmp1, t_swap *tmp2)
{
	s(tmp1);
	s(tmp2);
	COUNT++;
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

void	p(t_swap **tmp1, t_swap **tmp2)
{
	if (*tmp2)
		stack_add_top(tmp1, stack_del_top(tmp2));
	COUNT++;
//	if ((*tmp2)->k == 'a')
//		printf("pa\n");
//	else
//		printf("pb\n");
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
	COUNT++;
//	if ((*tmp)->k == 'a')
//		printf("ra\n");
//	else
//		printf("rb\n");
}

void	rr(t_swap **tmp1, t_swap **tmp2)
{
	r(tmp1);
	r(tmp2);
	COUNT++;
}

void	rr_a_b(t_swap **tmp)
{
	stack_add_top(tmp, stack_del_end(tmp));
	COUNT++;
//	if ((*tmp)->k == 'a')
//		printf("rra\n");
//	else
//		printf("rrb\n");
}

void	rrr(t_swap **tmp1, t_swap **tmp2)
{
	stack_add_top(tmp1, stack_del_end(tmp1));
	stack_add_top(tmp2, stack_del_end(tmp2));
	COUNT++;
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

int 	find_central(int *list, int size)
{
	int 	result;

	result = list[size / 2];
	return (result);
}

void	find_min(t_swap *a)
{
	int		i;
	int 	minimum;
	int 	size;

	minimum = INT32_MAX;
	i = 0;
	size = size_of_list(a);
	while (a->next)
	{
		if (minimum >= a->elem)
		{
			minimum = a->elem;
			MIN[0] = i;
		}
		i++;
		a = a->next;
	}
	MIN[1] = size - MIN[0];
}

void	find_max(t_swap *a)
{
	int		i;
	int 	maximum;
	int 	size;

	maximum = a->elem;
	i = 0;
	size = size_of_list(a);
	while (a->next)
	{
		if (maximum <= a->elem)
		{
			maximum = a->elem;
			MAX[0] = i;
		}
		i++;
		a = a->next;
	}
	MAX[1] = size - MAX[0];
}

void	under_median(t_swap **a, t_swap **b, int median)
{
	int 	size;
	int 	i;
	int 	cnt;
	int 	size1;

	i = 0;
	size = size_of_list(*a);
	cnt = 0;
	size1 = size / 2;
	while (i < size)
	{
		if (cnt == size1)
			break;
		if ((*a)->elem < median)
		{
			p(b, a);
			printf("pb\n");
			size--;
			i--;
			cnt++;
		}
		else
		{
			r(a);
			printf("ra\n");
		}
		i++;
	}
}

void	sort_push(t_swap **a, t_swap **b)
{

	if ((*b)->elem > (*b)->next->elem)
		s(*b);
	while (*b)
	{
		find_min(*b);
		if (MIN[0] < MIN[1])
		{
			while (MIN[0] != 0)
			{
				r(b);
				printf("rb\n");
				MIN[0]--;
			}
			p(a, b);
			printf("pb\n");
			r(a);
			printf("ra\n");
			MIN[1] = 0;
			BACK++;
		}
		else
		{
			while (MIN[1] != 0)
			{
				rr_a_b(b);
				printf("rrb\n");
				MIN[1]--;
			}
			p(a, b);
			printf("pb\n");
			r(a);
			printf("ra\n");
			MIN[0] = 0;
			BACK++;
		}
		if (*b)
		{
			find_max(*b);
			if (MAX[0] < MAX[1])
			{
				while (MAX[0] != 0)
				{
					r(b);
					printf("rb\n");
					MAX[0]--;
				}
				p(a, b);
				printf("pb\n");
				MAX[1] = 0;
				HEAD++;
			}
			else
			{
				while (MAX[1] != 0)
				{
					rr_a_b(b);
					printf("rrb\n");
					MAX[1]--;
				}
				p(a, b);
				printf("pb\n");
				MAX[0] = 0;
				HEAD++;
			}
		}
		else
			break;
	}
//	free_list(b);
//	*b = new_list(NULL, 'b');
	RESULT = HEAD + BACK;
	while (HEAD > 0)
	{
		r(a);
		printf("ra\n");
		HEAD--;
	}
	refresh();
}

void	sort_push_a(t_swap **a, t_swap **b)
{

}

int 	sorted(t_swap *a)
{
	while (a->next->next)
	{
		if (a->elem - a->next->elem > 0)
			return (0);
		a = a->next;
	}
	return (1);
}

void	sort_list(t_swap **a, t_swap **b, int *list, int size) {
	int		central;
	int 	flag;

	central = find_central(list, size);
	under_median(a, b, central);
	if ((*a)->elem > (*a)->next->elem)
	{
		s(*a);
		printf("sa\n");
	}
	flag = sorted(*a);
	sort_push(a, b);
	if (flag)
	{
		while (RESULT < size)
		{
			r(a);
			printf("ra\n");
			RESULT++;
		}
	}
	else
	{
		while (RESULT > 0)
		{
			p(b, a);
			printf("pa\n");
			RESULT--;
		}
		sort_push(a, b);
	}
}

int		main(int argc, char *argv[])
{
	t_swap	*a;
	t_swap	*b;
	int 	*list;

	COUNT = 0;
	refresh();
	MIN = (int*)malloc(sizeof(int) * 2);
	MAX = (int*)malloc(sizeof(int) * 2);
	if (argc < 2)
		RaiseError(1);
	a = new_list(argv, 'a');
	b = new_list(NULL, 'b');
	print_list(a);
	print_list(b);
	list = new_sort(&argv[1]);
	if (!(sorted(a)))
		sort_list(&a, &b, list, argc - 1);
	print_list(a);
	print_list(b);
	printf("%d\n", COUNT);
}