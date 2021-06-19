/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youncho <youncho@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/15 21:44:14 by youncho           #+#    #+#             */
/*   Updated: 2021/06/19 09:30:59 by youncho          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
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
}	t_stack;

/*
**	utils.c
*/
void	push(t_stack *stack, t_node *node);
t_node	*pop(t_stack *stack);
void	append(t_stack *stack, t_node *node);
t_node	*new_node(int val);

/*
**	utils.c
*/
void	error_exit(void);
t_bool	check_int(const char *str);

#endif
