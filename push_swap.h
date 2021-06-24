/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youncho <youncho@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/15 21:44:14 by youncho           #+#    #+#             */
/*   Updated: 2021/06/24 08:46:41 by youncho          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include "printf/ft_printf.h"
# include "gnl/get_next_line.h"
# include <limits.h>

# define O_SA 0
# define O_SB 1
# define O_SS 2
# define O_PA 3
# define O_PB 4
# define O_RA 5
# define O_RB 6
# define O_RR 7
# define O_RRA 8
# define O_RRB 9
# define O_RRR 10

typedef enum e_bool
{
	false,
	true
}	t_bool;

typedef struct s_node
{
	int				val;
	struct s_node	*prev;
	struct s_node	*next;
}	t_node;

typedef struct s_stack
{
	t_node	*head;
	size_t	size;
	char	name;
}	t_stack;

typedef struct s_ps
{
	int		*tmp;
	int 	*arr;
	int		size;
	int		dir;
	int		is_chk;
	int		min[4];
	int		move[8];
	t_stack	*a;
	t_stack	*b;
}	t_ps;

/*
**	push_swap.c
*/
void		push_swap(t_ps *ps);

/*
**	checker.c
*/
void		move_checker(t_ps *ps, int op);
void		checker(t_ps *ps);

/*
**	stack.c
*/
void		push(t_stack *stack, t_node *node);
t_node		*pop(t_stack *stack);
void		append(t_stack *stack, int val);
t_node		*new_node(int val);

/*
**	<operations>
**	operation_ps.c / operation_r.c
**
**	sa: swap a - swap the first 2 elements at the top of stack a.
**		Do nothing if there is only one or no elements). -> sx(t_stack *x)
**	sb: swap b - swap the first 2 elements at the top of stack b.
**		Do nothing if there is only one or no elements). -> sx(t_stack *x)
**	ss : sa and sb at the same time. -> ss(t_ps *ps)
**
**	pa: push a - take the first element at the top of b
**		and put it at the top of a. Do nothing if b is empty. -> pa(t_ps *ps)
**	pb: push b - take the first element at the top of a
**		and put it at the top of b. Do nothing if a is empty. -> pb(t_ps *ps)
**
**	ra: rotate a - shift up all elements of stack a by 1.
**		The first element becomes the last one. -> rx(t_stack *x)
**	rb: rotate b - shift up all elements of stack b by 1.
**		The first element becomes the last one. -> rx(t_stack *x)
**	rr: ra and rb at the same time. -> rr(t_ps *ps)
**
**	rra: reverse rotate a - shift down all elements of stack a by 1.
**		 The last element becomes the first one. -> rrx(t_stack *x)
**	rrb: reverse rotate b - shift down all elements of stack b by 1.
**		 The last element becomes the first one. -> rrx(t_stack *x)
**	rrr: rra and rrb at the same time. -> rrr(t_ps *ps)
*/
void		pa(t_ps *ps);
void		pb(t_ps *ps);
void		sx(t_stack *x);
void		ss(t_ps *ps);

void		rx(t_stack *x);
void		rr(t_ps *ps);
void		rrx(t_stack *x);
void		rrr(t_ps *ps);

/*
**	solve.c
*/
t_bool		is_corr(t_ps *ps, t_node *a, t_node *b);
int			calc_min(t_ps *ps, t_node *na, t_node *nb, int m);
void		move(t_ps *ps, int dir, t_stack	*s, int m);
void		align(t_ps *ps, t_node *n);
void		solve(t_ps *ps, t_stack *a, t_stack *b, int *min);

/*
**	utils.c
*/
void		error_exit(void);
int			get_int(const char *str);
t_bool		check_sorted(t_stack *st);
void		arr_qsort(int *arr, int l, int r);
void		parse_arg(t_stack *a, char **arg, int ac);
void		check_dup(t_stack *st);
void		test(t_ps *ps);

#endif
