/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youncho <youncho@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/24 07:39:35 by youncho           #+#    #+#             */
/*   Updated: 2021/06/24 08:42:12 by youncho          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	move_checker(t_ps *ps, int op)
{
	if (op == O_SA)
		sx(ps->a);
	else if (op == O_SB)
		sx(ps->b);
	else if (op == O_SS)
		ss(ps);
	else if (op == O_PA)
		pa(ps);
	else if (op == O_PB)
		pb(ps);
	else if (op == O_RA)
		rx(ps->a);
	else if (op == O_RB)
		rx(ps->b);
	else if (op == O_RR)
		rr(ps);
	else if (op == O_RRA)
		rrx(ps->a);
	else if (op == O_RRB)
		rrx(ps->b);
	else if (op == O_RRR)
		rrr(ps);
}

void	checker(t_ps *ps)
{
	char		*line;
	const char	*op[12] = {"sa", "sb", "ss", "pa", "pb",
							"ra", "rb", "rr", "rra", "rrb", "rrr", NULL};
	int			i;

	while (get_next_line(0, &line) > 0)
	{
		i = 0;
		while (op[i] && ft_strncmp(op[i], line, 4))
			i++;
		if (i != 11)
			move_checker(ps, i);
		else
			error_exit();
	}
	if (!ps->b->size && check_sorted(ps->a))
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
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
	ps.is_chk = 1;
	checker(&ps);
	return (0);
}
