/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youncho <youncho@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/15 21:42:31 by youncho           #+#    #+#             */
/*   Updated: 2021/06/24 17:31:49 by youncho          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

//	Fixme: comment out -> makefile/WFLAG
//	python3 push_swap_visualizer/pyviz.py `ruby -e "puts (-250..249).to_a.shuffle.join(' ')"`

void		push_swap(t_ps *ps)
{
	int		i;
	t_node	*n;

	if (check_sorted(ps->a))
		return ;
	ps->arr = (int *)malloc(sizeof(int) * ps->a->size);
	ps->tmp = (int *)malloc(sizeof(int) * ps->a->size);
	if (!ps->arr || !ps->tmp)
		error_exit(ps);
	n = ps->a->head;
	i = -1;
	while (++i < (int)ps->a->size)
	{
		ps->tmp[i] = n->val;
		ps->arr[i] = n->val;
		n = n->next;
	}
	arr_qsort(ps->arr, 0, ps->a->size - 1);
	if (ps->size <= 3)
		least_case_sort(ps);
	else
		solve(ps, ps->a, ps->b, ps->min);
}

int			main(int argc, char **argv)
{
	t_stack	*a;
	t_stack *b;
	t_ps	*ps;
	char 	**args;

	if (argc < 2)
		return (0);
	a = (t_stack *)ft_calloc(1, sizeof(t_stack)); //Init all var to 0
	b = (t_stack *)ft_calloc(1, sizeof(t_stack));
	ps = (t_ps *)ft_calloc(1, sizeof(t_ps));
	a->name = 'a';
	b->name = 'b';
	ps->a = a;
	ps->b = b;
	if (argc == 2)
	{
		args = ft_split(argv[1], ' ');
		parse_arg(ps, args, argc);
	}
	else if (argc > 2)
		parse_arg(ps, argv, argc);
	check_dup(ps);
	ps->size = a->size;
	push_swap(ps);
	return (free_all(ps));
}
