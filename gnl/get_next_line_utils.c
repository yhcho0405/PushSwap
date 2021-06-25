/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youncho <youncho@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/21 17:12:30 by youncho           #+#    #+#             */
/*   Updated: 2021/06/25 18:43:11 by youncho          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t	len;

	if (!str)
		return (FAIL);
	len = 0;
	while (str[len])
		len++;
	return (len);
}

int		set_line_size(char **line, size_t len)
{
	char	*tmp;
	size_t	i;

	if (!(tmp = malloc(BUFFER_SIZE + len + 1)))
		return (FAIL);
	i = -1;
	while (++i < len)
		tmp[i] = (*line)[i];
	tmp[i] = (char)0;
	free(*line);
	*line = tmp;
	return (SUCCESS);
}

t_storage	*get_new_node(int fd)
{
	t_storage *ret;

	if (!(ret = malloc(sizeof(t_storage))))
		return (FAIL);
	ret->fd = fd;
	ret->next = (t_storage *)0;
	ret->buff[0] = (char)0;
	return (ret);
}

t_storage	*get_current_node(int fd, t_storage *node)
{
	while (node->fd != fd)
	{
		if (!node->next)
			return (node->next = get_new_node(fd));
		node = node->next;
	}
	return (node);
}

int			deallocation(int fd, t_storage **head, int ret)
{
	t_storage	*prev;
	t_storage	*del;

	prev = *head;
	while (prev->next && prev->next->fd != fd)
		prev = prev->next;
	del = get_current_node(fd, *head);
	if ((*head)->fd == fd)
		*head = del->next;
	else
		prev->next = del->next;
	free(del);
	return (ret);
}
