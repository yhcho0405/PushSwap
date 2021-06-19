/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youncho <youncho@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/15 21:44:14 by youncho           #+#    #+#             */
/*   Updated: 2021/06/20 08:03:25 by youncho          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include "../printf/ft_printf.h"
# include <limits.h>
# include <stdio.h>

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
	t_stack	*a;
	t_stack	*b;
}	t_ps;

/*
**	push_swap.c
*/

/*
**	stack.c
*/
void		push(t_stack *stack, int val);
t_node		*pop(t_stack *stack);
void		append(t_stack *stack, int val);
t_node		*new_node(int val);

/*
**	utils.c
*/
void		error_exit(void);
int			get_int(const char *str);
void		test(t_ps *ps);

/*
**	operations
*/
void		pa(t_ps *ps);
void		pb(t_ps *ps);
void		sx(t_stack *x);
void		ss(t_ps *ps);
void		rx(t_stack *x);
void		rr(t_ps *ps);
void		rrx(t_stack *x);
void		rrr(t_ps *ps);

#endif
