/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youncho <youncho@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/15 21:42:31 by youncho           #+#    #+#             */
/*   Updated: 2021/06/20 10:51:15 by youncho          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//Fixme: comment out -> makefile/WFLAG

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
	//Todo: Impl swap algorithms
	int		*arr;
	int		i;
	t_node	*n;

	if (check_sorted(ps->a))
		return ;
	i = ps->a->size;
	arr = (int *)malloc(sizeof(int) * i);
	if (!arr)
		error_exit();
	n = ps->a->head;
	while (i--)
	{
		arr[ps->a->size - i - 1] = n->val;
		n = n->next;
	}
	arr_qsort(arr, 0, ps->a->size - 1);
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
	push_swap(&ps);
	return (0);
}
