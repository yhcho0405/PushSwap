/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youncho <youncho@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/15 21:42:31 by youncho           #+#    #+#             */
/*   Updated: 2021/06/20 07:31:35 by youncho          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Todo: comment out -> makefile/WFLAG

/*
**	sa : swap a - 스택 a의 가장 위에 있는 두 원소(혹은 첫 번쨰 원소와 두 번째 원소)의 위치를 서로 바꾼다.
**	sb : swap b - 스택 b의 가장 위에 있는 두 원소(혹은 첫 번쨰 원소와 두 번째 원소)의 위치를 서로 바꾼다.
**	ss : sa와 sb를 동시에 실행한다.
**
**	pa : push a - 스택 b에서 가장 위(탑)에 있는 원소를 가져와서, 스택 a의 맨 위(탑)에 넣는다. 스택 b가 비어 있으면 아무 것도 하지 않는다.
**	pb : push b - 스택 a에서 가장 위(탑)에 있는 원소를 가져와서, 스택 b의 맨 위(탑)에 넣는다. 스택 a가 비어있으면 아무 것도 하지 않는다.
**
**	ra : rotate a - 스택 a의 모든 원소들을 위로 1 인덱스 만큼 올린다. 첫 번째 원소(탑)는 마지막 원소(바텀)가 된다.
**	rb : rotate b - 스택 b의 모든 원소들을 위로 1 인덱스 만큼 올린다. 첫 번째 원소(탑)는 마지막 원소(바텀)가 된다.
**	rr : ra와 rb를 동시에 실행한다.
**
**	rra : reverse rotate a - 스택 a의 모든 원소들을 아래로 1 인덱스 만큼 내린다. 마지막 원소(바텀)는 첫 번째 원소(탑)가 된다.
**	rrb : reverse rotate b - 스택 b의 모든 원소들을 아래로 1 인덱스 만큼 내린다. 마지막 원소(바텀)는 첫 번째 원소(탑)가 된다.
**	rrr : rra와 rrb를 동시에 실행한다.
*/

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
