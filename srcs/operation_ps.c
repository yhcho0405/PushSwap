/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_ps.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youncho <youncho@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/20 05:58:10 by youncho           #+#    #+#             */
/*   Updated: 2021/06/24 07:46:27 by youncho          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	pa(t_ps *ps)
{
	if (ps->b->size < 1)
		return ;
	push(ps->a, pop(ps->b));
	if (!ps->is_chk)
		ft_printf("pa\n");
}

void	pb(t_ps *ps)
{
	if (ps->a->size < 1)
		return ;
	push(ps->b, pop(ps->a));
	if (!ps->is_chk)
		ft_printf("pb\n");
}

void	sx(t_stack *x)
{
	t_node *pop_x;

	if (x->size < 2)
		return ;
	pop_x = pop(x);
	push(x, pop_x);
	push(x, pop_x);
	if (x->name)
		ft_printf("s%c\n", x->name);
}

void	ss(t_ps *ps)
{
	t_node *pop_a;
	t_node *pop_b;

	if (ps->a->size >= 2)
	{
		pop_a = pop(ps->a);
		push(ps->a, pop_a);
		push(ps->a, pop_a);
	}
	if (ps->b->size >= 2)
	{
		pop_b = pop(ps->b);
		push(ps->b, pop_b);
		push(ps->b, pop_b);
	}
	if (!ps->is_chk && ps->a->size >= 2 || ps->b->size >= 2)
		ft_printf("ss\n");
}
