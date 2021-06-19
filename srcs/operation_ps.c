/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_ps.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youncho <youncho@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/20 05:58:10 by youncho           #+#    #+#             */
/*   Updated: 2021/06/20 08:07:04 by youncho          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_ps *ps)
{
	t_node *pop_b;

	if (ps->b->size < 1)
		return ;
	pop_b = pop(ps->b);
	push(ps->a, pop_b->val);
	free(pop_b);
	ft_printf("pa\n");
}

void	pb(t_ps *ps)
{
	t_node *pop_a;

	if (ps->a->size < 1)
		return ;
	pop_a = pop(ps->a);
	push(ps->b, pop_a->val);
	free(pop_a);
	ft_printf("pb\n");
}

void	sx(t_stack *x)
{
	t_node *pop_x1;
	t_node *pop_x2;

	if (x->size < 2)
		return ;
	pop_x1 = pop(x);
	pop_x2 = pop(x);
	push(x, pop_x1->val);
	push(x, pop_x2->val);
	free(pop_x1);
	free(pop_x2);
	ft_printf("s%c\n", x->name);
}

void	ss(t_ps *ps)
{
	t_node *pop_a1;
	t_node *pop_a2;
	t_node *pop_b1;
	t_node *pop_b2;

	if (ps->a->size >= 2)
	{
		pop_a1 = pop(ps->a);
		pop_a2 = pop(ps->a);
		push(ps->a, pop_a1->val);
		push(ps->a, pop_a2->val);
		free(pop_a1);
		free(pop_a2);
	}
	if (ps->b->size >= 2)
	{
		pop_b1 = pop(ps->b);
		pop_b2 = pop(ps->b);
		push(ps->b, pop_b1->val);
		push(ps->b, pop_b2->val);
		free(pop_b1);
		free(pop_b2);
	}
	if (ps->a->size >= 2 || ps->b->size >= 2)
		ft_printf("ss\n");
}
