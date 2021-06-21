/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youncho <youncho@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/20 12:19:42 by youncho           #+#    #+#             */
/*   Updated: 2021/06/22 03:21:31 by youncho          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"




/*
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
*/

int get_start_val(t_ps *ps, int size)
{
	int		i;
	int		max;
	int		cnt;
	t_node	*n, *nn;

	i = -1;
	max = 0;
	nn = ps->a->head;
	while (++i < size - 1)
	{
		cnt = 0;
		n = nn->next;
		ps->tmp[0] = n->prev->val;
		ps->tmp[1] = n->prev->val;
		while (n != ps->a->head)
		{
			if (ps->tmp[0] < n->val && ++cnt)
				ps->tmp[0] = n->val;
			n = n->next;
		}
		if (max < cnt)
		{
			max = cnt;
			ps->tmp[2] = ps->tmp[1];
		}
		nn = nn->next;
	}
	return (ps->tmp[2]);
}

void	swap(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

t_bool	canpa(t_ps *ps, t_node *a, t_node *b)
{
	if (ps->size <= 1)
		return (false);
	if (a->val < a->prev->val)
		return (a->val > b->val || a->prev->val < b->val);
	if (a->val > b->val && b->val > a->prev->val)
		return (true);
	return (false);
}

int		max(int i, int j)
{
	if (i < j)
		return (j);
	return (i);
}

void	solve(int *arr, t_ps *ps, int size)
{
	t_stack *a = ps->a;
	t_stack *b = ps->b;
	int sv = get_start_val(ps, size);
	int i = -1;
	int j = 0;
	int chk = 0;
	int ws = 25;
	t_node *na;
	t_node *nb;
	int rna, rnb, as, bs, mina = 0, minb = 0, min, mina2 = 0, minb2 = 0;
	i = -1;

	while (++i < size)
	{
		if (a->head->val < arr[ps->size / 3])
		{
			pb(ps);
			rx(b);
		}
		else if (a->head->val > arr[ps->size / 3 * 2])
			pb(ps);
		else
			rx(a);
	}
	while (a->size > 0)
		pb(ps);
	while (b->size > 0)
	{
		i = -1;
		na = a->head;
		nb = b->head;
		int min1 = 0;
		as = a->size;
		bs = b->size;
		min1 = max(as, bs);
		while (++i < as)
		{
			j = -1;
			while (++j < bs)
			{
				if ( canpa(ps, na, nb) && min1 > max(i, j))
				{
					min1 = max(i, j);
					mina = i;
					minb = j;
				}
				nb = nb->next;
			}
			na = na->next;
		}

		na = a->head;
		nb = b->head;
		i = -1;
		int min2 = max(as, bs);
		while (++i < as)
		{
			j = -1;
			while (++j < bs)
			{
				if ( canpa(ps, na, nb) && min2 > max(i, j))
				{
					min2 = max(i, j);
					mina2 = i;
					minb2 = j;
				}
				nb = nb->prev;
			}
			na = na->prev;
		}

		na = a->head;
		nb = b->head;
		i = -1;
		int min3 = max(as, bs);
		int mina3 = 0, minb3 = 0;
		while (++i < as)
		{
			j = -1;
			while (++j < bs)
			{
				if ( canpa(ps, na, nb) && min3 > max(i, j))
				{
					min3 = max(i, j);
					mina3 = i;
					minb3 = j;
				}
				nb = nb->prev;
			}
			na = na->next;
		}

		na = a->head;
		nb = b->head;
		i = -1;
		int min4 = max(as, bs);
		int mina4 = 0, minb4 = 0;
		while (++i < as)
		{
			j = -1;
			while (++j < bs)
			{
				if ( canpa(ps, na, nb) && min4 > max(i, j))
				{
					min4 = max(i, j);
					mina4 = i;
					minb4 = j;
				}
				nb = nb->prev;
			}
			na = na->next;
		}

		int i = -1;
		if (ps->b->size > 0)
		{
			if ((min1 <= min2) && (min1 <= min3)
				&& (min1 <= min4) && (mina < minb))
			{
				while (++i < mina)
					rr(ps);
				while (i++ < minb)
					rx(b);
			}
			else if (min1 <= min2 && min1 <= min3
					&& min1 <= min4)
			{
				while (++i < minb)
					rr(ps);
				while (i++ < mina)
					rx(a);
			}

			else if (min2 <= min1 && min2 <= min3
				&& min2 <= min4 && mina2 < minb2)
			{
				while (++i < mina2)
					rrr(ps);
				while (i++ < minb2)
					rrx(b);
			}
			else if (min2 <= min1 && min2 <= min3
					&& min2 <=min4)
			{
				while (++i < minb2)
					rrr(ps);
				while (i++ < mina2)
					rrx(a);
			}

			else if (min3 <= min1 && min3 <= min2
				&& min3 <= min4)
			{
				while (++i < mina3)
					rx(a);
				i = -1;
				while (++i < minb3)
					rrx(b);
			}

			else if (min4 <= min1 && min4 <= min2
				&& min4 <= min3)
			{
				while (++i < mina3)
					rrx(a);
				i = -1;
				while (++i < minb3)
					rx(b);
			}

			pa(ps);
		}

	}


	na = a->head;
	nb = a->head;
	int maxn = 0, maxp = 0;
	while (a->head->val != arr[0])
	{
		i = -1;
		if (na->val == arr[0])
			while (++i < maxn)
				rx(a);
		else if (nb->val == arr[0])
			while (++i < maxp)
				rrx(a);
		na = na->next;
		maxn++;
		nb = na->prev;
		maxp++;
	}

}
// a b 중 원소 많은 쪽 top기준으로 이동 -> top? window size?
// window size 중 가장 가까운 것 기준?
// 실행 중 작은건 바로 뒤로 넘기기
// 예외가 있는가?
// 오름, 내림차순 정렬된 배열 테스트

//마지막과 마지막 - 1 원소의 위치에 따라 편차가 심함. 4200 ~ 5000 회 사이.

