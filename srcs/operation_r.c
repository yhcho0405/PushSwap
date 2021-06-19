/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_r.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youncho <youncho@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/20 05:58:11 by youncho           #+#    #+#             */
/*   Updated: 2021/06/20 07:27:51 by youncho          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rx(t_stack *x)
{
	if (x->size < 2)
		return ;
	x->head = x->head->next;
	ft_printf("r%c\n", x->name);
}

void	rr(t_ps *ps)
{
	if (ps->a->size >= 2)
		ps->a->head = ps->a->head->next;
	if (ps->b->size >= 2)
		ps->b->head = ps->b->head->next;
	ft_printf("rr\n");
}

void	rrx(t_stack *x)
{
	if (x->size < 2)
		return ;
	x->head = x->head->prev;
	ft_printf("rr%c\n", x->name);
}

void	rrr(t_ps *ps)
{
	if (ps->a->size >= 2)
		ps->a->head = ps->a->head->prev;
	if (ps->b->size >= 2)
		ps->b->head = ps->b->head->prev;
	ft_printf("rrr\n");
}
