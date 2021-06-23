/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youncho <youncho@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/15 21:42:31 by youncho           #+#    #+#             */
/*   Updated: 2021/06/23 12:37:02 by youncho          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

//	Fixme: comment out -> makefile/WFLAG
//	python3 push_swap_visualizer/pyviz.py `ruby -e "puts (-250..249).to_a.shuffle.join(' ')"`

void	parse_arg(t_stack *a, char **arg, int ac)
{
	int i;

	i = 1;
	if (ac == 2)
		i = 0;
	while (arg[i])
	{
		append(a, get_int(arg[i]));
		if (ac == 2)
			free(arg[i]);
		i++;
	}
	if (ac == 2)
		free(arg);
}

void	check_dup(t_stack *st)
{
	int		i;
	t_node *j;
	t_node *k;

	i = -1;
	j = st->head;
	while (++i < st->size)
	{
		k = j->next;
		while (j != k)
		{
			if (j->val == k->val)
				error_exit();
			k = k->next;
		}
		j = j->next;
	}
}

void	push_swap(t_ps *ps)
{
	int		i;
	t_node	*n;

	if (check_sorted(ps->a))
		return ;
	ps->arr = (int *)malloc(sizeof(int) * ps->a->size);
	ps->tmp = (int *)malloc(sizeof(int) * ps->a->size);
	if (!ps->arr || !ps->tmp)
		error_exit();
	n = ps->a->head;
	i = -1;
	while (++i < ps->a->size)
	{
		ps->tmp[i] = n->val;
		ps->arr[i] = n->val;
		n = n->next;
	}
	arr_qsort(ps->arr, 0, ps->a->size - 1);
	if (ps->size == 2)
		sx(ps->a);
	else
		solve(ps, ps->a, ps->b, ps->min);
	//	TODO: deallocated
}

int		main(int argc, char **argv)
{
	t_stack	*a;
	t_stack *b;
	t_ps	ps;
	char 	**args;

	if (argc < 2)
		return (0);
	a = (t_stack *)ft_calloc(1, sizeof(t_stack)); //Init all var to 0
	b = (t_stack *)ft_calloc(1, sizeof(t_stack));
	a->name = 'a';
	b->name = 'b';
	if (argc == 2)
	{
		args = ft_split(argv[1], ' ');
		parse_arg(a, args, argc);
	}
	else if (argc > 2)
		parse_arg(a, argv, argc);
	check_dup(a);
	ps.a = a;
	ps.b = b;
	ps.size = a->size;
	push_swap(&ps);
	return (0);
}
