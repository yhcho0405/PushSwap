/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youncho <youncho@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/19 08:49:22 by youncho           #+#    #+#             */
/*   Updated: 2021/06/20 11:02:08 by youncho          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	error_exit()
{
	ft_putstr_fd("Error\n", 1);
	exit(1);
}

int		get_int(const char *str)
{
	int			sign;
	uint64_t	ans;

	ans = 0;
	sign = 1;
	while ((9 <= *str && *str <= 13) || *str == ' ')
		str++;
	if ((*str == '-' || *str == '+') && *(str++) == '-')
		sign *= -1;
	if (ft_strlen(str) > 10)
		error_exit();
	while ('0' <= *str && *str <= '9')
		ans = ans * 10 + *(str++) - '0';
	if (*str || (int64_t)(ans * sign) < (int64_t)INT_MIN
		|| (int64_t)INT_MAX < (int64_t)(ans * sign))
		error_exit();
	return (ans * sign);
}

t_bool	check_sorted(t_stack *st)
{
	t_node	*n;
	int		tmp;

	n = st->head;
	if (!n)
		return (true);
	tmp = n->val;
	n = n->next;
	while (n != st->head)
	{
		if (tmp > n->val)
			return (false);
		tmp = n->val;
		n = n->next;
	}
	return (true);
}

void	arr_qsort(int *arr, int l, int r)
{
	int i;
	int j;
	int pivot;
	int tmp;

	i = l;
	j = r;
	pivot = arr[(l + r) / 2];
	while (i <= j)
	{
		while (arr[i] < pivot)
			i++;
		while (arr[j] > pivot)
			j--;
		if (i <= j)
		{
			tmp = arr[i];
			arr[i++] = arr[j];
			arr[j--] = tmp;
		}
	}
	if (l < j)
		arr_qsort(arr, l, j);
	if (i < r)
		arr_qsort(arr, i, r);
}

void	test(t_ps *ps)
{
	t_node *na;
	t_node *nb;
	int		ia;
	int		ib;

	na = ps->a->head;
	nb = ps->b->head;
	ia = ps->a->size;
	ib = ps->b->size;
	ft_printf("┌─────a─────┬─────b─────┐\n");
	while (ia > 0 || ib > 0)
	{
		if (ia > 0)
		{
			ft_printf("|%11d|", na->val);
			na = na->next;
		}
		else
			ft_printf("│           │");
		if (ib > 0)
		{
			ft_printf("%11d|\n", nb->val);
			nb = nb->next;
		}
		else
			ft_printf("           |\n");
		ia--;
		ib--;
	}
	ft_printf("└───────────┴───────────┘\n");
}
	/*test(ps);
	pb(ps);pb(ps);pb(ps);test(ps);
	pa(ps);test(ps);
	sx(ps->a);test(ps);
	sx(ps->b);test(ps);
	ss(ps);test(ps);
	rx(ps->a);rx(ps->a);test(ps);
	rx(ps->b);test(ps);
	rr(ps);test(ps);
	rrx(ps->a);test(ps);
	rrx(ps->b);test(ps);
	rrr(ps);test(ps);*/
