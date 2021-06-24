/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youncho <youncho@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/20 12:19:42 by youncho           #+#    #+#             */
/*   Updated: 2021/06/24 07:37:01 by youncho          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_bool	is_corr(t_ps *ps, t_node *a, t_node *b)
{
	if (ps->size <= 1)
		return (false);
	if (a->val < a->prev->val)
		return (a->val > b->val || a->prev->val < b->val);
	if (a->val > b->val && b->val > a->prev->val)
		return (true);
	return (false);
}

int		calc_min(t_ps *ps, t_node *na, t_node *nb, int m)
{
	int i;
	int j;

	i = -1;
	while (++i < ps->a->size)
	{
		j = -1;
		while (++j < ps->b->size)
		{
			if(m > ft_max(i, j) + (ft_min(i, j) * !!(ps->dir % 3))
				&& is_corr(ps, na, nb))
			{
				m = ft_max(i, j) + (ft_min(i, j) * !!(ps->dir % 3));
				ps->move[ps->dir * 2] = i;
				ps->move[ps->dir  * 2 + 1] = j;
			}
			nb = nb->next;
			if (ps->dir % 2)
				nb = nb->prev->prev;
		}
		na = na->prev;
		if (ps->dir < 2)
			na = na->next->next;
	}
	return (m);
}

void	move(t_ps *ps, int dir, t_stack	*s, int m)
{
	int		i;

	while (dir < 4 && ps->min[dir] != m)
		dir++;
	if (ps->move[dir * 2] < ps->move[dir * 2 + 1])
		s = ps->b;
	i = -1;
	while (dir == 0 && ++i < ft_min(ps->move[dir * 2], ps->move[dir * 2 + 1]))
		rr(ps);
	while (dir == 3 && ++i < ft_min(ps->move[dir * 2], ps->move[dir * 2 + 1]))
		rrr(ps);
	while (dir == 0 && i++ < ft_max(ps->move[dir * 2], ps->move[dir * 2 + 1]))
		rx(s);
	while (dir == 3 && i++ < ft_max(ps->move[dir * 2], ps->move[dir * 2 + 1]))
		rrx(s);
	while (dir == 1 && ++i < ps->move[dir * 2])
		rx(ps->a);
	while (dir == 2 && ++i < ps->move[dir * 2])
		rrx(ps->a);
	i = -1;
	while (dir == 1 && ++i < ps->move[dir * 2 + 1])
		rrx(ps->b);
	while (dir == 2 && ++i < ps->move[dir * 2 + 1])
		rx(ps->b);
	pa(ps);
}

void	align(t_ps *ps, t_node *n)
{
	int i;

	i = 0;
	while (n->val != ps->arr[0])
	{
		n = n->next;
		i++;
	}
	while (ps->a->head->val != ps->arr[0])
	{
		if (i <= ps->size / 2)
			rx(ps->a);
		else
			rrx(ps->a);
	}
}

void	solve(t_ps *ps, t_stack *a, t_stack *b, int *m)
{
	int i;

	i = -1;
	while (++i < ps->size && ps->size > 30)
	{
		if (a->head->val < ps->arr[ps->size / 2 - i / 2])
		{
			pb(ps);
			rx(ps->b);
		}
		else if (a->head->val > ps->arr[ps->size / 3 * 2 - i / 3])
			pb(ps);
		else
			rx(a);
	}
	while (a->size > 2)
		pb(ps);
	while (b->size > 0)
	{
		ps->dir = -1;
		while (++ps->dir < 4)
			m[ps->dir] = calc_min(ps, a->head, b->head, INT_MAX);
		move(ps, 0, ps->a, ft_min(m[0], ft_min(m[1], ft_min(m[2], m[3]))));
	}
	align(ps, ps->a->head);
}
