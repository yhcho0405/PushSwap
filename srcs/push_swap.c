/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youncho <youncho@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/15 21:42:31 by youncho           #+#    #+#             */
/*   Updated: 2021/06/20 05:24:48 by youncho          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Todo: comment out -> makefile/WFLAG

void	parse_arg(t_stack *a, char **arg, int ac)
{
	int i;

	i = 1;
	if (ac == 2)
		i = 0;
	while (arg[i])
	{
		append(a, new_node(get_int(arg[i])));
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

void	push_swap(t_stack *a, t_stack *b)
{

}

int		main(int argc, char **argv)
{
	t_stack	*a;
	t_stack *b;
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
	push_swap(a, b);
	return (0);
}
