/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youncho <youncho@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/20 12:19:42 by youncho           #+#    #+#             */
/*   Updated: 2021/06/20 22:17:42 by youncho          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"





void	solve(int *arr, t_ps *ps, int size)
{
	int		i, j;
	int		min;
	int		max;
	int	f, b, r, flg;
	t_node *na;
	t_node *nb;
	int div = 11;
	int fst, now, ptr;
	i = -1;
	min = arr[0];
	while (++i < div)
	{
		if (i == 1)
			fst = (size * (i + 1)) / div - 1;
		max = arr[(size * (i + 1)) / div - 1];
		flg = 1;
		ptr = 0;
		while (flg)
		{
			f = 0; b = 0;
			na = ps->a->head;
			while (f <= ps->a->size / 2 + 1 && !(min <= na->val && na->val < max))
			{
				na = na->next;
				f++;
			}
			na = ps->a->head;
			while (b <= ps->a->size / 2 + 1 && !(min <= na->val && na->val < max))
			{
				na = na->prev;
				b++;
			}
			j = -1;
			if (!(f > ps->a->size / 2 + 1 && b > ps->a->size / 2 + 1))
			{
				if (f <= b)
				{
					while (++j < f)
						rx(ps->a);
				}
				else
				{
					while (++j < b)
						rrx(ps->a);
				}
				pb(ps);
			}
			else
				flg = 0;
		}
		while (ptr > 0)
		{
			rrx(ps->b);
			ptr--;
		}
		min = max;
	}
	i = size - 1;
	ptr = 0;
	while (ps->b->size > 1 && --i >= 1)
	{
		int fb[4];
		ft_bzero(fb, sizeof(fb));
		max = arr[i];
		int max2 = arr[i - 1];
		nb = ps->b->head;
		while (nb && nb->val != max)
		{
			nb = nb->next;
			fb[0]++;
		}
		nb = ps->b->head;
		while (nb && i > 1 && nb->val != max2)
		{
			nb = nb->next;
			fb[2]++;
		}
		nb = ps->b->head;
		while (nb && nb->val != max)
		{
			nb = nb->prev;
			fb[1]++;
		}
		nb = ps->b->head;
		while (nb && i > 1 && nb->val != max2)
		{
			nb = nb->prev;
			fb[3]++;
		}
		j = -1;
		min = fb[++j];
		int chk = j;
		while (++j < 4)
			if (fb[j] < min)
			{
				min = fb[j];
				chk = j;
			}
		j = -1;
		if (chk % 2)
			while (++j < fb[chk])
				rrx(ps->b);
		else
			while (++j < fb[chk])
				rx(ps->b);
		pa(ps);
		if (chk >= 2)
		{
			i--;
			nb = ps->b->head;
			fb[0] = 0, fb[1] = 0;
			while (nb && nb->val != max)
			{
				nb = nb->next;
				fb[0]++;
			}
			nb = ps->b->head;
			while (nb && nb->val != max)
			{
				nb = nb->prev;
				fb[1]++;
			}
			j = -1;
			if (fb[0] < fb[1])
			{
				while (++j < fb[0])
					rx(ps->b);
			}
			else
			{
				while (++j < fb[1])
					rrx(ps->b);
			}
			pa(ps);
			sx(ps->a);
		}

	}
	pa(ps);
}
