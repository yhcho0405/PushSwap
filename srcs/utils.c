/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youncho <youncho@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/19 08:49:22 by youncho           #+#    #+#             */
/*   Updated: 2021/06/20 04:18:44 by youncho          ###   ########.fr       */
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

void	test(t_stack *st)
{
	t_node *nd;
	int		i;

	nd = st->head;
	i = st->size;
	while (i--)
	{
		printf("node val: %d\n", nd->val);
		nd = nd->next;
	}
}
