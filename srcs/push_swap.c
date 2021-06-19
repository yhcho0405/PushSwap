/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youncho <youncho@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/15 21:42:31 by youncho           #+#    #+#             */
/*   Updated: 2021/06/19 21:12:48 by youncho          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Todo: comment out -> makefile/WFLAG

void	parse_arg(t_stack *a, char *str)
{
	char **args;
	int i;

	args = ft_split(str, ' ');
	i = -1;
	while (args[++i])
	{
		printf("%d\n", get_int(args[i]));
	}
}

int		main(int argc, char **argv)
{
	t_stack	*a;
	t_stack *b;

	if (argc < 2)
		return (0);
	a = (t_stack *)ft_calloc(1, sizeof(t_stack));
	b = (t_stack *)ft_calloc(1, sizeof(t_stack));
	if (argc == 2)
		parse_arg(a, argv[1]);
	else if (argc > 2)
	{
		;
	}
	return (0);
}
