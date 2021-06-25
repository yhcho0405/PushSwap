/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youncho <youncho@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/18 13:02:28 by youncho           #+#    #+#             */
/*   Updated: 2021/06/25 18:45:51 by youncho          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	push(t_stack *stack, t_node *node)
{
	if (!stack || !node)
		return ;
	if (!stack->head)
	{
		node->prev = node;
		node->next = node;
		stack->head = node;
	}
	else
	{
		stack->head->prev->next = node;
		node->prev = stack->head->prev;
		stack->head->prev = node;
		node->next = stack->head;
		stack->head = node;
	}
	stack->size++;
}

t_node	*pop(t_stack *stack)
{
	t_node	*ret;

	if (!stack || !stack->size)
		return (NULL);
	ret = stack->head;
	if (stack->size == 1)
		stack->head = NULL;
	else
	{
		stack->head = stack->head->next;
		ret->prev->next = ret->next;
		ret->next->prev = ret->prev;
	}
	ret->prev = NULL;
	ret->next = NULL;
	stack->size--;
	return (ret);
}

void	append(t_ps *ps, t_stack *st, int val)
{
	t_node	*node;

	node = new_node(ps, val);
	if (!st)
		return ;
	if (!st->head)
	{
		node->prev = node;
		node->next = node;
		st->head = node;
	}
	else
	{
		st->head->prev->next = node;
		node->prev = st->head->prev;
		st->head->prev = node;
		node->next = st->head;
	}
	st->size++;
}

t_node	*new_node(t_ps *ps, int val)
{
	t_node	*new;

	new = (t_node *)malloc(sizeof(t_node));
	if (!new)
		error_exit(ps);
	new->val = val;
	new->prev = NULL;
	new->next = NULL;
	return (new);
}
